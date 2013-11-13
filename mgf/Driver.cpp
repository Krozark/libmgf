#include <mgf/Driver.hpp>

#include <fstream>

#include <mgf/Analyse.hpp>
#include <mgf/Scanner.hpp>

namespace mgf
{

    Driver::Driver(std::istream& in) : 
        input(in),
        parser(in),
        scanner(in)
    {
    }

    Driver::~Driver()
    {
        delete scanner;
        delete parser;
    }

    
    /*int Driver::parse(std::istream& in)
    {
    }

    int Driver::parse_file(const std::string& filename)
    {
    }*/

    Spectrum* Driver::next()
    {
        return nullptr;
    }

    Analyse parse(std::istream& in)
    {
        Analyse res;
        Driver::parse(in,res);
        return res;
    }

    int parse(std::istream& in,Analyse& a)
    {
        int r = 0;
        Driver driver(in);
        Spectrum spectrum = nullptr;
        while((spectrum = driver.next(in))!= nullptr)
        {
            a.push(spectrum);
            ++r;
        }
        return r;
    }

    Analyse parse_file(const std::string& filename)
    {
        Analyse res;
        Driver::parse_file(filename,res);
        return res;
    }

    int parse_file(const std::string& filename,Analyse& a)
    {
        int res = -1;
        std::ifstream file(filename, std::ifstream::in);
        if (file.good())
        {
            r = Driver::parse(file);
            file.close();
        }
        return r;
    }

}
