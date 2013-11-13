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

    void Analyse::push(Spectrum* spect)
    {
        spectrums.push_back(spect);
    }
}
