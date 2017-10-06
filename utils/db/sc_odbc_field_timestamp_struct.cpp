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
#include "sc_odbc_field_timestamp_struct.hpp"

/**
 * @brief FieldTIMESTAMP_STRUCT::FieldTIMESTAMP_STRUCT
 */
FieldTIMESTAMP_STRUCT::FieldTIMESTAMP_STRUCT() { this->_target_type = SQL_C_TIMESTAMP; }

/**
 * @brief FieldTIMESTAMP_STRUCT::~FieldTIMESTAMP_STRUCT
 */
FieldTIMESTAMP_STRUCT::~FieldTIMESTAMP_STRUCT() {}

/**
 * @brief FieldTIMESTAMP_STRUCT::to_string
 * @return
 */
const char* FieldTIMESTAMP_STRUCT::to_string() {

    TIMESTAMP_STRUCT this_F_DTA_HRA_INCLUSAO = this->get();
    return (SC::TimestampUtils::to_str_dt(this_F_DTA_HRA_INCLUSAO));

}
