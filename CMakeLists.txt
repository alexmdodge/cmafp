cmake_minimum_required(VERSION 3.20.2)

# media file data
project(CmafParser)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# define path variables
set(SOURCE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE_READER ${SOURCE_ROOT}/reader)
set(SOURCE_HELPERS ${SOURCE_ROOT}/helpers)
set(SOURCE_PARSER ${SOURCE_ROOT}/parser)
set(SOURCE_BOXES ${SOURCE_ROOT}/boxes)

# collect library files
file(GLOB CP_SOURCES
  ${SOURCE_READER}/*.cpp
  ${SOURCE_HELPERS}/*.cpp
  ${SOURCE_PARSER}/*.cpp
  ${SOURCE_BOXES}/*.cpp
)

# local project includes
set(CP_INCLUDE_DIRS
  ${SOURCE_READER}
  ${SOURCE_HELPERS}
  ${SOURCE_PARSER}
  ${SOURCE_BOXES}
)

# external library source includes
#set(LIBS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/libs)
#set(LIBS_EXT_LIB ${LIBS_ROOT}/<LIB_DIRNAME>)

#set(CP_EXTERNAL_DIRS
#  ${LIBS_EXT_LIB}/includes
#)

#set(CP_EXTERNAL_LIBS
#  ${LIBS_EXT_LIB}/lib.a
#)

if(EMSCRIPTEN)
    message("\nEMSCRIPTEN DEFINED\n")
else()
    message("\nEMSCRIPTEN N/A\n")
endif()

# mfp library modules and header includes
add_library(cmafp STATIC ${CP_SOURCES})
target_include_directories(cmafp PUBLIC ${CP_INCLUDE_DIRS})
#target_include_directories(cmafp PUBLIC ${CP_EXTERNAL_DIRS})

# link external libraries
#target_link_libraries(cmafp ${CP_EXTERNAL_LIBS})

# executable linking if desired
#add_executable(CmafParser src/Main.cpp)
#target_link_libraries(CmafParser cmafp)
