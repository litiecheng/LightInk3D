

if is_plat("windows") and is_option("LightInk3DDX9") then

	local name = "MojoShader"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	add_includedirs(prefixInclude)
	
	add_defines("_CRT_SECURE_NO_WARNINGS=1")

	-- add headers
	add_headers(prefixInclude .. "/*.h")

		
	-- add files
	add_files(prefixSrc .. "/*.cpp")



end