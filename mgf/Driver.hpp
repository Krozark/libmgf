#ifndef MGF_DRIVER_HPP
#define MGF_DRIVER_HPP

#include <iostream>

namespace mgf
{
    class Analyse;

    class Driver
    {
        public:
            Driver(mgf::Analyse& analyse);

            int parse(std::istream& in);
            int parse_file(const std::string& filename);
            bool parse_next(std::istream& in);

        private:
            Analyse& analyse;
    };
}
#endif
