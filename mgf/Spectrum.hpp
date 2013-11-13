#ifndef MGF_SPECTRUM_HPP
#define MGF_SPECTRUM_HPP

#include <string>
#include <vector>
#include <memory>

namespace mgf
{
    class Spectrum
    {
        public:
            Spectrum(const Spectrum&) = delete;
            Spectrum& operator=(const Spectrum&) = delete;

            Spectrum();
            Spectrum(Spectrum&& tmp);

        private:
            double intensity,
                   masse,
                   mz;
            unsigned char charge;
            std::string title;
            //std::vector<peaks*> peaks;

            std::shared_ptr<std::vector<std::string>> real_solutions;
        
    };
}
#endif
