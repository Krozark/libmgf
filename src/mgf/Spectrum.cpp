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

    bool Spectrum::is_one_of_h2o(const Peak* p)const
    {
        return (p == special_peaks[SPECIAL::DEBUT_H2O]) or (p == special_peaks[SPECIAL::FIN_H2O]);
    };

    bool Spectrum::is_one_of_specials(const Peak* p)const
    {
        return (p == special_peaks[SPECIAL::DEBUT]) 
            or (p == special_peaks[SPECIAL::DEBUT_H2O]) 
            or (p == special_peaks[SPECIAL::FIN_H2O])
            or (p == special_peaks[SPECIAL::FIN]);
    };
    

    void Spectrum::push(double z,double it,char ch)
    {
        peaks.emplace_back(new Peak(z,it,ch));
    }

    void Spectrum::sort()
    {
        std::sort(this->peaks.begin(),
                  this->peaks.end(),
                  [](const Peak* _1 ,const Peak* _2){
                    return _1->getMass() < _2->getMass();
                  });
    }

    void Spectrum::calc_mass()
    {
        if(header.charge<=0)
            header.charge = 1;

        mass = mgf::Convert::mz_to_mass(header.mz,header.charge);
    }

    void Spectrum::calc_mass_peaks()
    {
        Spectrum& self = *this;

        unsigned int size =peaks.size();
        unsigned int i=0;
        while(i<size)
        {
            peaks.at(i)->calc_mass(self);
            if (peaks.at(i)->mass > mass) //supression des truc impossible à etre en lien avec le peptide
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
        p->mass = p->mz;
        peaks.emplace_back(p);
        special_peaks[SPECIAL::DEBUT] = p;

        p = new Peak(this->mass,1,-1);
        p->mass = p->mz;
        peaks.emplace_back(p);
        special_peaks[SPECIAL::FIN] = p;
        
        /***************** H2O *******************/

        p = new Peak(mgf::Convert::MH2O,1,-1); 
        p->mass = p->mz;
        peaks.emplace_back(p);
        special_peaks[SPECIAL::DEBUT_H2O] = p;

        p = new Peak(this->mass - mgf::Convert::MH2O,1,-1);
        p->mass = p->mz;
        peaks.emplace_back(p);
        special_peaks[SPECIAL::FIN_H2O] = p;
    }

    void Spectrum::prepare()
    {
        calc_mass(); // calc spectrum mass
        calc_mass_peaks(); // calc peaks mass
        normalize_intensitee(); // normalize intensity of peaks (before calc_mass_peaks to make less call)
        add_specials_peaks(); // add artificials peaks
        sort(); // sort peaks
        peaks.shrink_to_fit(); //reduce vector to minimal size
    }

    
    void Spectrum::__print__(std::ostream& stream)const
    {
        stream<<"Spectrum:\n"
            <<"\tMass: "<<mass<<"\n";
        header.__print__(stream);

        const unsigned int size = peaks.size();
        for(unsigned int i=0;i<size;++i)
        {
            stream<<"#"<<i<<" : ";
            peaks[i]->__print__(stream);
        }
        stream<<"end Spectrum\n\n";

    }

    std::ostream& operator<<(std::ostream& stream,const Spectrum& self)
    {
        stream<<"BEGIN IONS\n"<<self.header;
        for(Peak* p : self.peaks)
            stream<<*p;
        return (stream<<"END IONS\n");
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

        meta.intensity_sum = 0.0;

        for(unsigned int i=0;i<size;++i)
            max = MAX(max,peaks[i]->intensity);

        for(unsigned int i=0;i<size;++i)
        {
            peaks[i]->intensity/=max;
            meta.intensity_sum+= peaks[i]->intensity;
        }
    };
}
