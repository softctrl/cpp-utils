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
#ifndef FIELDTIMESTAMP_STRUCT_H
#define FIELDTIMESTAMP_STRUCT_H

#include "src/utils/sc_timestamp_utils.hpp"
#include <src/utils/db/sc_odbc_field_sql.hpp>

/**
 * Set the date value
 */
#define _sinn_dt(__obj, __method, __field) if (__field.getDataLength()>0) __obj->__method(__field.to_li_dt());

/**
 * Set the timestamp value
 */
#define _sinn_ts(__obj, __method, __field) if (__field.getDataLength()>0) __obj->__method(__field.to_li_ts());

class FieldTIMESTAMP_STRUCT : public SCODBCFieldSQL<TIMESTAMP_STRUCT> {

    public:
        FieldTIMESTAMP_STRUCT();

        ~FieldTIMESTAMP_STRUCT();

        TIMESTAMP_STRUCT _New() override {
            return this->get();
        }


        const char* to_string() override;

        /**
         * @brief to_li_ts
         * @return
         */
        long int to_li_ts() {
            TIMESTAMP_STRUCT this_F_DTA_HRA_INCLUSAO = this->get();
            return SC::TimestampUtils::to_li_ts(&this_F_DTA_HRA_INCLUSAO);
        }

        /**
         * @brief to_li_dt
         * @return
         */
        long int to_li_dt() {
            TIMESTAMP_STRUCT this_F_DTA_HRA_INCLUSAO = this->get();
            return SC::TimestampUtils::to_li_dt(&this_F_DTA_HRA_INCLUSAO);
        }

};

#endif // FIELDTIMESTAMP_STRUCT_H
