

local name = "SQLite"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DSQLite") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name
		
		add_defines("SQLITE_USE_URI=1",
					"SQLITE_ENABLE_COLUMN_METADATA",
					"SQLITE_SOUNDEX")

		add_includedirs(prefixInclude)

		-- add headers
		add_headers(prefixInclude .. "/*.h")

			
		-- add files
		add_files(prefixSrc .. "/*.c")



	end

end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DSQLite") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name
		
		add_defines("SQLITE_USE_URI=1",
					"SQLITE_ENABLE_COLUMN_METADATA",
					"SQLITE_SOUNDEX")

		add_includedirs(prefixInclude)



	end

end
end