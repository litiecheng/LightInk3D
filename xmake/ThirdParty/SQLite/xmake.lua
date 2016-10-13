
if is_option("LightInk3DSQLite") then

	local name = "SQLite"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name
	
	add_defines("SQLITE_USE_URI=1",
				"SQLITE_ENABLE_COLUMN_METADATA",
				"SQLITE_SOUNDEX")

	add_includedirs(prefixInclude)

	-- add headers
	add_headers(prefixInclude .. "/*.h")

		
	-- add files
	add_files(prefixSrc .. "/*.c")



end