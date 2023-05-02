project(ssdsim_main)

# Load required packages
find_package(fmt REQUIRED)
find_package(cxxopts REQUIRED)

add_subdirectory(nand_flash_memory)

set(SRC_FILES main.cpp)

add_executable(ssdsim ${SRC_FILES})

target_link_libraries(ssdsim
  cxxopts::cxxopts
  fmt::fmt
  nand_flash_memory
)
target_compile_options(ssdsim PRIVATE -Wall -O3 -g)
install(TARGETS ssdsim DESTINATION ./bin)
