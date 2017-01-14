

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
#include "Graphics/Graphics.h"
#include "IO/Deserializer.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Graphics(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Graphics, void ()>(lm.state(), "Graphics", BaseClassStrategy<Object>())
				.def(&Graphics::SetWindowIcon, "SetWindowIcon")
				.def(&Graphics::SetWindowTitle, "SetWindowTitle")
				.def(static_cast<void(Graphics::*)(const IntVector2&)>(&Graphics::SetWindowPosition), "SetWindowPositionV")
				.def(static_cast<void(Graphics::*)(int, int)>(&Graphics::SetWindowPosition), "SetWindowPositionII")
				.def(static_cast<bool(Graphics::*)(int, int, bool, bool, bool, bool, bool, bool, int)>(&Graphics::SetMode), "SetModeII6BI")
				.def(static_cast<bool(Graphics::*)(int, int)>(&Graphics::SetMode), "SetModeII")
				.def(&Graphics::SetSRGB, "SetSRGB")
				.def(&Graphics::SetDither, "SetDither")
				.def(&Graphics::SetFlushGPU, "SetFlushGPU")
				.def(&Graphics::SetOrientations, "SetOrientations")
				.def(&Graphics::ToggleFullscreen, "ToggleFullscreen")
				.def(&Graphics::Maximize, "Maximize")
				.def(&Graphics::Minimize, "Minimize")
				.def(&Graphics::Close, "Close")
				.def(&Graphics::TakeScreenShot, "TakeScreenShot")
				.def(&Graphics::BeginDumpShaders, "BeginDumpShaders")
				.def(&Graphics::EndDumpShaders, "EndDumpShaders")
				.def(&Graphics::PrecacheShaders, "PrecacheShaders")
				.def(&Graphics::IsInitialized, "IsInitialized")
				.def(&Graphics::GetWindowTitle, "GetWindowTitle")
				.def(&Graphics::GetApiName, "GetApiName")
				.def(&Graphics::GetWindowPosition, "GetWindowPosition")
				.def(&Graphics::GetWidth, "GetWidth")
				.def(&Graphics::GetHeight, "GetHeight")
				.def(&Graphics::GetMultiSample, "GetMultiSample")
				.def(&Graphics::GetFullscreen, "GetFullscreen")
				.def(&Graphics::GetBorderless, "GetBorderless")
				.def(&Graphics::GetResizable, "GetResizable")
				.def(&Graphics::GetVSync, "GetVSync")
				.def(&Graphics::GetTripleBuffer, "GetTripleBuffer")
				.def(&Graphics::GetSRGB, "GetSRGB")
				.def(&Graphics::GetDither, "GetDither")
				.def(&Graphics::GetFlushGPU, "GetFlushGPU")
				.def(&Graphics::GetOrientations, "GetOrientations")
				.def(&Graphics::GetNumPrimitives, "GetNumPrimitives")
				.def(&Graphics::GetNumBatches, "GetNumBatches")
				.def(&Graphics::GetDummyColorFormat, "GetDummyColorFormat")
				.def(&Graphics::GetShadowMapFormat, "GetShadowMapFormat")
				.def(&Graphics::GetHiresShadowMapFormat, "GetHiresShadowMapFormat")
				.def(&Graphics::GetInstancingSupport, "GetInstancingSupport")
				.def(&Graphics::GetLightPrepassSupport, "GetLightPrepassSupport")
				.def(&Graphics::GetDeferredSupport, "GetDeferredSupport")
				.def(&Graphics::GetHardwareShadowSupport, "GetHardwareShadowSupport")
				.def(&Graphics::GetReadableDepthSupport, "GetReadableDepthSupport")
				.def(&Graphics::GetSRGBSupport, "GetSRGBSupport")
				.def(&Graphics::GetSRGBWriteSupport, "GetSRGBWriteSupport")
				.def(&Graphics::GetDesktopResolution, "GetDesktopResolution")
				.def(Graphics::GetAlphaFormat, "GetAlphaFormat")
				.def(Graphics::GetLuminanceFormat, "GetLuminanceFormat")
				.def(Graphics::GetLuminanceAlphaFormat, "GetLuminanceAlphaFormat")
				.def(Graphics::GetRGBFormat, "GetRGBFormat")
				.def(Graphics::GetRGBAFormat, "GetRGBAFormat")
				.def(Graphics::GetRGBA16Format, "GetRGBA16Format")
				.def(Graphics::GetRGBAFloat16Format, "GetRGBAFloat16Format")
				.def(Graphics::GetRGBAFloat32Format, "GetRGBAFloat32Format")
				.def(Graphics::GetRG16Format, "GetRG16Format")
				.def(Graphics::GetRGFloat16Format, "GetRGFloat16Format")
				.def(Graphics::GetRGFloat32Format, "GetRGFloat32Format")
				.def(Graphics::GetFloat16Format, "GetFloat16Format")
				.def(Graphics::GetFloat32Format, "GetFloat32Format")
				.def(Graphics::GetLinearDepthFormat, "GetLinearDepthFormat")
				.def(Graphics::GetDepthStencilFormat, "GetDepthStencilFormat")
				.def(Graphics::GetReadableDepthFormat, "GetReadableDepthFormat")
				.def(Graphics::GetPixelUVOffset, "GetPixelUVOffset")
				.def(Graphics::GetMaxBones, "GetMaxBones")
				
				
		];
	}
}

