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


            /**
             * \brief Prepare the spectum for analyse.
             * Use this function before any analyse. It set the masse, and performe
             * some others tasks.
             */
            void prepare();

            /**
             * \return The peak list
             */
            inline const std::vector<Peak*>& getPeaks()const{return peaks;}


            /**
             * \return The header
             */
            inline const LocalHeader& getHeader()const{return header;}


            /**
             * \return the peptide mass
             */
            inline double getMasse()const {return masse;}
            
            /**
             * \brief Debug print. Print all the ms/ms peaks and meta data of the spectrum
             */
            void __print__(std::ostream& stream) const;

            /**
             * \brief Delete all the MS/MS peaks
             */
            void clear();

            /**
             * \brief reset the object as a new one.
             */
            void reset();


            struct Meta {
                double intensity_sum;
            };

            inline const Meta& getMeta()const{return meta;}


            bool is_one_of_h2o(const Peak*)const;
            bool is_one_of_specials(const Peak*)const;
        

        private:
            friend class Parser;
            friend class Peak;

            LocalHeader header; ///< meta datas
            Meta meta; ///< precalculated meta

            double masse;///< masse in Da

            std::vector<Peak*> peaks; ///< peaks list

            //std::shared_ptr<std::vector<std::string>> real_solutions;

            void push(double mz,double it,char charge);///< add e new peak in the list

            void sort(); ///< sort peaks by there masse
            void calc_masse();///< calc the spectrum masse
            void calc_masse_peaks();///< calc all the peaks mass. It can add some new peaks, and delete others that have a masse greater than the specrum mass.
            void add_specials_peaks();///< add specials peaks
            
            /**
             * \brief Normalize les intensitée entre 0 et 1.
             * 1 sera l'intensité du pic le plus intense
             **/
            void normalize_intensitee();

            enum SPECIAL {DEBUT=0, ///< masse = 0
                DEBUT_H2O, ///< masse = MH2O
                FIN_H2O, ///< masse = fin - MH2O
                FIN, ///< mass = tout
                SIZE};
            Peak* special_peaks[SPECIAL::SIZE];
        
    };
}
#endif
