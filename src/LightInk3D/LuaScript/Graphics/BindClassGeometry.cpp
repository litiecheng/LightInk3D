

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
#include "Graphics/Geometry.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/VertexBuffer.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Geometry(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Geometry, void ()>(lm.state(), "Geometry", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreateObject<Geometry>, "new")
				.def(&Geometry::SetNumVertexBuffers, "SetNumVertexBuffers")
				.def(&Geometry::SetVertexBuffer, "SetVertexBuffer")
				.def(&Geometry::SetIndexBuffer, "SetIndexBuffer")
				.def(static_cast<bool(Geometry::*)(PrimitiveType, unsigned, unsigned, bool)>(&Geometry::SetDrawRange), "SetDrawRangePUUB")
				.def(static_cast<bool(Geometry::*)(PrimitiveType, unsigned, unsigned, unsigned, unsigned, bool)>(&Geometry::SetDrawRange), "SetDrawRangePUUUUB")
				.def(&Geometry::SetLodDistance, "SetLodDistance")
				.def(&Geometry::GetNumVertexBuffers, "GetNumVertexBuffers")
				.def(&Geometry::GetVertexBuffer, "GetVertexBuffer")
				.def(&Geometry::GetIndexBuffer, "GetIndexBuffer")
				.def(&Geometry::GetPrimitiveType, "GetPrimitiveType")
				.def(&Geometry::GetIndexStart, "GetIndexStart")
				.def(&Geometry::GetIndexCount, "GetIndexCount")
				.def(&Geometry::GetVertexStart, "GetVertexStart")
				.def(&Geometry::GetVertexCount, "GetVertexCount")
				.def(&Geometry::GetLodDistance, "GetLodDistance")
				.def(&Geometry::IsEmpty, "IsEmpty")
		];
	}
}

