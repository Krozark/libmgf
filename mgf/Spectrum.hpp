#ifndef MGF_SPECTRUM_HPP
#define MGF_SPECTRUM_HPP

#include <string>
#include <vector>
#include <memory>

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
            Spectrum(Spectrum&& tmp);

            void push(double mz,double it,int charge);

        private:
            friend class Parser;

            double intensity,
                   masse,
                   mz;
            unsigned char charge;
            std::string title;
            //std::vector<peaks*> peaks;

            std::shared_ptr<std::vector<std::string>> real_solutions;

            LocalHeader header;
        
    };
}
#endif
