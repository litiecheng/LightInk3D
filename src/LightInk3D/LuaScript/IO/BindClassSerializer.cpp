

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
#include "IO/Serializer.h"
#include "IO/VectorBuffer.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static unsigned SerializerWrite(Serializer* self, const VectorBuffer& buffer)
	{
		return self->Write(buffer.GetData(), buffer.GetSize());
	}

	static bool SerializerWriteBuffer(Serializer* self, const VectorBuffer& buffer)
	{
		return self->WriteBuffer(buffer.GetBuffer());
	}
	void bind_class_Serializer(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Serializer, void ()>(lm.state(), "Serializer")
				.def(SerializerWrite, "Write")
				.def(&Serializer::WriteInt, "WriteInt")
				.def(&Serializer::WriteInt64, "WriteInt64")
				.def(&Serializer::WriteShort, "WriteShort")
				.def(&Serializer::WriteByte, "WriteByte")
				.def(&Serializer::WriteUInt, "WriteUInt")
				.def(&Serializer::WriteUInt64, "WriteUInt64")
				.def(&Serializer::WriteUShort, "WriteUShort")
				.def(&Serializer::WriteUByte, "WriteUByte")
				.def(&Serializer::WriteBool, "WriteBool")
				.def(&Serializer::WriteFloat, "WriteFloat")
				.def(&Serializer::WriteDouble, "WriteDouble")
				.def(&Serializer::WriteIntRect, "WriteIntRect")
				.def(&Serializer::WriteIntVector2, "WriteIntVector2")
				.def(&Serializer::WriteRect, "WriteRect")
				.def(&Serializer::WriteVector2, "WriteVector2")
				.def(&Serializer::WriteVector3, "WriteVector3")
				.def(&Serializer::WritePackedVector3, "WritePackedVector3")
				.def(&Serializer::WriteVector4, "WriteVector4")
				.def(&Serializer::WriteQuaternion, "WriteQuaternion")
				.def(&Serializer::WritePackedQuaternion, "WritePackedQuaternion")
				.def(&Serializer::WriteMatrix3, "WriteMatrix3")
				.def(&Serializer::WriteMatrix3x4, "WriteMatrix3x4")
				.def(&Serializer::WriteMatrix4, "WriteMatrix4")
				.def(&Serializer::WriteColor, "WriteColor")
				.def(&Serializer::WriteBoundingBox, "WriteBoundingBox")
				.def(&Serializer::WriteString, "WriteString")
				.def(&Serializer::WriteFileID, "WriteFileID")
				.def(&Serializer::WriteStringHash, "WriteStringHash")
				.def(SerializerWriteBuffer, "WriteBuffer")
				.def(&Serializer::WriteResourceRef, "WriteResourceRef")
				.def(&Serializer::WriteResourceRefList, "WriteResourceRefList")
				.def(&Serializer::WriteVariant, "WriteVariant")
				.def(&Serializer::WriteVariantData, "WriteVariantData")
				.def(&Serializer::WriteVariantVector, "WriteVariantVector")
				.def(&Serializer::WriteStringVector, "WriteStringVector")
				.def(&Serializer::WriteVariantMap, "WriteVariantMap")
				.def(&Serializer::WriteVLE, "WriteVLE")
				.def(&Serializer::WriteNetID, "WriteNetID")
				.def(&Serializer::WriteLine, "WriteLine")

		];
	}
}

