cmake_minimum_required(VERSION 3.3) # setting this is required
project(RayTracing)            # this sets the project name

set(CMAKE_CXX_STANDARD 14)


###############################################################################
## target definitions #########################################################
###############################################################################

# The data is just added to the executable, because in some IDEs (QtCreator) 
# files are invisible when they are not explicitly part of the project.
file(GLOB_RECURSE sources    src/*.cpp src/*.h)
file(GLOB_RECURSE data resources/*)

add_executable(raytracing main.cpp ${sources} ${data})
target_include_directories(raytracing PRIVATE "src")

# Just for example add some compiler flags.
target_compile_options(raytracing PUBLIC -O2 -Wall -Wfloat-conversion)

find_package(Boost 1.80 ) #REQUIRED COMPONENTS
             #functional filesystem iostreams


if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

target_link_libraries(raytracing )


enable_testing()
add_subdirectory( tests)

