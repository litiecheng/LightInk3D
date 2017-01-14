

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
#include "Math/BoundingBox.h"
#include "Math/Frustum.h"
#include "Math/Polyhedron.h"
#include "Math/Sphere.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_BoundingBox(LuaModele & lm)
	{
		lm
		[
			LuaRegister<BoundingBox, void (const Vector3&, const Vector3&)>(lm.state(), "BoundingBox")
				.def(&BoundingBox::operator==, "__eq")
				.def(static_cast<void(BoundingBox::*)(const BoundingBox&)>(&BoundingBox::Define), "DefineB")
				.def(static_cast<void(BoundingBox::*)(const Rect&)>(&BoundingBox::Define), "DefineR")
				.def(static_cast<void(BoundingBox::*)(const Vector3&, const Vector3&)>(&BoundingBox::Define), "DefineVV")
				.def(static_cast<void(BoundingBox::*)(float, float)>(&BoundingBox::Define), "DefineFF")
				.def(static_cast<void(BoundingBox::*)(const Vector3&)>(&BoundingBox::Define), "DefineV")
				.def(static_cast<void(BoundingBox::*)(const Frustum&)>(&BoundingBox::Define), "DefineF")
				.def(static_cast<void(BoundingBox::*)(const Polyhedron&)>(&BoundingBox::Define), "DefineP")
				.def(static_cast<void(BoundingBox::*)(const Sphere&)>(&BoundingBox::Define), "DefineS")
				.def(static_cast<void(BoundingBox::*)(const Vector3&)>(&BoundingBox::Merge), "MergeV")
				.def(static_cast<void(BoundingBox::*)(const BoundingBox&)>(&BoundingBox::Merge), "MergeB")
				.def(static_cast<void(BoundingBox::*)(const Frustum&)>(&BoundingBox::Merge), "MergeF")
				.def(static_cast<void(BoundingBox::*)(const Polyhedron&)>(&BoundingBox::Merge), "MergeP")
				.def(static_cast<void(BoundingBox::*)(const Sphere&)>(&BoundingBox::Merge), "MergeS")
				.def(&BoundingBox::Clip, "Clip")
				.def(static_cast<void(BoundingBox::*)(const Matrix3&)>(&BoundingBox::Transform), "TransformM3")
				.def(static_cast<void(BoundingBox::*)(const Matrix3x4&)>(&BoundingBox::Transform), "TransformM3x4")
				.def(&BoundingBox::Clear, "Clear")
				.def(&BoundingBox::Defined, "Defined")
				.def(&BoundingBox::Center, "Center")
				.def(&BoundingBox::Size, "Size")
				.def(&BoundingBox::HalfSize, "HalfSize")
				.def(static_cast<BoundingBox(BoundingBox::*)(const Matrix3&) const>(&BoundingBox::Transformed), "TransformedM3")
				.def(static_cast<BoundingBox(BoundingBox::*)(const Matrix3x4&) const>(&BoundingBox::Transformed), "TransformedM3x4")
				.def(&BoundingBox::Projected, "Projected")
				.def(static_cast<Intersection(BoundingBox::*)(const Vector3&) const>(&BoundingBox::IsInside), "IsInsideV")
				.def(static_cast<Intersection(BoundingBox::*)(const BoundingBox&) const>(&BoundingBox::IsInside), "IsInsideB")
				.def(static_cast<Intersection(BoundingBox::*)(const Sphere&) const>(&BoundingBox::IsInside), "IsInsideS")
				.def(static_cast<Intersection(BoundingBox::*)(const BoundingBox&) const>(&BoundingBox::IsInsideFast), "IsInsideFastB")
				.def(static_cast<Intersection(BoundingBox::*)(const Sphere&) const>(&BoundingBox::IsInsideFast), "IsInsideFastS")
				.def(&BoundingBox::ToString, "ToString")
				.def(&BoundingBox::min_, "min")
				.def(&BoundingBox::max_, "max")
		];
	}
}

