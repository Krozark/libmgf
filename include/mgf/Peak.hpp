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
            //Peak(Peak&&) = default;
            //Peak& operator=(Peak&&) = default;

            /**
             * \brief Constructor
             * \param mz the mass/charge ration
             * \param intensity the ion intensity
             * \param charge The charge of the ion. Set 0 if not know
             */
            Peak(const double mz,const double intensity,const char charge);
            
            /**
             * \brief Constructor
             * \param mz the mass/charge ration
             * \param intensity the ion intensity
             * \param charge The charge of the ion. Set 0 if not know
             * \param used init used member.
             */
            Peak(const double mz,const double intensity,const char charge,bool* used);

            /**
             * \brief Destructor. Delete used if original is true
             */
            ~Peak();


            /**
             * \return the mass
             */
            inline double getMass()const{return mass;}


            /**
             * \return the ion intensity 
             */
            inline double getIntensity()const{return intensity;}

            /**
             * \return the ion charge
             */
            inline char getCharge()const{return charge;}

            /**
             * \return original
             */
            inline bool isOriginal()const{return original;}


            /**
             * \brief Set the valuse of used
             */
            inline void setUsed(bool b){*used = b;}

            /**
             * \return if ions is used
             */
            inline bool isUsed()const{return *used;}

            /**
             * \brief Debug print. Print the mass, mz, intensity, charge
             * format is : mass (mz) intensity charge
             */
            void __print__(std::ostream& stream)const ;

            /**
             * \brief Print the Spectrum as MGF format
             * \stream the outout stream
             * \param self the Peak to print
             * \return stream
             */
            friend std::ostream& operator<<(std::ostream& stream,const Peak& self);

        protected:
            /**
             * \brief set the mass value using mz and charge. Charge have to be greather than zero.
             */
            void calc_mass();

        private:
            friend class Spectrum;

            /**
             * \brief Calc the mass using the mz and charge ratio. It can add new peak in the parent list if charge is 0
             * \param parent The Parent spectrum.
             */
            void calc_mass(Spectrum& parent);

            const double mz; ///< mass / charge ratio
            double intensity; ///< intensity
            double mass; ///< mass in Da
            char charge; ///< charge
            bool* used;///< if the peak is used. shared_ptr is used to manage multiple peak with same mz, but different charge.
            bool original;
    };
}
#endif
