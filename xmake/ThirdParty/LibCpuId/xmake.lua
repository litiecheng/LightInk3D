
if not is_plat("linux") then

	local name = "LibCpuId"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	add_links("advapi32")
	
	add_includedirs(prefixInclude)
	
	-- add headers
	add_headers(prefixInclude .. "/*.h")

		
	-- add files
	add_files(prefixSrc .. "/*.c")



end
