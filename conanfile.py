from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, cmake_layout

class MQSim(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    build_policy = "missing"

    def validate(self):
        if self.settings.compiler != "gcc":
            raise ConanInvalidConfiguration("Require GCC")
        versions = ['11', '12']
        if not self.settings.compiler.version in versions:
            raise ConanInvalidConfiguration("Use GCC version >= 11")
        if self.settings.compiler.libcxx != "libstdc++11":
            raise ConanInvalidConfiguration("Require libstdc++11")
        gnus = ["gnu11", "gnu14", "gnu17", "gnu20"]
        if not self.settings.compiler.cppstd in gnus:
            raise ConanInvalidConfiguration("Require cpp standard above 11 (e.g., gnu11")

    def requirements(self):
        self.requires("fmt/9.1.0")
        self.requires("spdlog/1.11.0")
        self.requires("yaml-cpp/0.7.0")
        self.requires("cxxopts/3.1.1")
        self.requires("unordered_dense/4.0.0")
        self.requires("gtest/1.12.1")

    def configure(self):
        self.options["fmt/*"].shared = False
        self.options["spdlog/*"].shared = False
        self.options["yaml-cpp/*"].shared = False
        self.options["cxxopts/*"].shared = False
        self.options["unordered_dense/*"].shared = False
        self.options["gtest/*"].shared = False

    def layout(self):
        cmake_layout(self)
