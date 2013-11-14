#include <iostream>

#include <mgf/Driver.hpp>

int main(int argc,char* argv[])
{
    mgf::Driver driver(std::cin);
    return driver.parse();
}
