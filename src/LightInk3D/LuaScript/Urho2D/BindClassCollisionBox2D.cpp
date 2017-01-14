

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
#include "Urho2D/CollisionBox2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_CollisionBox2D(LuaModele & lm)
	{
		lm
		[
			LuaRegister<CollisionBox2D, void ()>(lm.state(), "CollisionBox2D", BaseClassStrategy<CollisionShape2D>())
				.disable_new()
				.def(CreateObject<CollisionBox2D>, "new")
				.def(static_cast<void(CollisionBox2D::*)(const Vector2&)>(&CollisionBox2D::SetSize), "SetSizeV")
				.def(static_cast<void(CollisionBox2D::*)(float, float)>(&CollisionBox2D::SetSize), "SetSizeFF")
				.def(static_cast<void(CollisionBox2D::*)(const Vector2&)>(&CollisionBox2D::SetCenter), "SetCenterV")
				.def(static_cast<void(CollisionBox2D::*)(float, float)>(&CollisionBox2D::SetCenter), "SetCenterFF")
				.def(&CollisionBox2D::SetAngle, "SetAngle")
				.def(&CollisionBox2D::GetSize, "GetSize")
				.def(&CollisionBox2D::GetCenter, "GetCenter")
				.def(&CollisionBox2D::GetAngle, "GetAngle")
				
		];
	}
}
