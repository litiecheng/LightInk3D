

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
#include "Math/Frustum.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Frustum(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Frustum, void ()>(lm.state(), "Frustum")
				.def(static_cast<void(Frustum::*)(float, float, float, float, float, const Matrix3x4&)>(&Frustum::Define), "Define5FM3x4")
				.def(static_cast<void(Frustum::*)(const Vector3&, const Vector3&, const Matrix3x4&)>(&Frustum::Define), "DefineVVM3x4")
				.def(static_cast<void(Frustum::*)(const BoundingBox&, const Matrix3x4&)>(&Frustum::Define), "DefineBM3x4")
				.def(&Frustum::DefineOrtho, "DefineOrtho")
				.def(static_cast<void(Frustum::*)(const Matrix3&)>(&Frustum::Transform), "TransformM3")
				.def(static_cast<void(Frustum::*)(const Matrix3x4&)>(&Frustum::Transform), "TransformM3x4")
				.def(static_cast<Intersection(Frustum::*)(const Vector3&) const>(&Frustum::IsInside), "IsInsideV")
				.def(static_cast<Intersection(Frustum::*)(const Sphere&) const>(&Frustum::IsInside), "IsInsideS")
				.def(static_cast<Intersection(Frustum::*)(const BoundingBox&) const>(&Frustum::IsInside), "IsInsideB")
				.def(static_cast<Intersection(Frustum::*)(const Sphere&) const>(&Frustum::IsInsideFast), "IsInsideFastS")
				.def(static_cast<Intersection(Frustum::*)(const BoundingBox&) const>(&Frustum::IsInsideFast), "IsInsideFastB")
				.def(&Frustum::Distance, "Distance")
				.def(static_cast<Frustum(Frustum::*)(const Matrix3&) const>(&Frustum::Transformed), "TransformedM3")
				.def(static_cast<Frustum(Frustum::*)(const Matrix3x4&) const>(&Frustum::Transformed), "TransformedM3x4")
				.def(&Frustum::Projected, "Projected")
				.def(&Frustum::UpdatePlanes, "UpdatePlanes")
		];
	}
}

