cmake_minimum_required(VERSION 3.0.0)
project(efmsoft_libs_usage VERSION 1.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  

if (CMAKE_BUILD_TYPE STREQUAL "")
  message(STATUS "  Diag: Build type was unspecified, set to Release")
  set(CMAKE_BUILD_TYPE Release)
else ()
  message(STATUS "  Diag: Build type specified as '${CMAKE_BUILD_TYPE}'")
endif ()

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
  set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "_DEBUG")
endif ()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/Modules/allstat/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/Modules/logme/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/Modules/syncme/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/Modules/utf8/cmake)

# Bind logme to allstat
# Bind syncme to logme and allstat
add_compile_definitions(
  USE_ALLSTAT
  USE_LOGME
  _LOGME_STATIC_BUILD_
  _SINCME_STATIC_BUILD_
)

find_package(OpenSSL REQUIRED)

find_package(allstat MODULE)
find_package(logme MODULE)
find_package(syncme MODULE)
find_package(utf8 MODULE)

add_subdirectory(Example)
