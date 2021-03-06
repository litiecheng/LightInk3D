

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
#include "Urho2D/CollisionCircle2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_CollisionCircle2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<CollisionCircle2D, void ()>(lm.state(), "CollisionCircle2D", BaseClassStrategy<CollisionShape2D>())
				.disable_new()
				.def(CreateObject<CollisionCircle2D>, "new")
				.def(&CollisionCircle2D::SetRadius, "SetRadius")
				.def(static_cast<void(CollisionCircle2D::*)(const Vector2&)>(&CollisionCircle2D::SetCenter), "SetCenterV")
				.def(static_cast<void(CollisionCircle2D::*)(float, float)>(&CollisionCircle2D::SetCenter), "SetCenterFF")
				.def(&CollisionCircle2D::GetRadius, "GetRadius")
				.def(&CollisionCircle2D::GetCenter, "GetCenter")
		];
	}
}
