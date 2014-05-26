#ifndef MGF_SPECTRUM_HPP
#define MGF_SPECTRUM_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <mgf/LocalHeader.hpp>

namespace mgf
{
    class Parser;
    class Peak;

    /**
     * \brief A class to represent a MS/MS spectrum
     */
    class Spectrum
    {
        public:
            Spectrum(const Spectrum&) = delete;
            Spectrum& operator=(const Spectrum&) = delete;

            /**
             * \brief Constructor
             */
            Spectrum();

            /**
             * \brief Move constructor
             */
            Spectrum(Spectrum&& tmp) = default;

            /**
             * \brief Desctuctor. Delete all peaks stored.
             */
            ~Spectrum();


            enum PrepareFlags {
                CalcMass = 1 << 1,
                CalcMassPeaks = 1<<2,
                NormalizeIntensitee = 1 << 3,
                AddSpecialsPeaks = 1<<4,
                Sort = 1 << 5,
                All = 0xFFFFFFFF
            };


            /**
             * \brief Prepare the spectum for analyse.
             * Use this function before any analyse. It set the mass, and performe
             * some others tasks.
             */
            void prepare(const int max_charge=0,const int flags = PrepareFlags::All);

            /**
             * \return The peak list
             */
            inline const std::vector<Peak*>& getPeaks()const{return peaks;}


            /**
             * \return The header
             */
            inline const LocalHeader& getHeader()const{return header;}

            inline LocalHeader& getHeader(){return header;}


            /**
             * \return the peptide mass
             */
            inline double getMass()const {return mass;}
            
            /**
             * \brief Debug print. Print all the ms/ms peaks and meta data of the spectrum
             */
            void __print__(std::ostream& stream) const;

            /**
             * \brief Print the Spectrum as MGF format
             * \stream the outout stream
             * \param self the Spectrum to print
             * \return stream
             */
            friend std::ostream& operator<<(std::ostream& stream,const Spectrum& self);

            /**
             * \brief Delete all the MS/MS peaks
             */
            void clear();

            /**
             * \brief reset the object as a new one.
             */
            void reset();

            /**
             * \brief meta data
             */ 
            struct Meta {
                double intensity_sum; ///< sum of all the peaks intensity
            };

            /**
             * \return the meta data
             */
            inline const Meta& getMeta()const{return meta;}

            /**
             * \param p the peak to compare
             * \return true if p is one of special peaks with H2o decalage
             */
            bool is_one_of_h2o(const Peak*)const;

            /**
             * \param p the peak to compare
             * \return true if p is one of special peaks
             */
            bool is_one_of_specials(const Peak* p)const;
        

        private:
            friend class Parser;
            friend class Peak;

            LocalHeader header; ///< meta datas
            Meta meta; ///< precalculated meta

            double mass;///< mass in Da

            std::vector<Peak*> peaks; ///< peaks list

            //std::shared_ptr<std::vector<std::string>> real_solutions;

            void push(double mz,double it,char charge);///< add e new peak in the list

            void sort(); ///< sort peaks by there mass
            void calc_mass();///< calc the spectrum mass
            void calc_mass_peaks(const int max_charge=0);///< calc all the peaks mass. It can add some new peaks, and delete others that have a mass greater than the specrum mass.
            void add_specials_peaks();///< add specials peaks
            
            /**
             * \brief Normalize les intensitée entre 0 et 1.
             * 1 sera l'intensité du pic le plus intense
             **/
            void normalize_intensitee();

            enum SPECIAL {DEBUT=0, ///< mass = 0
                DEBUT_H2O, ///< mass = MH2O
                FIN_H2O, ///< mass = fin - MH2O
                FIN, ///< mass = tout
                SIZE};
            Peak* special_peaks[SPECIAL::SIZE]; ///< store the specials peaks (artificals)
        
    };
}
#endif
