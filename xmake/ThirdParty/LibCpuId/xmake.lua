
if is_plat("linux") then

	local name = "LibCpuId"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name



	-- add headers
	add_headers(prefixInclude .. "/*.h")

		
	-- add files
	add_files(prefixSrc .. "*.c", prefixSrc .. "*.asm")



end
