project(ssdsim_test)

# will use google test to build test binaries
find_package(GTest REQUIRED)
find_package(fmt REQUIRED)

set(TEST_SRC_FILES main.cpp)

add_executable(ssdsim_test ${TEST_SRC_FILES})

target_include_directories(ssdsim_test PRIVATE ${INCLUDE_DIRS})
target_link_libraries(ssdsim_test
  gtest::gtest
  fmt::fmt
  nand_flash_memory
)
target_compile_options(ssdsim_test PRIVATE -Wall -O3)
install(TARGETS ssdsim_test DESTINATION ./bin)
