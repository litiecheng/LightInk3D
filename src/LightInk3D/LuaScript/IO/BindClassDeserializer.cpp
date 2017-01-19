

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
#include "IO/Deserializer.h"
#include "IO/VectorBuffer.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static VectorBuffer DeserializerRead(Deserializer* self, unsigned size)
	{
		unsigned char* data = new unsigned char[size];
		self->Read(data, size);
		VectorBuffer buffer(data, size);
		delete[] data;
		return buffer;
	}

	static VectorBuffer DeserializerReadBuffer(Deserializer* self)
	{
		return VectorBuffer(self->ReadBuffer());
	}
	void bind_class_Deserializer(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Deserializer, void>(lm.state(), "Deserializer")
				.disable_new()
				.def(DeserializerRead, "Read")
				.def(&Deserializer::Seek, "Seek")
				.def(&Deserializer::GetName, "GetName")
				.def(&Deserializer::GetChecksum, "GetChecksum")
				.def(&Deserializer::IsEof, "IsEof")
				.def(&Deserializer::GetPosition, "GetPosition")
				.def(&Deserializer::GetSize, "GetSize")
				.def(&Deserializer::ReadInt, "ReadInt")
				.def(&Deserializer::ReadInt64, "ReadInt64")
				.def(&Deserializer::ReadShort, "ReadShort")
				.def(&Deserializer::ReadByte, "ReadByte")
				.def(&Deserializer::ReadUInt, "ReadUInt")
				.def(&Deserializer::ReadUInt64, "ReadUInt64")
				.def(&Deserializer::ReadUShort, "ReadUShort")
				.def(&Deserializer::ReadUByte, "ReadUByte")
				.def(&Deserializer::ReadBool, "ReadBool")
				.def(&Deserializer::ReadFloat, "ReadFloat")
				.def(&Deserializer::ReadDouble, "ReadDouble")
				.def(&Deserializer::ReadIntRect, "ReadIntRect")
				.def(&Deserializer::ReadIntVector2, "ReadIntVector2")
				.def(&Deserializer::ReadRect, "ReadRect")
				.def(&Deserializer::ReadVector2, "ReadVector2")
				.def(&Deserializer::ReadVector3, "ReadVector3")
				.def(&Deserializer::ReadPackedVector3, "ReadPackedVector3")
				.def(&Deserializer::ReadVector4, "ReadVector4")
				.def(&Deserializer::ReadQuaternion, "ReadQuaternion")
				.def(&Deserializer::ReadPackedQuaternion, "ReadPackedQuaternion")
				.def(&Deserializer::ReadMatrix3, "ReadMatrix3")
				.def(&Deserializer::ReadMatrix3x4, "ReadMatrix3x4")
				.def(&Deserializer::ReadMatrix4, "ReadMatrix4")
				.def(&Deserializer::ReadColor, "ReadColor")
				.def(&Deserializer::ReadBoundingBox, "ReadBoundingBox")
				.def(&Deserializer::ReadString, "ReadString")
				.def(&Deserializer::ReadFileID, "ReadFileID")
				.def(&Deserializer::ReadStringHash, "ReadStringHash")
				.def(DeserializerReadBuffer, "ReadBuffer")
				.def(&Deserializer::ReadResourceRef, "ReadResourceRef")
				.def(&Deserializer::ReadResourceRefList, "ReadResourceRefList")
				.def(static_cast<Variant(Deserializer::*)()>(&Deserializer::ReadVariant), "ReadVariant")
				.def(static_cast<Variant(Deserializer::*)(VariantType)>(&Deserializer::ReadVariant), "ReadVariantV")
				.def(&Deserializer::ReadVariantVector, "ReadVariantVector")
				.def(&Deserializer::ReadStringVector, "ReadStringVector")
				.def(&Deserializer::ReadVariantMap, "ReadVariantMap")
				.def(&Deserializer::ReadVLE, "ReadVLE")
				.def(&Deserializer::ReadNetID, "ReadNetID")
				.def(&Deserializer::ReadLine, "ReadLine")
		];
	}
}

