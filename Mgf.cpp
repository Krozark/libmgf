#include <iostream>
#include <fstream>

#include <mgf/Driver.hpp>

int main(int argc,char* argv[])
{
    int r=1;
    std::ifstream file(argv[1], std::ifstream::in);
    if (file.good())
    {
        mgf::Driver driver(file);
        r = driver.parse();
        file.close();
    }
    return r;

    mgf::Driver driver(std::cin);
    return driver.parse();
}
