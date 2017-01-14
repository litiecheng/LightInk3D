

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
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Camera(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Camera, void ()>(lm.state(), "Camera", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<Camera>, "new")
				.def(&Camera::SetNearClip, "SetNearClip")
				.def(&Camera::SetFarClip, "SetFarClip")
				.def(&Camera::SetFov, "SetFov")
				.def(static_cast<void(Camera::*)(float)>(&Camera::SetOrthoSize), "SetOrthoSizeF")
				.def(static_cast<void(Camera::*)(const Vector2&)>(&Camera::SetOrthoSize), "SetOrthoSizeV")
				.def(&Camera::SetAspectRatio, "SetAspectRatio")
				.def(&Camera::SetFillMode, "SetFillMode")
				.def(&Camera::SetZoom, "SetZoom")
				.def(&Camera::SetLodBias, "SetLodBias")
				.def(&Camera::SetViewMask, "SetViewMask")
				.def(&Camera::SetViewOverrideFlags, "SetViewOverrideFlags")
				.def(&Camera::SetOrthographic, "SetOrthographic")
				.def(&Camera::SetAutoAspectRatio, "SetAutoAspectRatio")
				.def(&Camera::SetProjectionOffset, "SetProjectionOffset")
				.def(&Camera::SetUseReflection, "SetUseReflection")
				.def(&Camera::SetReflectionPlane, "SetReflectionPlane")
				.def(&Camera::SetUseClipping, "SetUseClipping")
				.def(&Camera::SetClipPlane, "SetClipPlane")
				.def(&Camera::SetFlipVertical, "SetFlipVertical")
				.def(&Camera::GetFarClip, "GetFarClip")
				.def(&Camera::GetNearClip, "GetNearClip")
				.def(&Camera::GetFov, "GetFov")
				.def(&Camera::GetOrthoSize, "GetOrthoSize")
				.def(&Camera::GetAspectRatio, "GetAspectRatio")
				.def(&Camera::GetZoom, "GetZoom")
				.def(&Camera::GetLodBias, "GetLodBias")
				.def(&Camera::GetViewMask, "GetViewMask")
				.def(&Camera::GetViewOverrideFlags, "GetViewOverrideFlags")
				.def(&Camera::GetFillMode, "GetFillMode")
				.def(&Camera::IsOrthographic, "IsOrthographic")
				.def(&Camera::GetAutoAspectRatio, "GetAutoAspectRatio")
				.def(&Camera::GetFrustum, "GetFrustum")
				.def(static_cast<const Matrix4&(Camera::*)() const>(&Camera::GetProjection), "GetProjection")
				.def(static_cast<Matrix4(Camera::*)(bool) const>(&Camera::GetProjection), "GetProjectionB")
				.def(&Camera::GetView, "GetView")
				.def(&Camera::GetFrustumSize, "GetFrustumSize")
				.def(&Camera::GetHalfViewSize, "GetHalfViewSize")
				.def(&Camera::GetSplitFrustum, "GetSplitFrustum")
				.def(&Camera::GetViewSpaceFrustum, "GetViewSpaceFrustum")
				.def(&Camera::GetViewSpaceSplitFrustum, "GetViewSpaceSplitFrustum")
				.def(&Camera::GetScreenRay, "GetScreenRay")
				.def(&Camera::WorldToScreenPoint, "WorldToScreenPoint")
				.def(&Camera::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Camera::GetProjectionOffset, "GetProjectionOffset")
				.def(&Camera::GetUseReflection, "GetUseReflection")
				.def(&Camera::GetReflectionPlane, "GetReflectionPlane")
				.def(&Camera::GetUseClipping, "GetUseClipping")
				.def(&Camera::GetClipPlane, "GetClipPlane")
				.def(&Camera::GetFlipVertical, "GetFlipVertical")
				.def(&Camera::GetDistance, "GetDistance")
				.def(&Camera::GetDistanceSquared, "GetDistanceSquared")
				.def(&Camera::GetLodDistance, "GetLodDistance")
				.def(&Camera::IsProjectionValid, "IsProjectionValid")
				.def(&Camera::GetEffectiveWorldTransform, "GetEffectiveWorldTransform")

		];
	}
}

