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
            

            void __print__(std::ostream& stream) const;
            void clear();
            void reset();
        

        private:
            friend class Parser;
            friend class Peak;

            LocalHeader header;

            double masse;
            std::vector<Peak*> peaks;

            //std::shared_ptr<std::vector<std::string>> real_solutions;

            void push(double mz,double it,char charge);

            void sort();
            void calc_masse();
            void calc_masse_peaks();
            
            /**
             * \brief Normalize les intensitée entre 0 et 1.
             * 1 sera l'intensité du pic le plus intense
             **/
            void normalize_intensitee();
        
    };
}
#endif
