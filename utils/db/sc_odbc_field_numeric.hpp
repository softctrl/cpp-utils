/*
 *
 * Author:
 *  Carlos Timoshenko
 *  carlostimoshenkorodrigueslopes@gmail.com
 *
 *  https://github.com/softctrl
 *
 * This project is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */
#ifndef FIELDNUMERIC_H
#define FIELDNUMERIC_H

#include "src/utils/db/sc_odbc_field_sql.hpp"
#include "src/utils/log/sc_logger.hpp"

#define SQL_MAX_NUMERIC_IDX		15
#define _TAG_FieldNUMERIC_ "FieldNUMERIC"

class FieldNUMERIC : public SCODBCFieldSQL<SQL_NUMERIC_STRUCT> {

    public:
        FieldNUMERIC();
        ~FieldNUMERIC();

        SQL_NUMERIC_STRUCT _New() override {
            return this->get();
        }

        inline void _SQLBindCol(SQLHSTMT StatementHandle/*, SQLUSMALLINT ColumnNumber*/) override {

            SQLBindCol(StatementHandle,
                       this->_column_number ,
                       this->_target_type,
                       &this->_field,
                       this->_column_length+1,
                       &this->_data_length);
            // Based on: <<https://support.microsoft.com/en-us/kb/181254>>
            /* Modify the fields in the implicit application parameter descriptor */
            this->_field.precision = 15;
            this->_field.scale = 7;


            SQLRETURN ret = 0;
            if (!SQL_SUCCEEDED(ret = SQLGetStmtAttr(StatementHandle, SQL_ATTR_APP_ROW_DESC, &_SQL_H_DESC, 0, NULL))) {
                _e_d(_TAG_FieldNUMERIC_, "Error", ret);
            }
            if (!SQL_SUCCEEDED(SQLSetDescField(_SQL_H_DESC, this->_column_number, SQL_DESC_TYPE, (SQLPOINTER) SQL_C_NUMERIC, 0))) {
                _e_d(_TAG_FieldNUMERIC_, "Error", ret);
            }
            if (!SQL_SUCCEEDED(SQLSetDescField(_SQL_H_DESC, this->_column_number, SQL_DESC_PRECISION, (SQLPOINTER) 22, 0))) {
                _e_d(_TAG_FieldNUMERIC_, "Error", ret);
            }
            if (!SQL_SUCCEEDED(SQLSetDescField(_SQL_H_DESC, this->_column_number, SQL_DESC_SCALE, (SQLPOINTER) 5, 0))) {
                _e_d(_TAG_FieldNUMERIC_, "Error", ret);
            }
            if (!SQL_SUCCEEDED(SQLSetDescField(_SQL_H_DESC, this->_column_number, SQL_DESC_DATA_PTR, (SQLPOINTER) &this->_field, sizeof(this->_field)))) {
                _e_d(_TAG_FieldNUMERIC_, "Error", ret);
            }

            memset(this->_field.val, 0, SQL_MAX_NUMERIC_LEN);

        }


        const char* to_string() override;

        long getValue() {

            long /*val=0,*/value=0;
            int i=1, last=1, current;
            int a=0, b=0;

            for(i=0; i<=SQL_MAX_NUMERIC_IDX; i++) {

                current = (int) this->get().val[i];
                a= current % 16; //Obtain LSD
                b= current / 16; //Obtain MSD

                value += last* a;
                last = last * 16;
                value += last* b;
                last = last * 16;

            }
            return value;

        }

    private:
        SQLHDESC   _SQL_H_DESC = NULL;

};

#endif // FIELDNUMERIC_H
