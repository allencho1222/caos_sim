project(nand_flash_memory)

# Load required packages
# find_package(fmt REQUIRED)
# find_package(spdlog REQUIRED)
# find_package(yaml-cpp REQUIRED)
# find_package(cxxopts REQUIRED)
# find_package(unordered_dense REQUIRED)

set(NAND_FLASH_MEMORY_SRC_FILES
 Package.cpp
 NANDFlashCommand.cpp
) 
add_library(nand_flash_memory ${NAND_FLASH_MEMORY_SRC_FILES})
# target_include_directories(ssdsim)
# target_link_libraries(ssdsim
#   fmt::fmt
#   spdlog::spdlog
#   yaml-cpp
#   cxxopts
#   unordered_dense
# )
target_compile_options(nand_flash_memory PRIVATE -Wall -O3 -g)
