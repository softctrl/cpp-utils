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
#ifndef FIELDSQLCHAR_H
#define FIELDSQLCHAR_H

#include "src/utils/db/sc_odbc_field_sql.hpp"

class FieldSQLCHAR : public SCODBCFieldSQL<char*> {

    public:
        FieldSQLCHAR();
        ~FieldSQLCHAR();

        char* _New() override {
            return new char[this->_column_length];
        }

        inline void _SQLBindCol(SQLHSTMT StatementHandle) override {

            SQLBindCol(StatementHandle,
                       this->_column_number ,
                       this->_target_type,
                       this->get(),
                       this->_column_length+1,
                       &this->_data_length);

        }


        const char* to_string() override;

};

#endif // FIELDSQLCHAR_H
