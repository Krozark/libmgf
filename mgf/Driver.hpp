#ifndef MGF_DRIVER_HPP
#define MGF_DRIVER_HPP

#include <iostream>

namespace mgf
{
    class Analyse;
    class Spectrum;

    class Parser;
    class Scanner;

    class Driver
    {
        public:
            Driver(std::istream& in);
            Driver(const Driver&) = delete;
            Driver& operator=(const Driver&) = delete;

            ~Driver();

            Spectrum* next();

            static Analyse parse(std::istream& in);
            static int parse(std::istream& in,Analyse& a);
            
            static Analyse parse_file(const std::string& filename);
            static int parse_file(const std::string& filename,Analyse& a);

        private:
                
            Parser parser;
            Scanner scanner;
    };
}
#endif
