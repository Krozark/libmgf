#ifndef MGF_PEAK_HPP
#define MGF_PEAK_HPP

#include <iostream>

namespace mgf
{
    class Spectrum;

    class Peak
    {
        public:
            Peak(const double mz,const double intensity,const char charge=0);
            Peak(const Peak&) = delete;
            Peak& operator=(const Peak&) = delete;

            void calc_masse(Spectrum& parent);
            inline double getMasse()const{return masse;}

            void __print__(std::ostream& stream)const ;

        protected:
            void calc_masse();

        private:
            friend class Spectrum;

            const double mz;
            double intensity;
            double masse;
            char charge;
    };
}
#endif
