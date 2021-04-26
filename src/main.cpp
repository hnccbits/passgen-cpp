#include <iostream>
double getversion()
{
    double ver = 1.0;
    return ver;
}
int main(int argc, char *argv[])
{

    for (int i = 0; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-V")
        {
            std::cout << "Current version: " << getversion() << "\n";
        }
    }
    return 0;
}
