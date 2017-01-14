

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
#include "Graphics/Texture.h"
#include "UI/Sprite.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Sprite(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Sprite, void ()>(lm.state(), "Sprite", BaseClassStrategy<UIElement>())
				.disable_new()
				.def(CreateObject<Sprite>, "new")
				.def(static_cast<void(Sprite::*)(const Vector2&)>(&Sprite::SetPosition), "SetPositionV")
				.def(static_cast<void(Sprite::*)(float, float)>(&Sprite::SetPosition), "SetPositionFF")
				.def(static_cast<void(Sprite::*)(const IntVector2&)>(&Sprite::SetHotSpot), "SetHotSpotIV")
				.def(static_cast<void(Sprite::*)(int, int)>(&Sprite::SetHotSpot), "SetHotSpotII")
				.def(static_cast<void(Sprite::*)(const Vector2&)>(&Sprite::SetScale), "SetScaleV")
				.def(static_cast<void(Sprite::*)(float, float)>(&Sprite::SetScale), "SetScaleFF")
				.def(static_cast<void(Sprite::*)(float)>(&Sprite::SetScale), "SetScaleF")
				.def(&Sprite::SetRotation, "SetRotation")
				.def(&Sprite::SetTexture, "SetTexture")
				.def(&Sprite::SetImageRect, "SetImageRect")
				.def(&Sprite::SetFullImageRect, "SetFullImageRect")
				.def(&Sprite::SetBlendMode, "SetBlendMode")
				.def(&Sprite::GetPosition, "GetPosition")
				.def(&Sprite::GetHotSpot, "GetHotSpot")
				.def(&Sprite::GetScale, "GetScale")
				.def(&Sprite::GetRotation, "GetRotation")
				.def(&Sprite::GetTexture, "GetTexture")
				.def(&Sprite::GetImageRect, "GetImageRect")
				.def(&Sprite::GetBlendMode, "GetBlendMode")
				.def(&Sprite::GetTransform, "GetTransform")
				
		];
	}
}
