#include <mgf/Peak.hpp>

#include <mgf/Convert.hpp>
#include <mgf/Spectrum.hpp>
#include <mgf/defines.hpp>

namespace mgf
{
    Peak::Peak(const double m,const double it,const char ch) :  mz(m), intensity(it), charge(ch), original(true)
    {
            used = new bool(false);
    }
    
    Peak::Peak(const double m,const double it,const char ch,bool* usd) :  mz(m), intensity(it), charge(ch), used(usd), original(false)
    {
    }

    Peak::~Peak()
    {
        if (original)
        {
            delete used;
        }
    }

    void Peak::calc_mass(Spectrum& parent)
    {
        if (charge==0)
        {
            charge = 1;
            calc_mass();

            const char max = parent.header.charge;
            for (char i=2; i<=max;++i)
            {
                double tmp_mass = mgf::Convert::mz_to_mass(mz,i);
                if (tmp_mass <=parent.mass)
                {
                    Peak* p = new Peak(mz,intensity,i,used);
                    p->mass = tmp_mass;
                    parent.peaks.emplace_back(p);
                }
                else
                    break;
            }
        }
        else
        {
            calc_mass();
        }
    }

    void Peak::calc_mass()
    {
        mass = mgf::Convert::mz_to_mass(mz,charge);
    }
    
    void Peak::__print__(std::ostream& stream) const
    {
        stream<</*ROUGE<<(bruit?"+":"-")<<*//*VERT<<" <"<<originale<<"> "<<*/MGF_JAUNE<<mass<<MGF_BLEU<<" ("<<mz<<") "<<MGF_ROUGE<<intensity<<" "<<MGF_VERT<<(short int)charge<<"+"<<MGF_BLANC<<std::endl;
            
    }

    std::ostream& operator<<(std::ostream& stream,const Peak& self)
    {
        stream<<self.mz<<"\t"<<int(self.intensity*10000);
        if(self.charge)
            stream<<"\t"<<(self.charge>0?self.charge:-self.charge)<<(self.charge>0?"+":"-");
        return (stream<<std::endl);
    }

}
