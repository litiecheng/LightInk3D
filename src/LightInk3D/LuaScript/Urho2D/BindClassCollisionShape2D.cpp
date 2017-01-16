

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
#include "Urho2D/CollisionShape2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_CollisionShape2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<CollisionShape2D, void ()>(lm.state(), "CollisionShape2D", BaseClassStrategy<Component>())
				.def(&CollisionShape2D::SetTrigger, "SetTrigger")
				.def(&CollisionShape2D::SetCategoryBits, "SetCategoryBits")
				.def(&CollisionShape2D::SetMaskBits, "SetMaskBits")
				.def(&CollisionShape2D::SetGroupIndex, "SetGroupIndex")
				.def(&CollisionShape2D::SetDensity, "SetDensity")
				.def(&CollisionShape2D::SetFriction, "SetFriction")
				.def(&CollisionShape2D::SetRestitution, "SetRestitution")
				.def(&CollisionShape2D::IsTrigger, "IsTrigger")
				.def(&CollisionShape2D::GetCategoryBits, "GetCategoryBits")
				.def(&CollisionShape2D::GetMaskBits, "GetMaskBits")
				.def(&CollisionShape2D::GetGroupIndex, "GetGroupIndex")
				.def(&CollisionShape2D::GetDensity, "GetDensity")
				.def(&CollisionShape2D::GetFriction, "GetFriction")
				.def(&CollisionShape2D::GetRestitution, "GetRestitution")
				.def(&CollisionShape2D::GetMass, "GetMass")
				.def(&CollisionShape2D::GetInertia, "GetInertia")
				.def(&CollisionShape2D::GetMassCenter, "GetMassCenter")

		];
	}
}
