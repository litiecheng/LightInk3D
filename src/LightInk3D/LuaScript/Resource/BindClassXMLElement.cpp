

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
#include "Resource/XMLElement.h"
#include "Resource/XMLFile.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_XMLElement(LuaModule & lm)
	{
		lm
		[
			LuaRegister<XPathQuery, void ()>(lm.state(), "XPathQuery")
				.def(&XPathQuery::Bind, "Bind")
				.def(static_cast<bool(XPathQuery::*)(const String&, bool)>(&XPathQuery::SetVariable), "SetVariableSB")
				.def(static_cast<bool(XPathQuery::*)(const String&, float)>(&XPathQuery::SetVariable), "SetVariableSF")
				.def(static_cast<bool(XPathQuery::*)(const String&, const String&)>(&XPathQuery::SetVariable), "SetVariableSS")
				.def(static_cast<bool(XPathQuery::*)(const String&, const XPathResultSet&)>(&XPathQuery::SetVariable), "SetVariableSX")
				.def(&XPathQuery::SetQuery, "SetQuery")
				.def(&XPathQuery::Clear, "Clear")
				.def(&XPathQuery::EvaluateToBool, "EvaluateToBool")
				.def(&XPathQuery::EvaluateToFloat, "EvaluateToFloat")
				.def(&XPathQuery::EvaluateToString, "EvaluateToString")
				.def(&XPathQuery::Evaluate, "Evaluate")
				.def(&XPathQuery::GetQuery, "GetQuery")
			<=
			LuaRegister<XPathResultSet, void ()>(lm.state(), "XPathResultSet")
				.def(&XPathResultSet::operator[], "GetValue")
				.def(&XPathResultSet::FirstResult, "FirstResult")
				.def(&XPathResultSet::Size, "Size")
				.def(&XPathResultSet::Empty, "Empty")
			<=
			LuaRegister<XMLElement, void ()>(lm.state(), "XMLElement")
				.def(static_cast<XMLElement(XMLElement::*)(const String&)>(&XMLElement::CreateChild), "CreateChild")
				.def(static_cast<bool(XMLElement::*)(const XMLElement&)>(&XMLElement::RemoveChild), "RemoveChildX")
				.def(static_cast<bool(XMLElement::*)(const String&)>(&XMLElement::RemoveChild), "RemoveChildS")
				.def(static_cast<bool(XMLElement::*)(const String&)>(&XMLElement::RemoveChildren), "RemoveChildren")
				.def(static_cast<bool(XMLElement::*)(const String&)>(&XMLElement::RemoveAttribute), "RemoveAttribute")
				.def(&XMLElement::SelectSinglePrepared, "SelectSinglePrepared")
				.def(&XMLElement::SelectPrepared, "SelectPrepared")
				.def(static_cast<bool(XMLElement::*)(const String&)>(&XMLElement::SetValue), "SetValue")
				.def(static_cast<bool(XMLElement::*)(const String&, const String&)>(&XMLElement::SetAttribute), "SetAttributeSS")
				.def(static_cast<bool(XMLElement::*)(const String&)>(&XMLElement::SetAttribute), "SetAttributeS")
				.def(&XMLElement::SetBool, "SetBool")
				.def(&XMLElement::SetBoundingBox, "SetBoundingBox")
				.def(&XMLElement::SetColor, "SetColor")
				.def(&XMLElement::SetFloat, "SetFloat")
				.def(&XMLElement::SetDouble, "SetDouble")
				.def(&XMLElement::SetUInt, "SetUInt")
				.def(&XMLElement::SetInt, "SetInt")
				.def(&XMLElement::SetIntRect, "SetIntRect")
				.def(&XMLElement::SetIntVector2, "SetIntVector2")
				.def(&XMLElement::SetRect, "SetRect")
				.def(&XMLElement::SetQuaternion, "SetQuaternion")
				.def(&XMLElement::SetString, "SetString")
				.def(&XMLElement::SetVariant, "SetVariant")
				.def(&XMLElement::SetVariantValue, "SetVariantValue")
				.def(&XMLElement::SetResourceRef, "SetResourceRef")
				.def(&XMLElement::SetResourceRefList, "SetResourceRefList")
				.def(&XMLElement::SetVariantVector, "SetVariantVector")
				.def(&XMLElement::SetStringVector, "SetStringVector")
				.def(&XMLElement::SetVariantMap, "SetVariantMap")
				.def(&XMLElement::SetVector2, "SetVector2")
				.def(&XMLElement::SetVector3, "SetVector3")
				.def(&XMLElement::SetVector4, "SetVector4")
				.def(&XMLElement::SetVectorVariant, "SetVectorVariant")
				.def(&XMLElement::SetMatrix3, "SetMatrix3")
				.def(&XMLElement::SetMatrix3x4, "SetMatrix3x4")
				.def(&XMLElement::SetMatrix4, "SetMatrix4")
				.def(&XMLElement::IsNull, "IsNull")
				.def(&XMLElement::NotNull, "NotNull")
				.def(&XMLElement::GetName, "GetName")
				.def(static_cast<bool(XMLElement::*)(const String&) const>(&XMLElement::HasChild), "HasChild")
				.def(static_cast<XMLElement(XMLElement::*)(const String&)const>(&XMLElement::GetChild), "GetChild")
				.def(static_cast<XMLElement(XMLElement::*)(const String&)const>(&XMLElement::GetNext), "GetNext")
				.def(&XMLElement::GetParent, "GetParent")
				.def(&XMLElement::GetNumAttributes, "GetNumAttributes")
				.def(static_cast<bool(XMLElement::*)(const String&) const>(&XMLElement::HasAttribute), "HasAttribute")
				.def(&XMLElement::GetValue, "GetValue")
				.def(static_cast<String(XMLElement::*)(const String&)const>(&XMLElement::GetAttribute), "GetAttribute")
				.def(static_cast<String(XMLElement::*)(const String&) const>(&XMLElement::GetAttributeLower), "GetAttributeLower")
				.def(static_cast<String(XMLElement::*)(const String&) const>(&XMLElement::GetAttributeUpper), "GetAttributeUpper")
				.def(&XMLElement::GetAttributeNames, "GetAttributeNames")
				.def(&XMLElement::GetBool, "GetBool")
				.def(&XMLElement::GetBoundingBox, "GetBoundingBox")
				.def(&XMLElement::GetColor, "GetColor")
				.def(&XMLElement::GetFloat, "GetFloat")
				.def(&XMLElement::GetDouble, "GetDouble")
				.def(&XMLElement::GetUInt, "GetUInt")
				.def(&XMLElement::GetInt, "GetInt")
				.def(&XMLElement::GetIntRect, "GetIntRect")
				.def(&XMLElement::GetIntVector2, "GetIntVector2")
				.def(&XMLElement::GetRect, "GetRect")
				.def(&XMLElement::GetQuaternion, "GetQuaternion")
				.def(&XMLElement::GetVariant, "GetVariant")
				.def(&XMLElement::GetVariantValue, "GetVariantValue")
				.def(&XMLElement::GetResourceRef, "GetResourceRef")
				.def(&XMLElement::GetResourceRefList, "GetResourceRefList")
				.def(&XMLElement::GetVariantVector, "GetVariantVector")
				.def(&XMLElement::GetStringVector, "GetStringVector")
				.def(&XMLElement::GetVariantMap, "GetVariantMap")
				.def(&XMLElement::GetVector2, "GetVector2")
				.def(&XMLElement::GetVector3, "GetVector3")
				.def(&XMLElement::GetVector4, "GetVector4")
				.def(&XMLElement::GetVector, "GetVector")
				.def(&XMLElement::GetVectorVariant, "GetVectorVariant")
				.def(&XMLElement::GetMatrix3, "GetMatrix3")
				.def(&XMLElement::GetMatrix3x4, "GetMatrix3x4")
				.def(&XMLElement::GetMatrix4, "GetMatrix4")
				.def(&XMLElement::GetFile, "GetFile")
				.def(&XMLElement::EMPTY, "EMPTY")
		];
	}
}
