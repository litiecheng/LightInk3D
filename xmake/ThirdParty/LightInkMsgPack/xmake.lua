
if is_option("LightInk3DNETWORK") then

	local name = "LightInkMsgPack"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	add_includedirs(prefixInclude)

	-- add headers
	add_headers(prefixInclude .. "/Msgpack/**.h", 
				prefixInclude .. "/Msgpack/*.cpp")

		
	-- add files
	add_files(prefixSrc .. "/Msgpack/**.cpp")



end