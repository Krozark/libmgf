#ifndef MGF_ANALYSE_HPP
#define MGF_ANALYSE_HPP

#include <list>

#include <mgf/GlobalHeader.hpp>

namespace mgf
{
    class Spectrum;
    class Parser;
    
    class Analyse
    {
        public:
            Analyse(const Analyse&) = delete;
            Analyse& operator=(const Analyse&) = delete;

            Analyse();
            Analyse(Analyse&& tmp);
            ~Analyse();

            void clear();

            void push(Spectrum* spect);


        private:
            friend class Parser;

            std::list<Spectrum*> spectrums;
            GlobalHeader header;

    };
}
#endif
