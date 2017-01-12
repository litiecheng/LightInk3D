

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


#include "../../Precompiled.h"
#include "../../Math/Plane.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Plane(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Plane, void ()>(lm.state(), "Plane")
				.def(static_cast<void(Plane::*)(const Vector3&, const Vector3&, const Vector3&)>(&Plane::Define), "DefineVVV")
				.def(static_cast<void(Plane::*)(const Vector3&, const Vector3&)>(&Plane::Define), "DefineVV")
				.def(static_cast<void(Plane::*)(const Vector4&)>(&Plane::Define), "DefineV4")
				.def(static_cast<void(Plane::*)(const Matrix3&)>(&Plane::Transform), "TransformM3")
				.def(static_cast<void(Plane::*)(const Matrix3x4&)>(&Plane::Transform), "TransformM3x4")
				.def(static_cast<void(Plane::*)(const Matrix4&)>(&Plane::Transform), "TransformM4")
				.def(&Plane::Project, "Project")
				.def(&Plane::Distance, "Distance")
				.def(&Plane::Reflect, "Reflect")
				.def(&Plane::ReflectionMatrix, "ReflectionMatrix")
				.def(static_cast<Plane(Plane::*)(const Matrix3&) const>(&Plane::Transformed), "TransformedM3")
				.def(static_cast<Plane(Plane::*)(const Matrix3x4&) const>(&Plane::Transformed), "TransformedM3x4")
				.def(static_cast<Plane(Plane::*)(const Matrix4&) const>(&Plane::Transformed), "TransformedM4")
				.def(&Plane::ToVector4, "ToVector4")
				.def(&Plane::normal_, "normal")
				.def(&Plane::absNormal_, "absNormal")
				.def(&Plane::d_, "d")
				.def(&Plane::UP, "UP")
		];
	}
}

