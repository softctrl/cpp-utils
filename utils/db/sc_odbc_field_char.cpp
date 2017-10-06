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
#include <iostream>

#include "sc_odbc_field_char.hpp"
#include "src/utils/sc_string_utils.hpp"

/**
 * @brief FieldSQLCHAR::FieldSQLCHAR
 */
FieldSQLCHAR::FieldSQLCHAR() { this->_target_type = SQL_C_CHAR; }

/**
 * @brief FieldSQLCHAR::~FieldSQLCHAR
 */
FieldSQLCHAR::~FieldSQLCHAR() {}

/**
 * @brief FieldSQLCHAR::to_string
 * @return
 */
const char* FieldSQLCHAR::to_string() {

    std::cout << this->get() << std::endl;

    if (this->_data_length > 0 && this->get() != NULL) {
        char* _res = new char[this->_data_length/*+1*/];
        strncpy(_res, this->get(), this->_data_length/*+1*/);
        return _res;
    } else {
        return NULL;
    }

}

