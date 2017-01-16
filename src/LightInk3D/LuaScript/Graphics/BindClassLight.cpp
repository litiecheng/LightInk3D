

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
#include "Graphics/Light.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Light(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Light, void ()>(lm.state(), "Light", BaseClassStrategy<Drawable>())
				.disable_new()
				.def(CreateObject<Light>, "new")
				.def(&Light::SetLightType, "SetLightType")
				.def(&Light::SetPerVertex, "SetPerVertex")
				.def(&Light::SetColor, "SetColor")
				.def(&Light::SetSpecularIntensity, "SetSpecularIntensity")
				.def(&Light::SetBrightness, "SetBrightness")
				.def(&Light::SetRange, "SetRange")
				.def(&Light::SetFov, "SetFov")
				.def(&Light::SetAspectRatio, "SetAspectRatio")
				.def(&Light::SetFadeDistance, "SetFadeDistance")
				.def(&Light::SetShadowFadeDistance, "SetShadowFadeDistance")
				.def(&Light::SetShadowBias, "SetShadowBias")
				.def(&Light::SetShadowCascade, "SetShadowCascade")
				.def(&Light::SetShadowFocus, "SetShadowFocus")
				.def(&Light::SetShadowIntensity, "SetShadowIntensity")
				.def(&Light::SetShadowResolution, "SetShadowResolution")
				.def(&Light::SetShadowNearFarRatio, "SetShadowNearFarRatio")
				.def(&Light::SetRampTexture, "SetRampTexture")
				.def(&Light::SetShapeTexture, "SetShapeTexture")
				.def(&Light::GetLightType, "GetLightType")
				.def(&Light::GetPerVertex, "GetPerVertex")
				.def(&Light::GetColor, "GetColor")
				.def(&Light::GetSpecularIntensity, "GetSpecularIntensity")
				.def(&Light::GetBrightness, "GetBrightness")
				.def(&Light::GetEffectiveColor, "GetEffectiveColor")
				.def(&Light::GetEffectiveSpecularIntensity, "GetEffectiveSpecularIntensity")
				.def(&Light::GetRange, "GetRange")
				.def(&Light::GetFov, "GetFov")
				.def(&Light::GetAspectRatio, "GetAspectRatio")
				.def(&Light::GetFadeDistance, "GetFadeDistance")
				.def(&Light::GetShadowFadeDistance, "GetShadowFadeDistance")
				.def(&Light::GetShadowBias, "GetShadowBias")
				.def(&Light::GetShadowCascade, "GetShadowCascade")
				.def(&Light::GetShadowFocus, "GetShadowFocus")
				.def(&Light::GetShadowIntensity, "GetShadowIntensity")
				.def(&Light::GetShadowResolution, "GetShadowResolution")
				.def(&Light::GetShadowNearFarRatio, "GetShadowNearFarRatio")
				.def(&Light::GetRampTexture, "GetRampTexture")
				.def(&Light::GetShapeTexture, "GetShapeTexture")
				.def(&Light::GetFrustum, "GetFrustum")
				.def(&Light::GetViewSpaceFrustum, "GetViewSpaceFrustum")
				.def(&Light::GetNumShadowSplits, "GetNumShadowSplits")
				.def(&Light::IsNegative, "IsNegative")
			<=
			LuaRegister<FocusParameters, void ()>(lm.state(), "FocusParameters")
				.def(&FocusParameters::Validate, "Validate")
				.def(&FocusParameters::focus_, "focus")
				.def(&FocusParameters::nonUniform_, "nonUniform")
				.def(&FocusParameters::autoSize_, "autoSize")
				.def(&FocusParameters::quantize_, "quantize")
				.def(&FocusParameters::minView_, "minView")
			<=
			LuaRegister<CascadeParameters, void (float, float, float, float, float, float)>(lm.state(), "CascadeParameters")
				.def(&CascadeParameters::fadeStart_, "fadeStart")
				.def(&CascadeParameters::biasAutoAdjust_, "biasAutoAdjust")
			<=
			LuaRegister<BiasParameters, void ()>(lm.state(), "BiasParameters")
				.def(&FocusParameters::constantBias_, "constantBias")
				.def(&FocusParameters::slopeScaledBias_, "slopeScaledBias")
				.def(&FocusParameters::normalOffset_, "normalOffset")
		];
	}
}

