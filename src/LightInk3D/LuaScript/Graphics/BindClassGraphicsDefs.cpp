

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
#include "Graphics/GraphicsDefs.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_GraphicsDefs(LuaModele & lm)
	{
		lua_pushvalue(lm.state(), LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		 // [Enum] PrimitiveType
		lrf["TRIANGLE_LIST"] = TRIANGLE_LIST;
		lrf["LINE_LIST"] = LINE_LIST;
		lrf["POINT_LIST"] = POINT_LIST;
		lrf["TRIANGLE_STRIP"] = TRIANGLE_STRIP;
		lrf["LINE_STRIP"] = LINE_STRIP;
		lrf["TRIANGLE_FAN"] = TRIANGLE_FAN;

		// [Enum] GeometryType
		lrf["GEOM_STATIC"] = GEOM_STATIC;
		lrf["GEOM_SKINNED"] = GEOM_SKINNED;
		lrf["GEOM_INSTANCED"] = GEOM_INSTANCED;
		lrf["GEOM_BILLBOARD"] = GEOM_BILLBOARD;
		lrf["GEOM_DIRBILLBOARD"] = GEOM_DIRBILLBOARD;
		lrf["GEOM_TRAIL_FACE_CAMERA"] = GEOM_TRAIL_FACE_CAMERA;
		lrf["GEOM_TRAIL_BONE"] = GEOM_TRAIL_BONE;
		lrf["GEOM_STATIC_NOINSTANCING"] = GEOM_STATIC_NOINSTANCING;
		lrf["MAX_GEOMETRYTYPES"] = MAX_GEOMETRYTYPES;

		// [Enum] BlendMode
		lrf["BLEND_REPLACE"] = BLEND_REPLACE;
		lrf["BLEND_ADD"] = BLEND_ADD;
		lrf["BLEND_MULTIPLY"] = BLEND_MULTIPLY;
		lrf["BLEND_ALPHA"] = BLEND_ALPHA;
		lrf["BLEND_ADDALPHA"] = BLEND_ADDALPHA;
		lrf["BLEND_PREMULALPHA"] = BLEND_PREMULALPHA;
		lrf["BLEND_INVDESTALPHA"] = BLEND_INVDESTALPHA;
		lrf["BLEND_SUBTRACT"] = BLEND_SUBTRACT;
		lrf["BLEND_SUBTRACTALPHA"] = BLEND_SUBTRACTALPHA;
		lrf["MAX_BLENDMODES"] = MAX_BLENDMODES;

		// [Enum] CompareMode
		lrf["CMP_ALWAYS"] = CMP_ALWAYS;
		lrf["CMP_EQUAL"] = CMP_EQUAL;
		lrf["CMP_NOTEQUAL"] = CMP_NOTEQUAL;
		lrf["CMP_LESS"] = CMP_LESS;
		lrf["CMP_LESSEQUAL"] = CMP_LESSEQUAL;
		lrf["CMP_GREATER"] = CMP_GREATER;
		lrf["CMP_GREATEREQUAL"] = CMP_GREATEREQUAL;
		lrf["MAX_COMPAREMODES"] = MAX_COMPAREMODES;

		// [Enum] CullMode
		lrf["CULL_NONE"] = CULL_NONE;
		lrf["CULL_CCW"] = CULL_CCW;
		lrf["CULL_CW"] = CULL_CW;
		lrf["MAX_CULLMODES"] = MAX_CULLMODES;

		// [Enum] FillMode
		lrf["FILL_SOLID"] = FILL_SOLID;
		lrf["FILL_WIREFRAME"] = FILL_WIREFRAME;
		lrf["FILL_POINT"] = FILL_POINT;

		// [Enum] StencilOp
		lrf["OP_KEEP"] = OP_KEEP;
		lrf["OP_ZERO"] = OP_ZERO;
		lrf["OP_REF"] = OP_REF;
		lrf["OP_INCR"] = OP_INCR;
		lrf["OP_DECR"] = OP_DECR;

		// [Enum] LockState
		lrf["LOCK_NONE"] = LOCK_NONE;
		lrf["LOCK_HARDWARE"] = LOCK_HARDWARE;
		lrf["LOCK_SHADOW"] = LOCK_SHADOW;
		lrf["LOCK_SCRATCH"] = LOCK_SCRATCH;

		// [Enum] LegacyVertexElement
		lrf["ELEMENT_POSITION"] = ELEMENT_POSITION;
		lrf["ELEMENT_NORMAL"] = ELEMENT_NORMAL;
		lrf["ELEMENT_COLOR"] = ELEMENT_COLOR;
		lrf["ELEMENT_TEXCOORD1"] = ELEMENT_TEXCOORD1;
		lrf["ELEMENT_TEXCOORD2"] = ELEMENT_TEXCOORD2;
		lrf["ELEMENT_CUBETEXCOORD1"] = ELEMENT_CUBETEXCOORD1;
		lrf["ELEMENT_CUBETEXCOORD2"] = ELEMENT_CUBETEXCOORD2;
		lrf["ELEMENT_TANGENT"] = ELEMENT_TANGENT;
		lrf["ELEMENT_BLENDWEIGHTS"] = ELEMENT_BLENDWEIGHTS;
		lrf["ELEMENT_BLENDINDICES"] = ELEMENT_BLENDINDICES;
		lrf["ELEMENT_INSTANCEMATRIX1"] = ELEMENT_INSTANCEMATRIX1;
		lrf["ELEMENT_INSTANCEMATRIX2"] = ELEMENT_INSTANCEMATRIX2;
		lrf["ELEMENT_INSTANCEMATRIX3"] = ELEMENT_INSTANCEMATRIX3;
		lrf["ELEMENT_OBJECTINDEX"] = ELEMENT_OBJECTINDEX;
		lrf["MAX_LEGACY_VERTEX_ELEMENTS"] = MAX_LEGACY_VERTEX_ELEMENTS;

		// [Enum] VertexElementType
		lrf["TYPE_INT"] = TYPE_INT;
		lrf["TYPE_FLOAT"] = TYPE_FLOAT;
		lrf["TYPE_VECTOR2"] = TYPE_VECTOR2;
		lrf["TYPE_VECTOR3"] = TYPE_VECTOR3;
		lrf["TYPE_VECTOR4"] = TYPE_VECTOR4;
		lrf["TYPE_UBYTE4"] = TYPE_UBYTE4;
		lrf["TYPE_UBYTE4_NORM"] = TYPE_UBYTE4_NORM;
		lrf["MAX_VERTEX_ELEMENT_TYPES"] = MAX_VERTEX_ELEMENT_TYPES;

		// [Enum] VertexElementSemantic
		lrf["SEM_POSITION"] = SEM_POSITION;
		lrf["SEM_NORMAL"] = SEM_NORMAL;
		lrf["SEM_BINORMAL"] = SEM_BINORMAL;
		lrf["SEM_TANGENT"] = SEM_TANGENT;
		lrf["SEM_TEXCOORD"] = SEM_TEXCOORD;
		lrf["SEM_COLOR"] = SEM_COLOR;
		lrf["SEM_BLENDWEIGHTS"] = SEM_BLENDWEIGHTS;
		lrf["SEM_BLENDINDICES"] = SEM_BLENDINDICES;
		lrf["SEM_OBJECTINDEX"] = SEM_OBJECTINDEX;
		lrf["MAX_VERTEX_ELEMENT_SEMANTICS"] = MAX_VERTEX_ELEMENT_SEMANTICS;
		
		
		lm
		[
			LuaRegister<VertexElement, void ()>(lm.state(), "VertexElement")
				.def(&VertexElement::operator==, "__eq")
				.def(&VertexElement::type_, "type")
				.def(&VertexElement::semantic_, "semantic")
				.def(&VertexElement::index_, "index")
				.def(&VertexElement::perInstance_, "perInstance")
				.def(&VertexElement::offset_, "offset")
		];
		
		
		// [Enum] TextureFilterMode
		lrf["FILTER_NEAREST"] = FILTER_NEAREST;
		lrf["FILTER_BILINEAR"] = FILTER_BILINEAR;
		lrf["FILTER_TRILINEAR"] = FILTER_TRILINEAR;
		lrf["FILTER_ANISOTROPIC"] = FILTER_ANISOTROPIC;
		lrf["FILTER_DEFAULT"] = FILTER_DEFAULT;
		lrf["MAX_FILTERMODES"] = MAX_FILTERMODES;

		// [Enum] TextureAddressMode
		lrf["ADDRESS_WRAP"] = ADDRESS_WRAP;
		lrf["ADDRESS_MIRROR"] = ADDRESS_MIRROR;
		lrf["ADDRESS_CLAMP"] = ADDRESS_CLAMP;
		lrf["ADDRESS_BORDER"] = ADDRESS_BORDER;
		lrf["MAX_ADDRESSMODES"] = MAX_ADDRESSMODES;

		// [Enum] TextureCoordinate
		lrf["COORD_U"] = COORD_U;
		lrf["COORD_V"] = COORD_V;
		lrf["COORD_W"] = COORD_W;
		lrf["MAX_COORDS"] = MAX_COORDS;

		// [Enum] TextureUsage
		lrf["TEXTURE_STATIC"] = TEXTURE_STATIC;
		lrf["TEXTURE_DYNAMIC"] = TEXTURE_DYNAMIC;
		lrf["TEXTURE_RENDERTARGET"] = TEXTURE_RENDERTARGET;
		lrf["TEXTURE_DEPTHSTENCIL"] = TEXTURE_DEPTHSTENCIL;

		// [Enum] CubeMapFace
		lrf["FACE_POSITIVE_X"] = FACE_POSITIVE_X;
		lrf["FACE_NEGATIVE_X"] = FACE_NEGATIVE_X;
		lrf["FACE_POSITIVE_Y"] = FACE_POSITIVE_Y;
		lrf["FACE_NEGATIVE_Y"] = FACE_NEGATIVE_Y;
		lrf["FACE_POSITIVE_Z"] = FACE_POSITIVE_Z;
		lrf["FACE_NEGATIVE_Z"] = FACE_NEGATIVE_Z;
		lrf["MAX_CUBEMAP_FACES"] = MAX_CUBEMAP_FACES;

		// [Enum] CubeMapLayout
		lrf["CML_HORIZONTAL"] = CML_HORIZONTAL;
		lrf["CML_HORIZONTALNVIDIA"] = CML_HORIZONTALNVIDIA;
		lrf["CML_HORIZONTALCROSS"] = CML_HORIZONTALCROSS;
		lrf["CML_VERTICALCROSS"] = CML_VERTICALCROSS;
		lrf["CML_BLENDER"] = CML_BLENDER;

		// [Enum] RenderSurfaceUpdateMode
		lrf["SURFACE_MANUALUPDATE"] = SURFACE_MANUALUPDATE;
		lrf["SURFACE_UPDATEVISIBLE"] = SURFACE_UPDATEVISIBLE;
		lrf["SURFACE_UPDATEALWAYS"] = SURFACE_UPDATEALWAYS;

		// [Enum] ShaderType
		lrf["VS"] = VS;
		lrf["PS"] = PS;

		// [Enum] TextureUnit
		lrf["TU_DIFFUSE"] = TU_DIFFUSE;
		lrf["TU_ALBEDOBUFFER"] = TU_ALBEDOBUFFER;
		lrf["TU_NORMAL"] = TU_NORMAL;
		lrf["TU_NORMALBUFFER"] = TU_NORMALBUFFER;
		lrf["TU_SPECULAR"] = TU_SPECULAR;
		lrf["TU_EMISSIVE"] = TU_EMISSIVE;
		lrf["TU_ENVIRONMENT"] = TU_ENVIRONMENT;
			
		// lrf["TU_VOLUMEMAP"] = TU_VOLUMEMAP;
		// lrf["TU_CUSTOM1"] = TU_CUSTOM1;
		// lrf["TU_CUSTOM2"] = TU_CUSTOM2;
		// lrf["TU_LIGHTRAMP"] = TU_LIGHTRAMP;
		// lrf["TU_LIGHTSHAPE"] = TU_LIGHTSHAPE;
		// lrf["TU_SHADOWMAP"] = TU_SHADOWMAP;
		// lrf["TU_FACESELECT"] = TU_FACESELECT;
		// lrf["TU_INDIRECTION"] = TU_INDIRECTION;
		// lrf["TU_DEPTHBUFFER"] = TU_DEPTHBUFFER;
		// lrf["TU_LIGHTBUFFER"] = TU_LIGHTBUFFER;
		// lrf["TU_ZONE"] = TU_ZONE;
		// lrf["MAX_MATERIAL_TEXTURE_UNITS"] = MAX_MATERIAL_TEXTURE_UNITS;
		// lrf["MAX_TEXTURE_UNITS"] = MAX_TEXTURE_UNITS;

		// [Enum] FaceCameraMode
		lrf["FC_NONE"] = FC_NONE;
		lrf["FC_ROTATE_XYZ"] = FC_ROTATE_XYZ;
		lrf["FC_ROTATE_Y"] = FC_ROTATE_Y;
		lrf["FC_LOOKAT_XYZ"] = FC_LOOKAT_XYZ;
		lrf["FC_LOOKAT_Y"] = FC_LOOKAT_Y;
		lrf["FC_DIRECTION"] = FC_DIRECTION;

		// [Enum] ShadowQuality
		lrf["SHADOWQUALITY_SIMPLE_16BIT"] = SHADOWQUALITY_SIMPLE_16BIT;
		lrf["SHADOWQUALITY_SIMPLE_24BIT"] = SHADOWQUALITY_SIMPLE_24BIT;
		lrf["SHADOWQUALITY_PCF_16BIT"] = SHADOWQUALITY_PCF_16BIT;
		lrf["SHADOWQUALITY_PCF_24BIT"] = SHADOWQUALITY_PCF_24BIT;
		lrf["SHADOWQUALITY_VSM"] = SHADOWQUALITY_VSM;
		lrf["SHADOWQUALITY_BLUR_VSM"] = SHADOWQUALITY_BLUR_VSM;

		// [Constant] int QUALITY_LOW
		lrf["QUALITY_LOW"] = QUALITY_LOW;
		// [Constant] int QUALITY_MEDIUM
		lrf["QUALITY_MEDIUM"] = QUALITY_MEDIUM;
		// [Constant] int QUALITY_HIGH
		lrf["QUALITY_HIGH"] = QUALITY_HIGH;
		// [Constant] int QUALITY_MAX
		lrf["QUALITY_MAX"] = QUALITY_MAX;

		// [Constant] unsigned CLEAR_COLOR
		lrf["CLEAR_COLOR"] = CLEAR_COLOR;
		// [Constant] unsigned CLEAR_DEPTH
		lrf["CLEAR_DEPTH"] = CLEAR_DEPTH;
		// [Constant] unsigned CLEAR_STENCIL
		lrf["CLEAR_STENCIL"] = CLEAR_STENCIL;

		// [Constant] unsigned MASK_NONE
		lrf["MASK_NONE"] = MASK_NONE;
		// [Constant] unsigned MASK_POSITION
		lrf["MASK_POSITION"] = MASK_POSITION;
		// [Constant] unsigned MASK_NORMAL
		lrf["MASK_NORMAL"] = MASK_NORMAL;
		// [Constant] unsigned MASK_COLOR
		lrf["MASK_COLOR"] = MASK_COLOR;
		// [Constant] unsigned MASK_TEXCOORD1
		lrf["MASK_TEXCOORD1"] = MASK_TEXCOORD1;
		// [Constant] unsigned MASK_TEXCOORD2
		lrf["MASK_TEXCOORD2"] = MASK_TEXCOORD2;
		// [Constant] unsigned MASK_CUBETEXCOORD1
		lrf["MASK_CUBETEXCOORD1"] = MASK_CUBETEXCOORD1;
		// [Constant] unsigned MASK_CUBETEXCOORD2
		lrf["MASK_CUBETEXCOORD2"] = MASK_CUBETEXCOORD2;
		// [Constant] unsigned MASK_TANGENT
		lrf["MASK_TANGENT"] = MASK_TANGENT;
		// [Constant] unsigned MASK_BLENDWEIGHTS
		lrf["MASK_BLENDWEIGHTS"] = MASK_BLENDWEIGHTS;
		// [Constant] unsigned MASK_BLENDINDICES
		lrf["MASK_BLENDINDICES"] = MASK_BLENDINDICES;
		// [Constant] unsigned MASK_INSTANCEMATRIX1
		lrf["MASK_INSTANCEMATRIX1"] = MASK_INSTANCEMATRIX1;
		// [Constant] unsigned MASK_INSTANCEMATRIX2
		lrf["MASK_INSTANCEMATRIX2"] = MASK_INSTANCEMATRIX2;
		// [Constant] unsigned MASK_INSTANCEMATRIX3
		lrf["MASK_INSTANCEMATRIX3"] = MASK_INSTANCEMATRIX3;
		// [Constant] unsigned MASK_OBJECTINDEX
		lrf["MASK_OBJECTINDEX"] = MASK_OBJECTINDEX;
	}
}

