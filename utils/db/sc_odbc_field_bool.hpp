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
#ifndef FIELDSQLBOOL_H
#define FIELDSQLBOOL_H

#include "src/utils/db/sc_odbc_field_sql.hpp"

class FieldSQLBOOL : public SCODBCFieldSQL<bool> {

    public:
        FieldSQLBOOL();
        ~FieldSQLBOOL();

        /**
         * @brief _New
         * @return
         */
        bool _New() override {
            return this->_field;
        }

        /**
         * @brief to_string
         * @return
         */
        const char* to_string() override;


};

#endif // FIELDSQLBOOL_H
