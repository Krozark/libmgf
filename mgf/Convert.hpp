#ifndef MGF_CONVERT_HPP
#define MGF_CONVERT_HPP

namespace mgf
{
    /**
     * \brief A class used to convert units, and to all maths
     */
    class Convert
    {
        public:
            Convert() = delete;
            Convert(const Convert&) = delete;
            Convert& operator=(const Convert&) = delete;

            static constexpr float MH = 1.00794f; ///< Mass of Hydrogen in Da
            static constexpr float MO = 15.99943f; ///< mass of carbon in Da
            static constexpr float MH2O = (MO + 2*MH); ///< mass of H2O if Da
            
            /**
             * \brief convert a mz  in mass
             * \param mz the M/Z ratio
             * \param charge The charge (Z)
             * \result the calculated mass in Da
             */
            static constexpr double mz_to_masse(const double mz,const int charge){return mz*charge - charge*MH;}

        private:
    };
}
#endif
