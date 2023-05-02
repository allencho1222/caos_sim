#include <fmt/format.h>
#include <gtest/gtest.h>

#include "nand_flash_memory/Package.h"

int main(int argc, char** argv) {
  fmt::print("HELLO test {} {}\n", 1, 3);
  ::testing::InitGoogleTest(&argc, argv);
  // For testing compilation
  auto flashMem = std::make_unique<FlashMemory>(4, 4, 4, 4, 4);
  return 0;
}
