

if is_option("LightInk3DPHYSICS") then
	local name = "Bullet"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

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



	

