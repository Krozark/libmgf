#ifndef MGF_ANALYSE_HPP
#define MGF_ANALYSE_HPP

#include <list>

namespace mgf
{
    class Spectrum;
    
    class Analyse
    {
        public:
            Analyse(const Analyse&) = delete;
            Analyse& operator=(const Analyse&) = delete;

            Analyse();
            Analyse(Analyse&& tmp);

            void push(Spectrum* spect);

        private:
            std::list<Spectrum*> spectrums;

    };
}
#endif
