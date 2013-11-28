#ifndef MGF_PEAK_HPP
#define MGF_PEAK_HPP

#include <iostream>

namespace mgf
{
    class Spectrum;

    /**
     * \brief A class storing MS/MS datas for a single peak
     */
    class Peak
    {
        public:
            Peak(const Peak&) = delete;
            Peak& operator=(const Peak&) = delete;

            /**
             * \brief Constructor
             * \param mz the masse/charge ration
             * \param intensity the ion intensity
             * \param charge The charge of the ion. Set 0 if not know
             */
            Peak(const double mz,const double intensity,const char charge=0);


            /**
             * \return the masse
             */
            inline double getMasse()const{return masse;}


            /**
             * \return the ion intensity 
             */
            inline double getIntensity()const{return intensity;}

            /**
             * \brief Debug print. Print the masse, mz, intensity, charge
             * format is : mass (mz) intensity charge
             */
            void __print__(std::ostream& stream)const ;

        protected:
            /**
             * \brief set the masse value using mz and charge. Charge have to be greather than zero.
             */
            void calc_masse();

        private:
            friend class Spectrum;

            /**
             * \brief Calc the masse using the mz and charge ratio. It can add new peak in the parent list if charge is 0
             * \param parent The Parent spectrum.
             */
            void calc_masse(Spectrum& parent);

            const double mz; ///< masse / charge ratio
            double intensity; ///< intensity
            double masse; ///< masse in Da
            char charge; ///< charge
    };
}
#endif
