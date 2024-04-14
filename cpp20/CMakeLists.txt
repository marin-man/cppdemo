cmake_minimum_required(VERSION 3.21) # at least 3.20 version is needed
project(cpp20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts") # this line make sure
# to enable modules

add_subdirectory(concept)
add_subdirectory(ranges)
add_subdirectory(coroutine)
add_subdirectory(attribute)
add_subdirectory(span)
add_subdirectory(format)

# add_executable(${PROJECT_NAME} src/main.cpp)

# target_sources(${PROJECT_NAME} PUBLIC FILE_SET cxx_modules TYPE HEADERS FILES
# include/mymodule.h)

# target_compile_options( ${PROJECT_NAME} PRIVATE
# "-fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/mymodule.pcm")

# set_target_properties( ${PROJECT_NAME} PROPERTIES CXX_LINK_EXECUTABLE
# "${CMAKE_CXX_LINK_EXECUm
