

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

#include "../Precompiled.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_Drawable2D(LuaModele & lm); 
	extern void bind_class_StaticSprite2D(LuaModele & lm);
	extern void bind_class_CollisionShape2D(LuaModele & lm);
	extern void bind_class_Constraint2D(LuaModele & lm);
	extern void bind_class_AnimatedSprite2D(LuaModele & lm);
	extern void bind_class_AnimationSet2D(LuaModele & lm);
	extern void bind_class_CollisionBox2D(LuaModele & lm);
	extern void bind_class_CollisionChain2D(LuaModele & lm);
	extern void bind_class_CollisionCircle2D(LuaModele & lm);
	extern void bind_class_CollisionEdge2D(LuaModele & lm);
	extern void bind_class_CollisionPolygon2D(LuaModele & lm);
	extern void bind_class_ConstraintDistance2D(LuaModele & lm);
	extern void bind_class_ConstraintFriction2D(LuaModele & lm);
	extern void bind_class_ConstraintGear2D(LuaModele & lm);
	extern void bind_class_ConstraintMotor2D(LuaModele & lm);
	extern void bind_class_ConstraintMouse2D(LuaModele & lm);
	extern void bind_class_ConstraintPrismatic2D(LuaModele & lm);
	extern void bind_class_ConstraintPulley2D(LuaModele & lm);
	extern void bind_class_ConstraintRevolute2D(LuaModele & lm);
	extern void bind_class_ConstraintRope2D(LuaModele & lm);
	extern void bind_class_ConstraintWeld2D(LuaModele & lm);
	extern void bind_class_ConstraintWheel2D(LuaModele & lm);
	extern void bind_class_ParticleEffect2D(LuaModele & lm);
	extern void bind_class_ParticleEmitter2D(LuaModele & lm);
	extern void bind_class_PhysicsWorld2D(LuaModele & lm);
	extern void bind_class_RigidBody2D(LuaModele & lm);
	extern void bind_class_Sprite2D(LuaModele & lm);
	extern void bind_class_SpriteSheet2D(LuaModele & lm);
	extern void bind_class_TileMap2D(LuaModele & lm);
	extern void bind_class_TileMapDefs2D(LuaModele & lm);
	extern void bind_class_TileMapLayer2D(LuaModele & lm);
	extern void bind_class_TmxFile2D(LuaModele & lm);
	

	void bind_urho2d_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModele lm(lua, "LightInk3D__", lrf);
		
		bind_class_Drawable2D(lm); 
		bind_class_StaticSprite2D(lm);
		bind_class_CollisionShape2D(lm);
		bind_class_Constraint2D(lm);

		bind_class_AnimatedSprite2D(lm);
		bind_class_AnimationSet2D(lm);
		bind_class_CollisionBox2D(lm);
		bind_class_CollisionChain2D(lm);
		bind_class_CollisionCircle2D(lm);
		bind_class_CollisionEdge2D(lm);
		bind_class_CollisionPolygon2D(lm);
		bind_class_ConstraintDistance2D(lm);
		bind_class_ConstraintFriction2D(lm);
		bind_class_ConstraintGear2D(lm);
		bind_class_ConstraintMotor2D(lm);
		bind_class_ConstraintMouse2D(lm);
		bind_class_ConstraintPrismatic2D(lm);
		bind_class_ConstraintPulley2D(lm);
		bind_class_ConstraintRevolute2D(lm);
		bind_class_ConstraintRope2D(lm);
		bind_class_ConstraintWeld2D(lm);
		bind_class_ConstraintWheel2D(lm);
		bind_class_ParticleEffect2D(lm);
		bind_class_ParticleEmitter2D(lm);
		bind_class_PhysicsWorld2D(lm);
		bind_class_RigidBody2D(lm);
		bind_class_Sprite2D(lm);
		bind_class_SpriteSheet2D(lm);
		bind_class_TileMap2D(lm);
		bind_class_TileMapDefs2D(lm);
		bind_class_TileMapLayer2D(lm);
		bind_class_TmxFile2D(lm);
		
		// [Enum] LoopMode2D
		lrf["LM_DEFAULT"] = LM_DEFAULT;
		lrf["LM_FORCE_LOOPED"] = LM_FORCE_LOOPED;
		lrf["LM_FORCE_CLAMPED"] = LM_FORCE_CLAMPED;
		

}

