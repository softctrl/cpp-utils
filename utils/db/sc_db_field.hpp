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
#ifndef SCDBFIELD_H
#define SCDBFIELD_H

#include <stdlib.h>

template<typename T>
class SCDbField {

    public:

        T get() const { return this->_value; }
        virtual inline void set(T &__value) { this->_value = __value; }
        virtual inline const char* field_mapping() = 0;
        virtual inline const char* to_string() = 0;
        virtual inline bool is_valid() = 0;

    protected:
        T _value;

};

#endif // SCDBFIELD_H
