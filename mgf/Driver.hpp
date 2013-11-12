#ifndef MGF_DRIVER_HPP
#define MGF_DRIVER_HPP

#include <iostream>

namespace mgf
{
    class Analyse;
    class Parser;
    class Scanner;

    class Driver
    {
        public:
            Driver(mgf::Analyse& analyse);
            Driver(const Driver&) = delete;
            Driver& operator=(const Driver&) = delete;

            ~Driver();

            int parse(std::istream& in);
            int parse_file(const std::string& filename);
            bool parse_next(std::istream& in);

            void init(std::istream&);

        private:
            Analyse& analyse;
            Parser* parser;
            Scanner* scanner;
    };
}
#endif
