

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


#include "../../Precompiled.h"
#include "../../Graphics/Material.h"
#include "../../Graphics/ParticleEffect.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_ParticleEffect(LuaModele & lm)
	{
		lm
		[
			LuaRegister<ParticleEffect, void ()>(lm.state(), "ParticleEffect", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<ParticleEffect>, "new")
				.def(&ParticleEffect::SetMaterial, "SetMaterial")
				.def(&ParticleEffect::SetNumParticles, "SetNumParticles")
				.def(&ParticleEffect::SetUpdateInvisible, "SetUpdateInvisible")
				.def(&ParticleEffect::SetRelative, "SetRelative")
				.def(&ParticleEffect::SetScaled, "SetScaled")
				.def(&ParticleEffect::SetSorted, "SetSorted")
				.def(&ParticleEffect::SetFixedScreenSize, "SetFixedScreenSize")
				.def(&ParticleEffect::SetAnimationLodBias, "SetAnimationLodBias")
				.def(&ParticleEffect::SetEmitterType, "SetEmitterType")
				.def(&ParticleEffect::SetEmitterSize, "SetEmitterSize")
				.def(&ParticleEffect::SetMinDirection, "SetMinDirection")
				.def(&ParticleEffect::SetMaxDirection, "SetMaxDirection")
				.def(&ParticleEffect::SetConstantForce, "SetConstantForce")
				.def(&ParticleEffect::SetDampingForce, "SetDampingForce")
				.def(&ParticleEffect::SetActiveTime, "SetActiveTime")
				.def(&ParticleEffect::SetInactiveTime, "SetInactiveTime")
				.def(&ParticleEffect::SetMinEmissionRate, "SetMinEmissionRate")
				.def(&ParticleEffect::SetMaxEmissionRate, "SetMaxEmissionRate")
				.def(&ParticleEffect::SetMinParticleSize, "SetMinParticleSize")
				.def(&ParticleEffect::SetMaxParticleSize, "SetMaxParticleSize")
				.def(&ParticleEffect::SetMinTimeToLive, "SetMinTimeToLive")
				.def(&ParticleEffect::SetMaxTimeToLive, "SetMaxTimeToLive")
				.def(&ParticleEffect::SetMinVelocity, "SetMinVelocity")
				.def(&ParticleEffect::SetMaxVelocity, "SetMaxVelocity")
				.def(&ParticleEffect::SetMinRotation, "SetMinRotation")
				.def(&ParticleEffect::SetMaxRotation, "SetMaxRotation")
				.def(&ParticleEffect::SetMinRotationSpeed, "SetMinRotationSpeed")
				.def(&ParticleEffect::SetMaxRotationSpeed, "SetMaxRotationSpeed")
				.def(&ParticleEffect::SetSizeAdd, "SetSizeAdd")
				.def(&ParticleEffect::SetSizeMul, "SetSizeMul")
				.def(&ParticleEffect::SetFaceCameraMode, "SetFaceCameraMode")
				.def(&ParticleEffect::AddColorTime, "AddColorTime")
				.def(&ParticleEffect::AddColorFrame, "AddColorFrame")
				.def(&ParticleEffect::RemoveColorFrame, "RemoveColorFrame")
				.def(&ParticleEffect::SetColorFrames, "SetColorFrames")
				.def(&ParticleEffect::SetColorFrame, "SetColorFrame")
				.def(&ParticleEffect::SetNumColorFrames, "SetNumColorFrames")
				.def(&ParticleEffect::SortColorFrames, "SortColorFrames")
				.def(&ParticleEffect::AddTextureTime, "AddTextureTime")
				.def(&ParticleEffect::AddTextureFrame, "AddTextureFrame")
				.def(&ParticleEffect::RemoveTextureFrame, "RemoveTextureFrame")
				.def(&ParticleEffect::SetTextureFrames, "SetTextureFrames")
				.def(&ParticleEffect::SetTextureFrame, "SetTextureFrame")
				.def(&ParticleEffect::SetNumTextureFrames, "SetNumTextureFrames")
				.def(&ParticleEffect::SortTextureFrames, "SortTextureFrames")
				.def(&ParticleEffect::Clone, "Clone")
				.def(&ParticleEffect::GetMaterial, "GetMaterial")
				.def(&ParticleEffect::GetNumParticles, "GetNumParticles")
				.def(&ParticleEffect::GetUpdateInvisible, "GetUpdateInvisible")
				.def(&ParticleEffect::IsRelative, "IsRelative")
				.def(&ParticleEffect::IsScaled, "IsScaled")
				.def(&ParticleEffect::IsSorted, "IsSorted")
				.def(&ParticleEffect::IsFixedScreenSize, "IsFixedScreenSize")
				.def(&ParticleEffect::GetAnimationLodBias, "GetAnimationLodBias")
				.def(&ParticleEffect::GetEmitterType, "GetEmitterType")
				.def(&ParticleEffect::GetEmitterSize, "GetEmitterSize")
				.def(&ParticleEffect::GetMinDirection, "GetMinDirection")
				.def(&ParticleEffect::GetMaxDirection, "GetMaxDirection")
				.def(&ParticleEffect::GetConstantForce, "GetConstantForce")
				.def(&ParticleEffect::GetDampingForce, "GetDampingForce")
				.def(&ParticleEffect::GetActiveTime, "GetActiveTime")
				.def(&ParticleEffect::GetInactiveTime, "GetInactiveTime")
				.def(&ParticleEffect::GetMinEmissionRate, "GetMinEmissionRate")
				.def(&ParticleEffect::GetMaxEmissionRate, "GetMaxEmissionRate")
				.def(&ParticleEffect::GetMinParticleSize, "GetMinParticleSize")
				.def(&ParticleEffect::GetMaxParticleSize, "GetMaxParticleSize")
				.def(&ParticleEffect::GetMinTimeToLive, "GetMinTimeToLive")
				.def(&ParticleEffect::GetMaxTimeToLive, "GetMaxTimeToLive")
				.def(&ParticleEffect::GetMinVelocity, "GetMinVelocity")
				.def(&ParticleEffect::GetMaxVelocity, "GetMaxVelocity")
				.def(&ParticleEffect::GetMinRotation, "GetMinRotation")
				.def(&ParticleEffect::GetMaxRotation, "GetMaxRotation")
				.def(&ParticleEffect::GetMinRotationSpeed, "GetMinRotationSpeed")
				.def(&ParticleEffect::GetMaxRotationSpeed, "GetMaxRotationSpeed")
				.def(&ParticleEffect::GetSizeAdd, "GetSizeAdd")
				.def(&ParticleEffect::GetSizeMul, "GetSizeMul")
				.def(&ParticleEffect::GetColorFrames, "GetColorFrames")
				.def(&ParticleEffect::GetNumColorFrames, "GetNumColorFrames")
				.def(&ParticleEffect::GetColorFrame, "GetColorFrame")
				.def(&ParticleEffect::GetTextureFrames, "GetTextureFrames")
				.def(&ParticleEffect::GetNumTextureFrames, "GetNumTextureFrames")
				.def(&ParticleEffect::GetTextureFrame, "GetTextureFrame")
				.def(&ParticleEffect::GetFaceCameraMode, "GetFaceCameraMode")
			<=
			LuaRegister<TextureFrame, void ()>(lm.state(), "TextureFrame")
				.def(&TextureFrame::uv_, "uv")
				.def(&TextureFrame::time_, "time")
			<=
			LuaRegister<ColorFrame, void ()>(lm.state(), "ColorFrame")
				.def(&ColorFrame::Interpolate, "Interpolate")
				.def(&ColorFrame::color_, "color")
				.def(&ColorFrame::time_, "time")
		];
	}
}

