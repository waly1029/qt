# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/FileClean_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/FileClean_autogen.dir/ParseCache.txt"
  "FileClean_autogen"
  )
endif()
