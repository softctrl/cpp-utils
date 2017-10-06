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
#include "sc_odbc_field_numeric.hpp"

/**
 * @brief FieldNUMERIC::FieldNUMERIC
 */
FieldNUMERIC::FieldNUMERIC() { this->_target_type = SQL_C_NUMERIC; }

/**
 * @brief FieldNUMERIC::~FieldNUMERIC
 */
FieldNUMERIC::~FieldNUMERIC() {}

/**
 * @brief FieldNUMERIC::to_string
 * @return
 */
const char* FieldNUMERIC::to_string() {
    return NULL;
}

