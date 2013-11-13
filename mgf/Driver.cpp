#include <mgf/Driver.hpp>

#include <fstream>

//#include <mgf/Spectrum.hpp>


namespace mgf
{

    Driver::Driver(std::istream& in) : scanner(in), parser(scanner,*this)
    {
    }

    Driver::~Driver()
    {
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

    Analyse Driver::parse(std::istream& in)
    {
        Analyse res;
        Driver::parse(in,res);
        return res;
    }

    int Driver::parse(std::istream& in,Analyse& a)
    {
        int res = 0;
        Driver driver(in);
        Spectrum* spectrum = nullptr;
        while((spectrum = driver.next())!= nullptr)
        {
            a.push(spectrum);
            ++res;
        }
        return res;
    }

    Analyse Driver::parse_file(const std::string& filename)
    {
        Analyse res;
        Driver::parse_file(filename,res);
        return res;
    }

    int Driver::parse_file(const std::string& filename,Analyse& a)
    {
        int res = -1;
        std::ifstream file(filename, std::ifstream::in);
        if (file.good())
        {
            res = Driver::parse(file,a);
            file.close();
        }
        return res;
    }

}
