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

    void Peak::calc_masse(Spectrum& parent)
    {
        if (charge==0)
        {
            charge = 1;
            calc_masse();

            const char max = parent.header.charge;
            for (char i=2; i<=max;++i)
            {
                double tmp_masse = mgf::Convert::mz_to_masse(mz,i);
                if (tmp_masse <=parent.masse)
                {
                    Peak* p = new Peak(mz,intensity,i,used);
                    p->masse = tmp_masse;
                    parent.peaks.emplace_back(p);
                }
                else
                    break;
            }
        }
        else
        {
            calc_masse();
        }
    }

    void Peak::calc_masse()
    {
        masse = mgf::Convert::mz_to_masse(mz,charge);
    }
    
    void Peak::__print__(std::ostream& stream) const
    {
        stream<</*ROUGE<<(bruit?"+":"-")<<*//*VERT<<" <"<<originale<<"> "<<*/MGF_JAUNE<<masse<<MGF_BLEU<<" ("<<mz<<") "<<MGF_ROUGE<<intensity<<" "<<MGF_VERT<<(short int)charge<<"+"<<MGF_BLANC<<std::endl;
            
    }

}
