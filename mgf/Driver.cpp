#include <mgf/Driver.hpp>

#include <fstream>

#include <mgf/Analyse.hpp>
#include <mgf/Scanner.hpp>

namespace mgf
{

    Driver::Driver(mgf::Analyse& a) : 
        analyse(a),
        parser(nullptr),
        scanner(nullptr)
    {
    }

    Driver::~Driver()
    {
        delete scanner;
        delete parser;
    }

    
    int Driver::parse(std::istream& in)
    {
        int r = 0;
        init(in);
        while(parse_next(in))
        {
            ++r;
        }
        return r;
    }

    int Driver::parse_file(const std::string& filename)
    {
        std::ifstream file(filename, std::ifstream::in);
        if (not file.good())
            return -1;
        init(file);
        int r = parse(file);
        file.close();
        return r;
    }

    bool Driver::parse_next(std::istream& in)
    {
        return false;
    }

   void Driver::init(std::istream& in)
   {
       if (scanner)
           delete scanner;
       scanner = new mgf::Scanner(in);
        
       if (parser)
           delete parser;
       parser = new mgf::Parser(*scanner,*this);
   } 
    
}
