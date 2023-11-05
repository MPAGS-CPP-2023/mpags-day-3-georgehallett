//Unit Tests for MPAGSCipher ProcessCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ProcessCommandLine.hpp"

TEST_CASE("Help Requested"){
    std::vector<std::string> cmdLineArgs{"./mpags-cipher", "-h"};
    ProgramSettings settings;

    REQUIRE(processCommandLine(cmdLineArgs, settings) == true);
    REQUIRE(settings.helpRequested == true);
}