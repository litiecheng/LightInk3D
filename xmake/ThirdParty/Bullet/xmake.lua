
local name = "Bullet"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DPHYSICS") then
		
		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)
		add_includedirs(prefixInclude .. "/BulletCollision/BroadphaseCollision/")
		add_includedirs(prefixInclude .. "/BulletCollision/CollisionDispatch/")
		add_includedirs(prefixInclude .. "/BulletCollision/CollisionShapes/")
		add_includedirs(prefixInclude .. "/BulletCollision/Gimpact/")
		add_includedirs(prefixInclude .. "/BulletCollision/NarrowPhaseCollision/")
		add_includedirs(prefixInclude .. "/BulletDynamics/Character/")
		add_includedirs(prefixInclude .. "/BulletDynamics/ConstraintSolver/")
		add_includedirs(prefixInclude .. "/BulletDynamics/Dynamics/")
		add_includedirs(prefixInclude .. "/BulletDynamics/Featherstone/")
		add_includedirs(prefixInclude .. "/BulletDynamics/MLCPSolvers/")
		add_includedirs(prefixInclude .. "/BulletDynamics/Vehicle/")
		add_includedirs(prefixInclude .. "/BulletSoftBody/")
		add_includedirs(prefixInclude .. "/LinearMath/")

		-- add headers
		add_headers(prefixInclude .. "/**.h", prefixInclude .. "/**.hpp")

			
		-- add files
		add_files(prefixSrc .. "/**.cpp")
		
	end

end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DPHYSICS") then
		
		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)
		add_includedirs(prefixInclude .. "/BulletCollision/BroadphaseCollision/")
		add_includedirs(prefixInclude .. "/BulletCollision/CollisionDispatch/")
		add_includedirs(prefixInclude .. "/BulletCollision/CollisionShapes/")
		add_includedirs(prefixInclude .. "/BulletCollision/Gimpact/")
		add_includedirs(prefixInclude .. "/BulletCollision/NarrowPhaseCollision/")
		add_includedirs(prefixInclude .. "/BulletDynamics/Character/")
		add_includedirs(prefixInclude .. "/BulletDynamics/ConstraintSolver/")
		add_includedirs(prefixInclude .. "/BulletDynamics/Dynamics/")
		add_includedirs(prefixInclude .. "/BulletDynamics/Featherstone/")
		add_includedirs(prefixInclude .. "/BulletDynamics/MLCPSolvers/")
		add_includedirs(prefixInclude .. "/BulletDynamics/Vehicle/")
		add_includedirs(prefixInclude .. "/BulletSoftBody/")
		add_includedirs(prefixInclude .. "/LinearMath/")
		
	end

end
end
	

