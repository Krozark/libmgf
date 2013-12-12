#include <mgf/Analyse.hpp>
#include <mgf/Spectrum.hpp>

namespace mgf
{
    Analyse::Analyse()
    {
    }

    Analyse::~Analyse()
    {
        for (Spectrum*s : spectrums)
            delete s;
    }

    void Analyse::push(Spectrum* spect)
    {
        spectrums.push_back(spect);
    }


    void Analyse::__print__(std::ostream& stream)const
    {
        stream<<"Analyse:\n";
        header.__print__(stream);
        for (Spectrum* s:spectrums)
            s->__print__(stream);
        stream<<"End Analyse\n";
    }

    std::ostream& operator<<(std::ostream& stream,const Analyse& self)
    {
        stream<<self.header<<std::endl;
        for(Spectrum* s : self.spectrums)
            stream<<*s<<std::endl;
        return stream;
    }
}
