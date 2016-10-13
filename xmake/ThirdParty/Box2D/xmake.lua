



if is_option("LightInk3D2D") then
	local name = "Box2D"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	-- add headers
	add_headers(prefixInclude .. "/**.h", prefixInclude .. "/**.hpp")

		
	-- add files
	add_files(prefixSrc .. "/**.cpp", prefixSrc .. "/**.c")

end
