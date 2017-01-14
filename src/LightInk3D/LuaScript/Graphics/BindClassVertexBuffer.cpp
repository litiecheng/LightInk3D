

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
#include "Graphics/VertexBuffer.h"
#include "IO/VectorBuffer.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static bool VertexBufferSetData(VertexBuffer* self, VectorBuffer& src)
	{
		// Make sure there is enough data
		if (self->GetVertexCount() && src.GetSize() >= self->GetVertexCount() * self->GetVertexSize())
			return self->SetData(&src.GetBuffer()[0]);
		else
			return false;
	}

	static VectorBuffer VertexBufferGetData(VertexBuffer* self)
	{
		VectorBuffer ret;

		void* data = self->Lock(0, self->GetVertexCount(), false);
		if (data)
		{
			ret.Write(data, self->GetVertexCount() * self->GetVertexSize());
			ret.Seek(0);
			self->Unlock();
		}

		return ret;
	}

	static SharedPtr<VertexBuffer> CreateVertexBuffer(Context * context, bool forceHeadless = false)
	{
		return SharedPtr<VertexBuffer>(new VertexBuffer(context, forceHeadless));
	}
	void bind_class_VertexBuffer(LuaModele & lm)
	{
		lm
		[
			LuaRegister<VertexBuffer, void ()>(lm.state(), "VertexBuffer", BaseClassStrategy<GPUObject>())
				.disable_new()
				.def(CreateVertexBuffer, "new")
				.def(&VertexBuffer::SetShadowed, "SetShadowed")
				.def(static_cast<bool(VertexBuffer::*)(unsigned int, const PODVector<VertexElement>&, bool)>(&VertexBuffer::SetSize), "SetSizeUVB")
				.def(static_cast<bool(VertexBuffer::*)(unsigned int, unsigned int, bool)>(&VertexBuffer::SetSize), "SetSizeUUB")
				.def(VertexBufferSetData, "SetData")
				.def(VertexBufferGetData, "GetData")
				.def(&VertexBuffer::SetDataRange, "SetDataRange")
				.def(&VertexBuffer::IsShadowed, "IsShadowed")
				.def(&VertexBuffer::IsDynamic, "IsDynamic")
				.def(&VertexBuffer::GetVertexCount, "GetVertexCount")
				.def(&VertexBuffer::GetVertexSize, "GetVertexSize")
				.def(static_cast<const VertexElement*(VertexBuffer::*)(VertexElementSemantic, unsigned char)const>(&VertexBuffer::GetElement), "GetElementVC")
				.def(static_cast<const VertexElement*(VertexBuffer::*)(VertexElementType, VertexElementSemantic, unsigned char)const>(&VertexBuffer::GetElement), "GetElementVVC")
				.def(static_cast<bool(VertexBuffer::*)(VertexElementSemantic, unsigned char)const>(&VertexBuffer::HasElement), "HasElementVC")
				.def(static_cast<bool(VertexBuffer::*)(VertexElementType, VertexElementSemantic, unsigned char)const>(&VertexBuffer::HasElement), "HasElementVVC")
				.def(&VertexBuffer::GetElementMask, "GetElementMask")
				
		];
	}
}

