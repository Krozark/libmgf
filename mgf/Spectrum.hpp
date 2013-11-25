#ifndef MGF_SPECTRUM_HPP
#define MGF_SPECTRUM_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <mgf/LocalHeader.hpp>

namespace mgf
{
    class Parser;

    class Spectrum
    {
        public:
            Spectrum(const Spectrum&) = delete;
            Spectrum& operator=(const Spectrum&) = delete;

            Spectrum();
            Spectrum(Spectrum&& tmp) = default;

            void push(double mz,double it,char charge);
            
            void __print__(std::ostream& stream);

        private:
            friend class Parser;

            //char charge;

            //std::vector<peaks*> peaks;

            //std::shared_ptr<std::vector<std::string>> real_solutions;

            LocalHeader header;
        
    };
}
#endif
