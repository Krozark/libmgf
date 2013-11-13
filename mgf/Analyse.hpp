#ifndef MGF_ANALYSE_HPP
#define MGF_ANALYSE_HPP

#include <list>

namespace mgf
{
    class Spectrum;
    
    class Analyse
    {
        public:
            Analyse();
            Analyse(const Analyse&) = delete;
            operator=(const Analyse&) = delete;

            void push(Spectrum* spect);

        private:
            std::list<Spectrum*> spectrums;

    };
}
#endif
