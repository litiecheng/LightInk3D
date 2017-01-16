

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
#include "Graphics/Material.h"
#include "Urho2D/Sprite2D.h"
#include "Urho2D/StaticSprite2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_StaticSprite2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<StaticSprite2D, void ()>(lm.state(), "StaticSprite2D", BaseClassStrategy<Drawable2D>())
				.disable_new()
				.def(CreateObject<StaticSprite2D>, "new")
				.def(&StaticSprite2D::SetSprite, "SetSprite")
				.def(&StaticSprite2D::SetBlendMode, "SetBlendMode")
				.def(&StaticSprite2D::SetFlip, "SetFlip")
				.def(&StaticSprite2D::SetFlipX, "SetFlipX")
				.def(&StaticSprite2D::SetFlipY, "SetFlipY")
				.def(&StaticSprite2D::SetColor, "SetColor")
				.def(&StaticSprite2D::SetAlpha, "SetAlpha")
				.def(&StaticSprite2D::SetUseHotSpot, "SetUseHotSpot")
				.def(&StaticSprite2D::SetHotSpot, "SetHotSpot")
				.def(&StaticSprite2D::SetCustomMaterial, "SetCustomMaterial")
				.def(&StaticSprite2D::GetSprite, "GetSprite")
				.def(&StaticSprite2D::GetBlendMode, "GetBlendMode")
				.def(&StaticSprite2D::GetFlipX, "GetFlipX")
				.def(&StaticSprite2D::GetFlipY, "GetFlipY")
				.def(&StaticSprite2D::GetColor, "GetColor")
				.def(&StaticSprite2D::GetAlpha, "GetAlpha")
				.def(&StaticSprite2D::GetUseHotSpot, "GetUseHotSpot")
				.def(&StaticSprite2D::GetHotSpot, "GetHotSpot")
				.def(&StaticSprite2D::GetCustomMaterial, "GetCustomMaterial")
				
		];
	}
}
