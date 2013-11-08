#ifndef MGF_ANALYSE_HPP
#define MGF_ANALYSE_HPP

#include <list>
#include <mgf/Spectrum.hpp>

namespace mgf
{
    class Analyse
    {
        public:
            Analyse();
        private:
            std::list<Spectrum> spectrums;

    };
}
#endif
