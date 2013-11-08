#include <mgf/Driver.hpp>
#include <mgf/Analyse.hpp>

#include <fstream>

namespace mgf
{

    Driver::Driver(mgf::Analyse& a) : analyse(a)
    {
    }
    
    int Driver::parse(std::istream& in)
    {
        int r = 0;
        while(parse_next(in))
        {
            ++r;
        }
        return r;
    }

    int Driver::parse_file(const std::string& filename)
    {
        std::ifstream file(filename, std::ifstream::in);
        int r = parse(file);
        file.close();
        return r;
    }

    bool Driver::parse_next(std::istream& in)
    {
        return false;
    }
    
}
