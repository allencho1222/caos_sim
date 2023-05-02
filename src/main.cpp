#include <cxxopts.hpp>
#include <fmt/format.h>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  using SSDConfig = std::string;
  using PreconditioningConfig = std::string;
  using WorkloadConfigs = std::vector<std::string>;

  cxxopts::Options options("CAOS sim options");
  options.add_options()
    ("c,config", "SSD config", cxxopts::value<SSDConfig>())
    ("w,workload", "Workload configs", cxxopts::value<WorkloadConfigs>())
    ("p,preconditioning", "Preconditioning config",
     cxxopts::value<PreconditioningConfig>())
    ("h,help", "Print usage");
  auto result = options.parse(argc, argv);

  auto ssd_config = result["config"].as<SSDConfig>();
  auto pre_config = result["preconditioning"].as<PreconditioningConfig>();
  auto workload_configs = result["workload"].as<WorkloadConfigs>();

  return 0;
}
