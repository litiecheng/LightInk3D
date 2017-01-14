

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
#include "Graphics/Camera.h"
#include "Graphics/RenderPath.h"
#include "Graphics/Viewport.h"
#include "Resource/XMLFile.h"
#include "Scene/Scene.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<Viewport> CreateViewport(Context * context)
	{
		return SharedPtr<Viewport>(new Viewport(context));
	}

	static SharedPtr<Viewport> CreateViewportCSC(Context * context, Scene* scene, Camera* camera)
	{
		return SharedPtr<Viewport>(new Viewport(context, scene, camera));
	}

	static SharedPtr<Viewport> CreateViewportCSCR(Context * context, Scene* scene, Camera* camera, RenderPath* renderPath)
	{
		return SharedPtr<Viewport>(new Viewport(context, scene, camera, renderPath));
	}

	static SharedPtr<Viewport> CreateViewportCSCI(Context * context, Scene* scene, Camera* camera, const IntRect& rect)
	{
		return SharedPtr<Viewport>(new Viewport(context, scene, camera, rect));
	}

	static SharedPtr<Viewport> CreateViewportCSCIR(Context * context, Scene* scene, Camera* camera, const IntRect& rect, RenderPath* renderPath)
	{
		return SharedPtr<Viewport>(new Viewport(context, scene, camera, rect, renderPath));
	}
	void bind_class_Viewport(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Viewport, void ()>(lm.state(), "Viewport", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreateViewport, "new")
				.def(CreateViewportCSC, "newCSC")
				.def(CreateViewportCSCR, "newCSCR")
				.def(CreateViewportCSCI, "newCSCI")
				.def(CreateViewportCSCIR, "newCSCIR")
				.def(&Viewport::SetScene, "SetScene")
				.def(&Viewport::SetCamera, "SetCamera")
				.def(&Viewport::SetRect, "SetRect")
				.def(static_cast<void(Viewport::*)(RenderPath*)>(&Viewport::SetRenderPath), "SetRenderPathR")
				.def(static_cast<void(Viewport::*)(XMLFile*)>(&Viewport::SetRenderPath), "SetRenderPathX")
				.def(&Viewport::SetDrawDebug, "SetDrawDebug")
				.def(&Viewport::SetCullCamera, "SetCullCamera")
				.def(&Viewport::GetScene, "GetScene")
				.def(&Viewport::GetCamera, "GetCamera")
				.def(&Viewport::GetRenderPath, "GetRenderPath")
				.def(&Viewport::GetDrawDebug, "GetDrawDebug")
				.def(&Viewport::GetCullCamera, "GetCullCamera")
				.def(&Viewport::GetScreenRay, "GetScreenRay")
				.def(&Viewport::WorldToScreenPoint, "WorldToScreenPoint")
				.def(&Viewport::ScreenToWorldPoint, "ScreenToWorldPoint")

		];
	}
}

