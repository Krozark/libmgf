#ifndef MGF_DRIVER_HPP
#define MGF_DRIVER_HPP

#include <iostream>

#include <mgf/Spectrum.hpp>
#include <mgf/GlobalHeader.hpp>
#include <mgf/Analyse.hpp>

#include <mgf/Scanner.hpp>

namespace mgf
{
    class Analyse;
    class Spectrum;

    class Driver
    {
        public:
            Driver(std::istream& in);
            Driver(const Driver&) = delete;
            Driver& operator=(const Driver&) = delete;

            ~Driver();

            int parse();

            /*Spectrum* next();

            static Analyse parse(std::istream& in);
            static int parse(std::istream& in,Analyse& a);
            
            static Analyse parse_file(const std::string& filename);
            static int parse_file(const std::string& filename,Analyse& a);*/

             
        private:
            friend class Parser;
                
            Scanner scanner;
            Parser parser;

            mgf::Analyse analyse;
            mgf::Spectrum currentSpectrum;

            void clearCurrentSpectrum();
    };
}
#endif
