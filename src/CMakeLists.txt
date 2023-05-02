project(ssdsim_main)

# Load required packages
find_package(fmt REQUIRED)
# find_package(spdlog REQUIRED)
# find_package(yaml-cpp REQUIRED)
# find_package(cxxopts REQUIRED)
# find_package(unordered_dense REQUIRED)

add_subdirectory(nand_flash_memory)

set(SRC_FILES main.cpp)

add_executable(ssdsim ${SRC_FILES})

# target_include_directories(ssdsim)
target_link_libraries(ssdsim
  nand_flash_memory
  fmt::fmt
  # spdlog::spdlog
  # yaml-cpp
  # cxxopts
  # unordered_dense
)
target_compile_options(ssdsim PRIVATE -Wall -O3 -g)
install(TARGETS ssdsim DESTINATION ./bin)
