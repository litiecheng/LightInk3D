

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
#include "Graphics/Texture2D.h"
#include "Urho2D/Sprite2D.h"
#include "Urho2D/SpriteSheet2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Sprite2D(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Sprite2D, void ()>(lm.state(), "Sprite2D", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<Sprite2D>, "new")
				.def(&Sprite2D::SetTexture, "SetTexture")
				.def(&Sprite2D::SetRectangle, "SetRectangle")
				.def(&Sprite2D::SetHotSpot, "SetHotSpot")
				.def(&Sprite2D::SetOffset, "SetOffset")
				.def(&Sprite2D::SetTextureEdgeOffset, "SetTextureEdgeOffset")
				.def(&Sprite2D::SetSpriteSheet, "SetSpriteSheet")
				.def(&Sprite2D::GetTexture, "GetTexture")
				.def(&Sprite2D::GetRectangle, "GetRectangle")
				.def(&Sprite2D::GetHotSpot, "GetHotSpot")
				.def(&Sprite2D::GetOffset, "GetOffset")
				.def(&Sprite2D::GetTextureEdgeOffset, "GetTextureEdgeOffset")
				.def(&Sprite2D::GetSpriteSheet, "GetSpriteSheet")
				
		];
	}
}
