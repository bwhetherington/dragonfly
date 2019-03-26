cmake_minimum_required (VERSION 3.6)
project (Dragonfly)

# Set version number
set (Dragonfly_VERSION_MAJOR 1)
set (Dragonfly_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "src/DragonflyConfig.hpp.in"
  "bin/DragonflyConfig.hpp"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("bin")

# use sfml
set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

set(Dragonfly_SRC
    "src/main.hpp"
    "src/main.cpp"
    "src/manager/Manager.hpp"
    "src/manager/Manager.cpp"
    "src/manager/LogManager.hpp"
    "src/manager/LogManager.cpp"
    "src/manager/GameManager.hpp"
    "src/manager/GameManager.cpp"
    "src/util/Clock.hpp"
    "src/util/Clock.cpp"
    "src/util/time.hpp"
    "src/util/time.cpp"
    "src/util/sleep.hpp"
    "src/util/sleep.cpp"
    "src/math/Vec2.hpp"
    "src/math/Vec2.cpp"
)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Check if we're on Linux
if(UNIX AND NOT APPLE)
  set(LINUX TRUE)
endif()

# Add -lrt if we're on Linux
if(LINUX)
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -lrt)
endif()

# Use C++11
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x")

add_executable(Dragonfly ${Dragonfly_SRC})
target_link_libraries(Dragonfly sfml-graphics sfml-audio)