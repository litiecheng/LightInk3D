

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
#include "Urho2D/ParticleEffect2D.h"
#include "Urho2D/ParticleEmitter2D.h"
#include "Urho2D/Sprite2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_ParticleEmitter2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<ParticleEmitter2D, void ()>(lm.state(), "ParticleEmitter2D", BaseClassStrategy<Drawable2D>())
				.disable_new()
				.def(CreateObject<ParticleEmitter2D>, "new")
				.def(&ParticleEmitter2D::SetEffect, "SetEffect")
				.def(&ParticleEmitter2D::SetSprite, "SetSprite")
				.def(&ParticleEmitter2D::SetBlendMode, "SetBlendMode")
				.def(&ParticleEmitter2D::SetMaxParticles, "SetMaxParticles")
				.def(&ParticleEmitter2D::GetEffect, "GetEffect")
				.def(&ParticleEmitter2D::GetSprite, "GetSprite")
				.def(&ParticleEmitter2D::GetBlendMode, "GetBlendMode")
				.def(&ParticleEmitter2D::GetMaxParticles, "GetMaxParticles")

		];
	}
}
