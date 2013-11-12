#include <mgf/Driver.hpp>
#include <mgf/Analyse.hpp>

#include <fstream>

namespace mgf
{

    Driver::Driver(mgf::Analyse& a) : 
        analyse(a),
        Parser(nullptr),
        Scanner(nullptr)
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
        init();
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
        init();
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
