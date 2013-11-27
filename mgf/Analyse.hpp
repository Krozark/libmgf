#ifndef MGF_ANALYSE_HPP
#define MGF_ANALYSE_HPP

#include <list>
#include <iostream>

#include <mgf/GlobalHeader.hpp>

namespace mgf
{
    class Spectrum;
    class Parser;
    
    /**
     * \brief Class For manage a single MGF file
     */
    class Analyse
    {
        public:
            Analyse(const Analyse&) = delete;
            Analyse& operator=(const Analyse&) = delete;

            /**
             * \brief Construct a Analyse
             */
            Analyse();

            /**
             * \brief default move constructor
             */
            Analyse(Analyse&& tmp) = default;

            /**
             * \brief Destructor, delete all Spectrum in memory
             */
            ~Analyse();

            //void clear();

            void push(Spectrum* spect);
            inline unsigned int size(){return spectrums.size();}
            inline Spectrum& back(){return *spectrums.back();}

            void __print__(std::ostream& stream)const;


        private:
            friend class Parser;

            std::list<Spectrum*> spectrums;
            GlobalHeader header;

    };
}
#endif
