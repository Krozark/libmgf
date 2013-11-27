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

        unsigned int size =peaks.size();
        unsigned int i=0;
        while(i<size)
        {
            peaks.at(i)->calc_masse(self);
            if (peaks.at(i)->masse > masse) //supression des truc impossible à etre en lien avec le peptide
            {
                delete peaks.at(i);
                peaks.erase(peaks.begin()+i);
                --size;
            }
            else
                ++i;
        }
    }

    void Spectrum::add_specials_peaks()
    {
        /********* EXTREMITÉES ****************/
        Peak* p = new Peak(0,1,-1);
        p->masse = 0;
        peaks.emplace_back(p);
        special_peaks[SPECIAL::DEBUT] = p;

        p = new Peak(0,1,-1);
        p->masse = this->masse;
        peaks.emplace_back(p);
        special_peaks[SPECIAL::FIN] = p;
        
        /***************** H2O *******************/

        p = new Peak(0,1,-1); 
        p->masse = mgf::Convert::MH2O; 
        peaks.emplace_back(p);
        special_peaks[SPECIAL::DEBUT_H2O] = p;

        p = new Peak(0,1,-1);
        p->masse = this->masse - mgf::Convert::MH2O;
        peaks.emplace_back(p);
        special_peaks[SPECIAL::FIN_H2O] = p;
    }

    void Spectrum::prepare()
    {
        normalize_intensitee();
        calc_masse();
        calc_masse_peaks();
        add_specials_peaks();
        sort();
        peaks.shrink_to_fit();
    }

    
    void Spectrum::__print__(std::ostream& stream)const
    {
        stream<<"Spectrum:\n"
            <<"\tMasse: "<<masse<<"\n";
        header.__print__(stream);
        for(Peak* p :peaks)
            p->__print__(stream);
        stream<<"end Spectrum\n\n";

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
