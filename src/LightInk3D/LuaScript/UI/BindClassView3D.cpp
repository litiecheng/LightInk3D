

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
#include "Graphics/Texture2D.h"
#include "Graphics/Viewport.h"
#include "Scene/Scene.h"
#include "UI/View3D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_View3D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<View3D, void ()>(lm.state(), "View3D", BaseClassStrategy<Window>())
				.disable_new()
				.def(CreateObject<View3D>, "new")
				.def(&View3D::SetView, "SetView")
				.def(&View3D::SetFormat, "SetFormat")
				.def(&View3D::SetAutoUpdate, "SetAutoUpdate")
				.def(&View3D::QueueUpdate, "QueueUpdate")
				.def(&View3D::GetFormat, "GetFormat")
				.def(&View3D::GetAutoUpdate, "GetAutoUpdate")
				.def(&View3D::GetScene, "GetScene")
				.def(&View3D::GetCameraNode, "GetCameraNode")
				.def(&View3D::GetRenderTexture, "GetRenderTexture")
				.def(&View3D::GetDepthTexture, "GetDepthTexture")
				.def(&View3D::GetViewport, "GetViewport")

		];
	}
}
