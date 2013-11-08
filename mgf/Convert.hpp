#ifndef MGF_CONVERT_HPP
#define MGF_CONVERT_HPP

namespace mgf
{
    class Convert
    {
        public:
            Convert() = delete;
            Convert(const Convert&) = delete;
            Convert& operator=(const Convert&) = delete;

            static constexpr float MH = 1.00794f; ///< Masse d'un Hydrogène en Da
            static constexpr float MO = 15.99943f; ///< masse d'un carbone en Da
            static constexpr float MH2O = (MO + 2*MH); ///< masse de H2O en Da
            
            static constexpr double mz_to_masse(const double mz,const int charge){return mz*charge - charge*MH;}

        private:
    };
}
#endif
