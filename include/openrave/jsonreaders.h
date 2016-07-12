// -*- coding: utf-8 -*-
// Copyright (C) 2006-2013 Rosen Diankov <rosen.diankov@gmail.com>
//
// This file is part of OpenRAVE.
// OpenRAVE is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/** \file jsonreaders.h
    \brief classes for reading common OpenRAVE objects from JSON

    This file is optional and not automatically included with openrave.h
 */
#ifndef OPENRAVE_JSONREADERS_H
#define OPENRAVE_JSONREADERS_H

#include <openrave/openrave.h>

#define RAPIDJSON_HAS_STDSTRING 1
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

namespace OpenRAVE {
namespace jsonreaders {

class OPENRAVE_API BufferJSONWriter : public BaseJSONWriter
{
public:
    BufferJSONWriter();
    const std::string& GetFormat() const;
    virtual const char* SerializeJSON();

    virtual void Null();
    virtual void Bool(bool value);
    virtual void Int(int value);
    virtual void Double(double value);
    virtual void String(const std::string& value);
    virtual void String(const char* value);

    virtual void StartArray();
    virtual void EndArray();
    virtual void StartObject();
    virtual void EndObject();

private:
    rapidjson::StringBuffer _buffer;
    rapidjson::Writer<rapidjson::StringBuffer> _writer;
};

typedef boost::shared_ptr<BufferJSONWriter> BufferJSONWriterPtr;

} // jsonreaders
} // OpenRAVE

#endif