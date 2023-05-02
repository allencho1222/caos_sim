#include <cstdint>
#include <vector>

enum class NANDFlashCommandCode {
  PageRead,
  PageReadMultiplane,
  PageReadCopyback,
  PageReadCopybackMultiplane,
  PageProg,
  PageProgMultiplane,
  PageProgCopyback,
  PageProgCopybackMultiplane,
  BlockErase,
  BlockEraseMulitplane
};

enum class MLCTechnology {
  SingleLevelCell = 1,
  MultiLevelCell = 2,
  TripleLevelCell = 3
};

class NANDFlashCommand {
 public:
  // for read
  NANDFlashCommand(NANDFlashCommandCode command_code, std::vector<uint64_t> ppa,
                   std::vector<uint64_t> oob_data,
                   std::vector<uint64_t> user_data);
  // for write
  NANDFlashCommand(NANDFlashCommandCode command_code,
                   std::vector<uint64_t> ppa);
  // for erase
  NANDFlashCommand(NANDFlashCommandCode command_code, std::vector<uint64_t> ppa,
                   MLCTechnology mlc_tech);

 private:
  NANDFlashCommandCode command_code_;
  std::vector<uint64_t> ppa_;
  std::vector<uint64_t> oob_data_;
  std::vector<uint64_t> user_data_;
  MLCTechnology mlc_tech_;
};