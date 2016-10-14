
if is_option("LightInk3DOPENGL") then

	local name = "GLEW"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	add_includedirs(prefixInclude)

	add_links("opengl32")
	
	-- add headers
	add_headers(prefixInclude .. "/**.h", prefixInclude .. "/**.hpp")

		
	-- add files
	add_files(prefixSrc .. "/**.c")



end

