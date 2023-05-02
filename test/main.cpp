#include <fmt/format.h>
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  fmt::print("HELLO test {} {}\n", 1, 3);
  ::testing::InitGoogleTest(&argc, argv);
  return 0;
}
