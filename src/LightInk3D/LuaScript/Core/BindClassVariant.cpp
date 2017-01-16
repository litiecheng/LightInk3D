

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

#include "Core/Variant.h"
#include "IO/VectorBuffer.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{

	static Variant IntToVariant(int value)
	{
		return Variant(value);
	}

	static Variant UIntToVariant(unsigned value)
	{
		return Variant(value);
	}

	static Variant StringHashToVariant(const StringHash& value)
	{
		return Variant(value);
	}

	static Variant BoolToVariant(bool value)
	{
		return Variant(value);
	}

	static Variant FloatToVariant(float value)
	{
		return Variant(value);
	}

	static Variant DoubleToVariant(double value)
	{
		return Variant(value);
	}

	static Variant Vector2ToVariant2(float x, float y)
	{
		return Variant(Vector2(x, y));
	}

	static Variant Vector2ToVariant(const Vector2& value)
	{
		return Variant(value);
	}

	static Variant Vector3ToVariant3(float x, float y, float z)
	{
		return Variant(Vector3(x, y, z));
	}

	static Variant Vector3ToVariant(const Vector3& value)
	{
		return Variant(value);
	}

	static Variant Vector4ToVariant4(float x, float y, float z, float w)
	{
		return Variant(Vector4(x, y, z, w));
	}

	static Variant Vector4ToVariant(const Vector4& value)
	{
		return Variant(value);
	}

	static Variant QuaternionToVariant4(float w, float x, float y, float z)
	{
		return Variant(Quaternion(w, x, y, z));
	}

	static Variant QuaternionToVariant(const Quaternion& value)
	{
		return Variant(value);
	}

	static Variant ColorToVariant3(float r, float g, float b)
	{
		return Variant(Color(r, g, b));
	}

	static Variant ColorToVariant4(float r, float g, float b, float a)
	{
		return Variant(Color(r, g, b, a));
	}

	static Variant ColorToVariant(const Color& value)
	{
		return Variant(value);
	}

	static Variant StringToVariant(const String& value)
	{
		return Variant(value);
	}

	static Variant VectorBufferToVariant(const VectorBuffer& value)
	{
		return Variant(value);
	}

	static Variant ResourceRefToVariantS(StringHash type)
	{
		return Variant(ResourceRef(type));
	}

	static Variant ResourceRefToVariant2(StringHash type, const String& name)
	{
		return Variant(ResourceRef(type, name));
	}

	static Variant ResourceRefToVariant(const ResourceRef& value)
	{
		return Variant(value);
	}

	static Variant ResourceRefListToVariantS(StringHash type)
	{
		return Variant(ResourceRefList(type));
	}

	static Variant ResourceRefListToVariant2(StringHash type, const StringVector& names)
	{
		return Variant(ResourceRefList(type, names));
	}

	static Variant ResourceRefListToVariant(const ResourceRefList& value)
	{
		return Variant(value);
	}

	static Variant VariantVectorToVariant(const VariantVector& value)
	{
		return Variant(value);
	}

	static Variant VariantMapToVariant(const VariantMap& value)
	{
		return Variant(value);
	}

	static Variant StringVectorToVariant(const StringVector& value)
	{
		return Variant(value);
	}

	static Variant IntRectToVariant4(int left, int top, int right, int bottom)
	{
		return Variant(IntRect(left, top, right, bottom));
	}

	static Variant IntRectToVariant(const IntRect& value)
	{
		return Variant(value);
	}

	static Variant IntVector2ToVariant2(int x, int y)
	{
		return Variant(IntVector2(x, y));
	}

	static Variant IntVector2ToVariant(const IntVector2& value)
	{
		return Variant(value);
	}

	static Variant PtrToVariant(RefCounted* value)
	{
		return Variant(value);
	}

	static Variant Matrix3ToVariant9(float v00, float v01, float v02, float v10, float v11, float v12, float v20, float v21, float v22)
	{
		return Variant(Matrix3(v00, v01, v02, v10, v11, v12, v20, v21, v22));
	}

	static Variant Matrix3ToVariant(const Matrix3& value)
	{
		return Variant(value);
	}

	static Variant Matrix3x4ToVariant(const Matrix3x4& value)
	{
		return Variant(value);
	}

	static Variant Matrix4ToVariant(const Matrix4& value)
	{
		return Variant(value);
	}

	static SharedPtr<RefCounted> VariantGetPtr(const Variant* self)
	{
		return SharedPtr<RefCounted>(self->GetPtr());
	}

	using namespace LightInk;
	void bind_class_Variant(LuaModule & lm)
	{
		lua_State * lua = lm.state();
		lm
		[
			LuaRegister<Variant, void ()>(lua, "Variant")
				.def(VariantGetPtr, "GetPtr")
				.def(&Variant::Clear, "Clear")
				.def(static_cast<bool(Variant::*)(const Variant&) const>(&Variant::operator==), "__eq")
				.def(&Variant::GetInt, "GetInt")
				.def(&Variant::GetUInt, "GetUInt")
				.def(&Variant::GetStringHash, "GetStringHash")
				.def(&Variant::GetBool, "GetBool")
				.def(&Variant::GetFloat, "GetFloat")
				.def(&Variant::GetDouble, "GetDouble")
				.def(&Variant::GetVector2, "GetVector2")
				.def(&Variant::GetVector3, "GetVector3")
				.def(&Variant::GetVector4, "GetVector4")
				.def(&Variant::GetQuaternion, "GetQuaternion")
				.def(&Variant::GetColor, "GetColor")
				.def(&Variant::GetString, "GetString")
				.def(&Variant::GetBuffer, "GetRawBuffer")
				.def(&Variant::GetVectorBuffer, "GetBuffer")
				.def(&Variant::GetVoidPtr, "GetVoidPtr")
				.def(&Variant::GetResourceRef, "GetResourceRef")
				.def(&Variant::GetResourceRefList, "GetResourceRefList")
				.def(&Variant::GetVariantVector, "GetVariantVector")
				.def(&Variant::GetStringVector, "GetStringVector")
				.def(&Variant::GetVariantMap, "GetVariantMap")
				.def(&Variant::GetIntRect, "GetIntRect")
				.def(&Variant::GetIntVector2, "GetIntVector2")
				.def(&Variant::GetMatrix3, "GetMatrix3")
				.def(&Variant::GetMatrix3x4, "GetMatrix3x4")
				.def(&Variant::GetMatrix4, "GetMatrix4")
				.def(&Variant::GetType, "GetType")
				.def(static_cast<String(Variant::*)() const>(&Variant::GetTypeName), "GetTypeName")
				.def(&Variant::ToString, "ToString")
				.def(&Variant::IsZero, "IsZero")
				.def(&Variant::IsEmpty, "IsEmpty")
			<=
			LuaRegister<ResourceRefList, void ()>(lua, "ResourceRefList")
				.def(&ResourceRefList::operator==, "__eq")
				.def(&ResourceRefList::type_, "type_")
			<=
			LuaRegister<ResourceRef, void ()>(lua, "ResourceRef")
				.def(, "__eq")
				.def(&ResourceRef::type_, "type_")
				.def(&ResourceRef::name_, "name_")
		];
		
		LuaDefAutoTool::def(lua, IntToVariant, "IntToVariant");
		LuaDefAutoTool::def(lua, UIntToVariant, "UIntToVariant");
		LuaDefAutoTool::def(lua, StringHashToVariant, "StringHashToVariant");
		LuaDefAutoTool::def(lua, BoolToVariant, "BoolToVariant");
		LuaDefAutoTool::def(lua, FloatToVariant, "FloatToVariant");
		LuaDefAutoTool::def(lua, DoubleToVariant, "DoubleToVariant");
		LuaDefAutoTool::def(lua, Vector2ToVariant, "Vector2ToVariant");
		LuaDefAutoTool::def(lua, Vector2ToVariant2, "Vector2ToVariant2");
		LuaDefAutoTool::def(lua, Vector3ToVariant, "Vector3ToVariant");
		LuaDefAutoTool::def(lua, Vector3ToVariant3, "Vector3ToVariant3");
		LuaDefAutoTool::def(lua, Vector4ToVariant, "Vector4ToVariant");
		LuaDefAutoTool::def(lua, Vector4ToVariant4, "Vector4ToVariant4");
		LuaDefAutoTool::def(lua, QuaternionToVariant, "QuaternionToVariant");
		LuaDefAutoTool::def(lua, QuaternionToVariant4, "QuaternionToVariant4");
		LuaDefAutoTool::def(lua, ColorToVariant, "ColorToVariant");
		LuaDefAutoTool::def(lua, ColorToVariant3, "ColorToVariant3");
		LuaDefAutoTool::def(lua, ColorToVariant4, "ColorToVariant4");
		LuaDefAutoTool::def(lua, StringToVariant, "StringToVariant");
		LuaDefAutoTool::def(lua, VectorBufferToVariant, "VectorBufferToVariant");
		LuaDefAutoTool::def(lua, ResourceRefToVariantS, "ResourceRefToVariantS");
		LuaDefAutoTool::def(lua, ResourceRefToVariant, "ResourceRefToVariant");
		LuaDefAutoTool::def(lua, ResourceRefToVariant2, "ResourceRefToVariant2");
		LuaDefAutoTool::def(lua, ResourceRefListToVariantS, "ResourceRefListToVariantS");
		LuaDefAutoTool::def(lua, ResourceRefListToVariant, "ResourceRefListToVariant");
		LuaDefAutoTool::def(lua, ResourceRefListToVariant2, "ResourceRefListToVariant2");
		LuaDefAutoTool::def(lua, VariantVectorToVariant, "VariantVectorToVariant");
		LuaDefAutoTool::def(lua, VariantMapToVariant, "VariantMapToVariant");
		LuaDefAutoTool::def(lua, StringVectorToVariant, "StringVectorToVariant");
		LuaDefAutoTool::def(lua, IntRectToVariant, "IntRectToVariant");
		LuaDefAutoTool::def(lua, IntRectToVariant4, "IntRectToVariant4");
		LuaDefAutoTool::def(lua, IntVector2ToVariant, "IntVector2ToVariant");
		LuaDefAutoTool::def(lua, IntVector2ToVariant2, "IntVector2ToVariant2");
		LuaDefAutoTool::def(lua, PtrToVariant, "PtrToVariant");
		LuaDefAutoTool::def(lua, Matrix3ToVariant, "Matrix3ToVariant");
		LuaDefAutoTool::def(lua, Matrix3ToVariant9, "Matrix3ToVariant9");
		LuaDefAutoTool::def(lua, Matrix3x4ToVariant, "Matrix3x4ToVariant");
		LuaDefAutoTool::def(lua, Matrix4ToVariant, "Matrix4ToVariant");

	}
}

