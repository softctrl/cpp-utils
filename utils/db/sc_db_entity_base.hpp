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
#ifndef SCDBENTITYBASE_H
#define SCDBENTITYBASE_H

#include <vector>
#include "src/utils/rapidjson/writer.h"
#include "src/utils/rapidjson/stringbuffer.h"
#include "src/utils/sc_string_utils.hpp"
#include "src/utils/log/sc_logger.hpp"

#define _TAG_SCDBEntityBase_ "SCDBEntityBase"

class SCDBEntityBase {

    public:

        static const char* F_ID;

        SCDBEntityBase();
        virtual ~SCDBEntityBase();


        /**
         * @brief to_json
         * @return
         */
        virtual inline const char* to_json() {

            rapidjson::StringBuffer _sb;
            rapidjson::Writer<rapidjson::StringBuffer> _writer(_sb);
            _writer.StartObject();
            this->Serialize(_writer);
            _writer.EndObject();

            return _sb.GetString();

        }

        /**
         * @brief write_to_json
         */
        virtual inline void write_to_json(FILE*) { _i(_TAG_SCDBEntityBase_, "Not implemented yet."); }

        /**
         * @brief get_mapping
         * @return
         */
        virtual inline const char* get_mapping() { _i(_TAG_SCDBEntityBase_, "Not implemented yet."); return NULL; }

        /**
         * @brief Serialize
         */
        void Serialize(rapidjson::Writer<rapidjson::StringBuffer>& __writer) const {
            if (_id) {
                __writer.Key(SCDBEntityBase::F_ID);
                __writer.Int(_id);
            }
        }

        /**
         * @brief getId
         * @return
         */
        virtual inline int getId() { return this->_id; }

        /**
         * @brief hash_code
         * @return
         */
        virtual int hash_code() { return 0; }

    protected:
        int _id = 0;


};

#endif // SCDBENTITYBASE_H
