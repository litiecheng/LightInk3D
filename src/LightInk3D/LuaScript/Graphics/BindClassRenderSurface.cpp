

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
#include "Graphics/RenderSurface.h"
#include "Graphics/Texture.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_RenderSurface(LuaModule & lm)
	{
		lm
		[
			LuaRegister<RenderSurface, void (Texture*)>(lm.state(), "RenderSurface", BaseClassStrategy<RefCounted>())
				.def(&RenderSurface::SetNumViewports, "SetNumViewports")
				.def(&RenderSurface::SetViewport, "SetViewport")
				.def(&RenderSurface::SetUpdateMode, "SetUpdateMode")
				.def(&RenderSurface::SetLinkedRenderTarget, "SetLinkedRenderTarget")
				.def(&RenderSurface::SetLinkedDepthStencil, "SetLinkedDepthStencil")
				.def(&RenderSurface::QueueUpdate, "QueueUpdate")
				.def(&RenderSurface::Release, "Release")
				.def(&RenderSurface::GetParentTexture, "GetParentTexture")
				.def(&RenderSurface::GetWidth, "GetWidth")
				.def(&RenderSurface::GetHeight, "GetHeight")
				.def(&RenderSurface::GetUsage, "GetUsage")
				.def(&RenderSurface::GetNumViewports, "GetNumViewports")
				.def(&RenderSurface::GetViewport, "GetViewport")
				.def(&RenderSurface::GetUpdateMode, "GetUpdateMode")
				.def(&RenderSurface::GetLinkedRenderTarget, "GetLinkedRenderTarget")
				.def(&RenderSurface::GetLinkedDepthStencil, "GetLinkedDepthStencil")
				
		];
	}
}

