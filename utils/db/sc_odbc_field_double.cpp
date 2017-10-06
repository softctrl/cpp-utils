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
#include "sc_odbc_field_double.hpp"
#include "src/utils/sc_string_utils.hpp"

/**
 * @brief FieldDouble::FieldDouble
 */
FieldDOUBLE::FieldDOUBLE() { this->_target_type = SQL_C_DOUBLE; }

/**
 * @brief FieldDouble::~FieldDouble
 */
FieldDOUBLE::~FieldDOUBLE() {}

/**
 * @brief FieldDOUBLE::to_string
 * @return
 */
const char* FieldDOUBLE::to_string() {
    return SC::StringUtils::to_string(this->get(), 7);
}
