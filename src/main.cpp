#include <memory>
#include <fmt/format.h>
#include "nand_flash_memory/Package.h"

int main(void) {
  fmt::print("I'm main\n");
  int numPkgs = 4;
  int numDies = 4;
  int numPlanes = 4;
  int numBlocks = 512;
  int numPages = 2048;
  auto flashMem = 
    std::make_unique<FlashMemory>(numPkgs, numDies, numPlanes, numBlocks, numPages);
}
