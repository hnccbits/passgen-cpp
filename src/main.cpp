#include <iostream>
#include "Config.h"

int main(int argc, char *argv[])
{

    for (int i = 0; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-V")
        {
            std::cout << "Current version: "
                      << passgen_VERSION_MAJOR << "." << passgen_VERSION_MINOR
                      << "\n";
        }
    }
    return 0;
}
