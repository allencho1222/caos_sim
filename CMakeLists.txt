cmake_minimum_required(VERSION 3.25)
project(ssdsim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# print SPDLOG_TRACE
#add_definitions(-DSPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE)

# Build ssdsim binary
add_subdirectory(src)
# Build test binaries
add_subdirectory(test)
