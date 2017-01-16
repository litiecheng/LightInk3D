

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
#include "Graphics/IndexBuffer.h"
#include "IO/VectorBuffer.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<IndexBuffer> CreateIndexBuffer(Context * context, bool forceHeadless = false)
	{
		return SharedPtr<IndexBuffer>(new IndexBuffer(context, forceHeadless));
	}
	
	static bool IndexBufferSetData(IndexBuffer* self, VectorBuffer& src)
	{
		// Make sure there is enough data
		if (self->GetIndexCount() && src.GetSize() >= self->GetIndexCount() * self->GetIndexSize())
			return self->SetData(&src.GetBuffer()[0]);
		else
			return false;
	}

	static VectorBuffer IndexBufferGetData(IndexBuffer* self)
	{
		VectorBuffer ret;
		
		void* data = self->Lock(0, self->GetIndexCount(), false);
		if (data)
		{
			ret.Write(data, self->GetIndexCount() * self->GetIndexSize());
			ret.Seek(0);
			self->Unlock();
		}

		return ret;
	}

	void bind_class_IndexBuffer(LuaModule & lm)
	{
		lm
		[
			LuaRegister<IndexBuffer, void ()>(lm.state(), "IndexBuffer", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreateIndexBuffer, "new")
				.def(IndexBufferSetData, "SetData")
				.def(IndexBufferGetData, "GetData")
				.def(&IndexBuffer::SetShadowed, "SetShadowed")
				.def(&IndexBuffer::SetSize, "SetSize")
				.def(&IndexBuffer::IsShadowed, "IsShadowed")
				.def(&IndexBuffer::IsDynamic, "IsDynamic")
				.def(&IndexBuffer::GetIndexCount, "GetIndexCount")
				.def(&IndexBuffer::GetIndexSize, "GetIndexSize")
				
		];
	}
}

