

if is_option("LightInk3DNAVIGATION") then

	local name = "Recast"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	add_includedirs(prefixInclude)

	-- add headers
	add_headers(prefixInclude .. "/*.h")

		
	-- add files
	add_files(prefixSrc .. "/*.cpp")



end