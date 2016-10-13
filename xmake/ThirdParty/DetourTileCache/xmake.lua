
if is_option("LightInk3DNAVIGATION") then

	local name = "DetourTileCache"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	add_includedirs(prefixInclude)

	-- add headers
	add_headers(prefixInclude .. "/**.h", prefixInclude .. "/**.hpp")

		
	-- add files
	add_files(prefixSrc .. "/**.cpp", prefixSrc .. "/**.c")



end

