

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
#include "Scene/Node.h"
#include "Scene/SplinePath.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_SplinePath(LuaModele & lm)
	{
		lm
		[
			LuaRegister<SplinePath, void ()>(lm.state(), "SplinePath", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<SplinePath>, "new")
				.def(&SplinePath::AddControlPoint, "AddControlPoint")
				.def(&SplinePath::RemoveControlPoint, "RemoveControlPoint")
				.def(&SplinePath::ClearControlPoints, "ClearControlPoints")
				.def(&SplinePath::SetInterpolationMode, "SetInterpolationMode")
				.def(&SplinePath::SetSpeed, "SetSpeed")
				.def(&SplinePath::SetPosition, "SetPosition")
				.def(&SplinePath::SetControlledNode, "SetControlledNode")
				.def(&SplinePath::GetInterpolationMode, "GetInterpolationMode")
				.def(&SplinePath::GetSpeed, "GetSpeed")
				.def(&SplinePath::GetLength, "GetLength")
				.def(&SplinePath::GetPosition, "GetPosition")
				.def(&SplinePath::GetPoint, "GetPoint")
				.def(&SplinePath::Move, "Move")
				.def(&SplinePath::Reset, "Reset")
				.def(&SplinePath::IsFinished, "IsFinished")
			
		];
	}
}
