#include <string_view>

namespace Templates {

  constexpr inline std::string_view CMAKE_CONFIG_TEXT =
    "cmake_minimum_required(VERSION 3.17)\n"
    "set(CMAKE_CXX_STANDARD 20)\n"
    "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
    "\n"
    "#[[vcpkg deps]]\n"
    "find_package(CLI11 CONFIG REQUIRED)\n"
    "find_package(fmt CONFIG REQUIRED)\n"
    "find_package(Catch2 CONFIG REQUIRED)\n"
    "\n"
    "#[[main directory]]\n"
    "directory({0})\n"
    "path(GLOB proj_src src/*.cpp)\n"
    "add_executable({0} ${proj_src})\n"
    "include_directories(src)\n"
    "target_link_libraries({0} PRIVATE CLI11::CLI11)\n"
    "target_link_libraries({0} PRIVATE fmt::fmt fmt::fmt-header-only)\n"
    "\n"
    "#[[test directory]]\n"
    "directory(test)\n"
    "list(FILTER proj_src EXCLUDE REGEX \".*Main.cpp$\")\n"
    "path(GLOB test_src test/*.cpp)\n"
    "add_executable(test ${proj_src} ${test_src})\n"
    "include_directories(test)\n"
    "target_link_libraries(test PRIVATE Catch2::Catch2)\n"
    "target_link_libraries(test PRIVATE CLI11::CLI11)\n"
    "target_link_libraries(test PRIVATE fmt::fmt fmt::fmt-header-only)";

  constexpr inline std::string_view README_TEXT =
    "## {0}\n"
    "\n"
    "{1}\n"
    "\n"
    "### How to use\n"
    "\n"
    "```shell\n"
    "{0}\n"
    "```\n"
    "\n"
    "### How to build\n"
    "\n"
    "We need a build system [`cmake`](https://cmake.org/download) and a manager\n"
    "libraries [`vcpkg`](https://github.com/microsoft/vcpkg). They can be easily installed with a package manager such\n"
    "as `brew`.\n"
    "\n"
    "1. Install the dependencies:\n"
    "   `vcpkg install` [`catch2`](https://github.com/catchorg/Catch2)\n"
    "   `vcpkg install` [`cli11`](https://github.com/CLIUtils/CLI11)\n"
    "   `vcpkg install` [`fmt`](https://github.com/fmtlib/fmt)\n"
    "1. If you are using an IDE, you can stop at this step simply by setting `CMake options` as the result\n"
    "   of `vcpkg integrate install` command.  \n"
    "   Without IDE prepare the directory for building using the dependencies `vcpkg`:  \n"
    "   ```cmake `vcpkg integrate install | tail -1 | cut -d \\\" -f2` -DCMAKE_BUILD_TYPE=Release -G \"Unix Makefiles\" -B cmake-build-release```  \n"
    "   On Windows, instead of the code in quotes, manually substitute the parameter obtained by\n"
    "   calling `vcpkg integrate install`.\n"
    "1. Putting together the directory and tests:\n"
    "   `cmake --build cmake-build-release --target all`\n"
    "   After that, the main self-executable utility will appear in the `cmake-build-release` directory under the name `{0}`\n"
    "   . Tests can be run by running the `test` file located nearby.";

  constexpr inline std::string_view MAIN_CPP_TEXT =
    "#include <CLI/App.hpp>\n"
    "#include <CLI/Formatter.hpp>\n"
    "#include <CLI/Config.hpp>\n"
    "#include <fmt/core.h>\n"
    "#include <fmt/color.h>\n"
    "\n"
    "int main(int argc, char **argv) {\n"
    "  CLI::App utility(\"{1}\", \"{0}\");\n"
    "  CLI11_PARSE(utility, argc, argv)\n"
    "}";

  constexpr inline std::string_view TEST_CPP_TEXT =
    "#define CATCH_CONFIG_MAIN\n"
    "\n"
    "#include <catch.hpp>\n"
    "\n"
    "TEST_CASE(\"test\") {\n"
    "  REQUIRE(1 == 1);\n"
    "}";

}



