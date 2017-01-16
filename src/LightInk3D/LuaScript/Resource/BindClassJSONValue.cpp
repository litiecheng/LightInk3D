

/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "Precompiled.h"
#include "Core/Context.h"
#include "Core/Variant.h"
#include "Resource/JSONValue.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static void JSONValueSetBool(JSONValue& self, bool value)
	{
		self = value;
	}

	static void JSONValueSetInt(JSONValue& self, int value)
	{
		self = value;
	}

	static void JSONValueSetUInt(JSONValue& self, unsigned value)
	{
		self = value;
	}

	static void JSONValueSetFloat(JSONValue& self, float value)
	{
		self = value;
	}

	static void JSONValueSetDouble(JSONValue& self, double value)
	{
		self = value;
	}

	static void JSONValueSetString(JSONValue& self, const char* value)
	{
		self = value;
	}

	static void JSONValueSetArray(JSONValue& self, const JSONArray& value)
	{
		self = value;
	}

	static void JSONValueSetObject(JSONValue& self, const JSONObject& value)
	{
		self = value;
	}
	void bind_class_JSONFile(LuaModule & lm)
	{
		lm
		[
			LuaRegister<JSONValue, void ()>(lm.state(), "JSONValue")
				.def(&JSONValue::GetValueType, "GetValueType")
				.def(&JSONValue::GetNumberType, "GetNumberType")
				.def(&JSONValue::IsNull, "IsNull")
				.def(&JSONValue::IsBool, "IsBool")
				.def(&JSONValue::IsNumber, "IsNumber")
				.def(&JSONValue::IsString, "IsString")
				.def(&JSONValue::IsArray, "IsArray")
				.def(&JSONValue::IsObject, "IsObject")
				.def(JSONValueSetBool, "SetBool")
				.def(JSONValueSetInt, "SetInt")
				.def(JSONValueSetUInt, "SetUInt")
				.def(JSONValueSetFloat, "SetFloat")
				.def(JSONValueSetDouble, "SetDouble")
				.def(JSONValueSetString, "SetString")
				.def(JSONValueSetArray, "SetArray")
				.def(JSONValueSetObject, "SetObject")
				.def(&JSONValue::GetBool, "GetBool")
				.def(&JSONValue::GetInt, "GetInt")
				.def(&JSONValue::GetUInt, "GetUInt")
				.def(&JSONValue::GetFloat, "GetFloat")
				.def(&JSONValue::GetDouble, "GetDouble")
				.def(&JSONValue::GetCString, "GetCString")
				.def(&JSONValue::GetArray, "GetArray")
				.def(&JSONValue::GetObject, "GetObject")
				.def(static_cast<const JSONValue&(JSONValue::*)(unsigned int) const>(&JSONValue::operator[]), "GetValueU")
				.def(static_cast<const JSONValue&(JSONValue::*)(const String&) const>(&JSONValue::operator[]), "GetValueS")
				.def(static_cast<JSONValue&(JSONValue::*)(unsigned int)>(&JSONValue::operator[]), "SetValueU")
				.def(static_cast<JSONValue&(JSONValue::*)(const String&)>(&JSONValue::operator[]), "SetValueS")
				.def(&JSONValue::Push, "Push")
				.def(&JSONValue::Pop, "Pop")
				.def(&JSONValue::Insert, "Insert")
				.def(static_cast<void(JSONValue::*)(unsigned int, unsigned int)>(&JSONValue::Erase), "EraseUU")
				.def(static_cast<bool(JSONValue::*)(const String&)>(&JSONValue::Erase), "EraseS")
				.def(&JSONValue::Resize, "Resize")
				.def(&JSONValue::Size, "Size")
				.def(&JSONValue::Set, "Set")
				.def(&JSONValue::Get, "Get")
				.def(&JSONValue::Contains, "Contains")
				.def(&JSONValue::Clear, "Clear")
		];
	}
}
