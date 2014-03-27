#include <iostream>
#include <fstream>

#include <mgf/Driver.hpp>

int main(int argc,char* argv[])
{
    int r=0;
    std::ifstream file(argv[1], std::ifstream::in);
    if (file.good())
    {
        mgf::Driver driver(file);
        mgf::Analyse a = driver.parse();
        file.close();

        r = a.size();
        std::cout<<a<<std::endl;
        //a.__print__(std::cout);
    }
    return r;
}
