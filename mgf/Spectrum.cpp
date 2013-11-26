#include <mgf/Spectrum.hpp>
#include <mgf/Convert.hpp>
#include <mgf/Peak.hpp>

#include <mgf/defines.hpp>

#include <algorithm>

namespace mgf
{
    
    Spectrum::Spectrum()
    {
    }

    Spectrum::~Spectrum()
    {
        clear();
    }
    

    void Spectrum::push(double z,double it,char ch)
    {
        peaks.emplace_back(new Peak(z,it,ch));
    }

    void Spectrum::sort()
    {
        std::sort(this->peaks.begin(),this->peaks.end(),[](const Peak* _1 ,const Peak* _2){return _1->getMasse() < _2->getMasse();});
    }

    void Spectrum::calc_masse()
    {
        masse = mgf::Convert::mz_to_masse(header.mz,header.charge);
    }

    void Spectrum::calc_masse_peaks()
    {
        Spectrum& self = *this;
        for(Peak* p :peaks)
            p->calc_masse(self);
    }

    void Spectrum::prepare()
    {
        normalize_intensitee();
        calc_masse();
        calc_masse_peaks();
        sort();
    }

    
    void Spectrum::__print__(std::ostream& stream)const
    {
        stream<<"Spectrum:\n";
        header.__print__(stream);
        for(Peak* p :peaks)
            p->__print__(stream);
        stream<<"end Spectrum\n";

    }

    void Spectrum::clear()
    {
        const unsigned int size = peaks.size();
        for(unsigned int i=0;i<size;++i)
            delete peaks[i];
        peaks.clear();
    }

    void Spectrum::reset()
    {
        header.reset();
        clear();
    }

    void Spectrum::normalize_intensitee()
    {
        const unsigned int size = peaks.size();
        double max = 0;
        for(unsigned int i=0;i<size;++i)
            max = MAX(max,peaks[i]->intensity);

        for(unsigned int i=0;i<size;++i)
            peaks[i]->intensity/=max;
    };
}
