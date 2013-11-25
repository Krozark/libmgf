#include <mgf/Analyse.hpp>
#include <mgf/Spectrum.hpp>

namespace mgf
{
    Analyse::Analyse()
    {
    }

    Analyse::Analyse(Analyse&& tmp)
    {
    }

    Analyse::~Analyse()
    {
        clear();
    }

    void Analyse::clear()
    {
        for(Spectrum* s : spectrums)
            delete s;
        spectrums.clear();
    }

    void Analyse::push(Spectrum* spect)
    {
        spectrums.push_back(spect);
    }
}
