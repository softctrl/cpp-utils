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
#ifndef SCSTRINGUTILS_H
#define SCSTRINGUTILS_H

#include <functional>
#include <cstring>
#include <sqltypes.h>
#include <iomanip>
#include <sstream>

namespace SC {

const std::hash<const char*> _STD_HASH_C_CHAR;
const std::hash<std::string> _STD_HASH_STD_STRING;

class StringUtils {

    public:

        /**
         * @brief hash
         * @param _value
         * @return
         */
        inline static int hash_(const char* &__value) {

            return _STD_HASH_C_CHAR(__value);
        }

        /**
         * One of the best Hash algoritms that i had found.
         * Based on: http://www.cse.yorku.ca/~oz/hash.html
         *
         * @brief c_hash
         * @param str
         * @return
         */
        inline unsigned long c_hash(unsigned char *&str) {
            unsigned long hash = 5381;
            int c;
            while ((c = *str++)) hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
            return hash;
        }



        /**
         * @brief hash
         * @param _value
         * @return
         */
        inline static int hash(std::string __value) {
            return _STD_HASH_STD_STRING(__value);
        }

        /**
         * @brief is_null_or_empty
         * @param _value
         * @return
         */
        inline static bool is_null_or_empty(const char* __value) {
            return (__value == NULL || __value[0] == 0);
        }

        /**
         * @brief _strlen
         * @param __value
         * @return
         */
        inline static int _strlen(const char* __value) {
            if (is_null_or_empty(__value))
                return 0;
            else
                return strlen(__value);
        }

        /**
         * @brief rtrim
         * @param __string
         * @param __junk
         * @return
         */
        inline static char* rtrim(char* __string, char __junk) {

            char* original = __string + strlen(__string);
            while(*--original == __junk);
                *(original + 1) = '\0';
            return __string;
        }

        /**
         * @brief _trim
         * @param _value
         */
        inline static void _trim(char _value[]) {
            const unsigned int len = strlen(_value);

            unsigned int skip, scrape;
            for (skip = 0; skip < len; skip++) if (! isspace(_value[skip])) break;
            for (scrape = len; scrape > skip; scrape--) if (! isspace(_value[scrape - 1] )) break;

            // Cap off at the scrap point
            if (scrape != len) _value[scrape] = 0;

            if (skip) {
                // Copy the chars down
                unsigned int index = 0;
                while (_value[skip]) _value[index++] = _value[skip++];
                _value[index] = 0;
            }

        }

        /**
         * @brief _strcpy
         * @param __dest
         * @param __src
         */
        inline static void _strcpy(const char * &__dest, const char * &__src) {

            char *_aux = new char[strlen(__src)+1];
            strcpy(_aux, __src);
            _trim(_aux);
            __dest = _aux;

        }

        /**
         * @brief _strncpy
         * @param __dest
         * @param __src
         * @param __length
         */
        inline static void _strncpy(const char * &__dest, char * &__src, SQLLEN __length ) {

            char *_aux = new char[__length+1];
            strncpy(_aux, __src, __length);
            _trim(_aux);
            __dest = _aux;

        }

        inline static bool _equals(const char * __char1, const char * __char2) {

            if (is_null_or_empty(__char1) || is_null_or_empty(__char2)) return false;
            return (strcmp(__char1, __char2) == 0);

        }

        /**
         * @brief to_string
         * @param __value
         * @param __precision
         * @return
         */
        inline static const char* to_string(double __value, int __precision) {

            std::stringstream _aux;
            _aux << std::fixed << std::setprecision(__precision) << __value;
            return _aux.str().c_str();

        }

};

}

#endif // SCSTRINGUTILS_H
