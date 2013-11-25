#include <mgf/Spectrum.hpp>
#include <mgf/Convert.hpp>

namespace mgf
{
    
    Spectrum::Spectrum()
    {
    }

    /*Spectrum::Spectrum(Spectrum&& tmp)
    {

    }*/

    void Spectrum::push(double z,double it,char ch)
    {
        /*mz=z;
        intensity = it;
        charge = ch<0?-ch:ch;
        masse = charge==0?0:Convert::mz_to_masse(mz,charge);*/
    }
    
    void Spectrum::__print__(std::ostream& stream)
    {
        stream<<"Spectrum:\n";
        header.__print__(stream);
        /*for(peak* p :peaks)
            p->__print__(stream);*/
        stream<<"end Spectrum\n";

    }
}
