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
#ifndef SCDBFIELDSQL_H
#define SCDBFIELDSQL_H

#include <sqltypes.h>
#include <sqlext.h>
#include <stddef.h>
#include <sql.h>
#include <cstring>
#include <string>

/**
 * We can use this macro to simplify our code:
 */
#define _sinn(__obj, __method, __field) if (__field.getDataLength()>0) __obj->__method(__field.get());

template<typename T>
class SCODBCFieldSQL {

    public:
        /**
         * @brief getField
         * @return
         */
        inline T get() {
            return this->_field;
        }

        /**
         * @brief _New
         * @return
         */
        virtual T _New() = 0;

        /**
         * @brief _Setup
         * @param __target_type
         * @param __column_index
         * @param __column_length
         */
        inline void _Setup(SQLSMALLINT __target_type, SQLUSMALLINT __column_index, unsigned int __column_length) {
            this->_target_type   = __target_type;
            this->_column_number = __column_index;
            this->_column_length = __column_length;
            this->_field = _New();
        }

        /**
         * @brief _Setup
         * @param __column_index
         * @param __column_length
         */
        inline void _Setup(SQLUSMALLINT __column_index, unsigned int __column_length) {
            this->_column_number = __column_index;
            this->_column_length = __column_length;
            this->_field = _New();
        }

        /**
         * @brief _SQLBindCol
         * @param StatementHandle
         */
        virtual inline void _SQLBindCol(SQLHSTMT StatementHandle) {

            SQLBindCol(StatementHandle,
                       this->_column_number ,
                       this->_target_type,
                       &this->_field,
                       this->_column_length+1,
                       &this->_data_length);

        }


        /**
         * @brief to_string
         * @return
         */
        virtual const char* to_string() = 0;

        /**
         * @brief getDataLength
         * @return
         */
        inline SQLLEN getDataLength() {
            return this->_data_length;
        }

    protected:
        SQLLEN _data_length;
        unsigned int _column_length;
        SQLSMALLINT _target_type;
        SQLUSMALLINT _column_number;
        T _field;

};

#endif // SCDBFIELDSQL_H
