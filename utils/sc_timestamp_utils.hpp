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
#ifndef TIMESTAMPUTILS_H
#define TIMESTAMPUTILS_H

#include <sqltypes.h>
#include <cstring>
#include <sstream>
#include <string>
#include <stdio.h>
#include "src/utils/rapidjson/writer.h"

namespace SC {

class TimestampUtils {

    public:

        /**
         * Cast to char* timestamp.
         * @brief to_str
         * @param __date
         * @return
         */
        inline static const char* to_str(TIMESTAMP_STRUCT* __date) {

            //[2003-07-09 15:8:35.000]
            char* _res = 0;
            sprintf(_res, "%04d-%02d-%02d %02d:%02d:%02d.%03d",
                    __date->year,
                    __date->month,
                    __date->day,
                    __date->hour,
                    __date->minute,
                    __date->second,
                    __date->fraction);
            return _res;

        }

        /**
         * @brief to_str_dt
         * @param __date
         * @return
         */
        inline static const char* to_str_dt(TIMESTAMP_STRUCT &__date) {

            //[2003-07-09 15:8:35]
            char* _res = /*(char*)malloc(1)*/new char[0];
            sprintf(_res, "%04d-%02d-%02d %02d:%02d:%02d",
                    __date.year,
                    __date.month,
                    __date.day,
                    __date.hour,
                    __date.minute,
                    __date.second);
            return _res;

        }

        /**
         * Uggly but i need it.
         * @brief to_li_ts
         * @param __date
         * @return
         */
        inline static long int to_li_ts(TIMESTAMP_STRUCT* __date) {

            long int _data = __date->year * 100;
            _data += __date->month;
            _data *= 100;
            _data += __date->day;
            _data *= 100;
            _data += __date->hour;
            _data *= 100;
            _data += __date->minute;
            _data *= 100;
            _data += __date->second;
            return _data;

        }

        /**
         * Uggly but i need it too.
         * @brief to_li_dt
         * @param __date
         * @return
         */
        inline static long int to_li_dt(TIMESTAMP_STRUCT* __date) {

            long int _data = __date->year * 100;
            _data += __date->month;
            _data *= 100;
            _data += __date->day;
            return _data;

        }

        /**
         * @brief to_str_t
         * @param __date
         * @return
         */
        inline static const char* to_str_t(TIMESTAMP_STRUCT* __date) {

            //[15:8:35.000000]
            char* _res = 0;
            sprintf(_res, "%02d:%02d:%02d.%06d",
                    __date->hour,
                    __date->minute,
                    __date->second,
                    __date->fraction);
            return _res;

        }

        /**
         * @brief to_str_d
         * @param __date
         * @return
         */
        inline static const char* to_str_d(TIMESTAMP_STRUCT* __date) {

            //[2003-07-09]
            char* _res = 0;
            sprintf(_res, "%04d-%02d-%02d",
                    __date->year,
                    __date->month,
                    __date->day);
            return _res;

        }

};

}

#endif // TIMESTAMPUTILS_H
