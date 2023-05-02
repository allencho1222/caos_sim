#include "NANDFlashCommand.h"

NANDFlashCommand::NANDFlashCommand(NANDFlashCommandCode command_code,
                                   std::vector<uint64_t> ppa,
                                   std::vector<uint64_t> oob_data,
                                   std::vector<uint64_t> user_data)
    : command_code_(command_code),
      ppa_(ppa),
      oob_data_(oob_data),
      user_data_(user_data) {}

NANDFlashCommand::NANDFlashCommand(NANDFlashCommandCode command_code,
                                   std::vector<uint64_t> ppa)
    : command_code_(command_code), ppa_(ppa) {}

NANDFlashCommand::NANDFlashCommand(NANDFlashCommandCode command_code,
                                   std::vector<uint64_t> ppa,
                                   MLCTechnology mlc_tech)
    : command_code_(command_code), ppa_(ppa), mlc_tech_(mlc_tech) {}