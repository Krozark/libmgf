#ifndef MGF_ANALYSE_HPP
#define MGF_ANALYSE_HPP

#include <list>
#include <iostream>

#include <mgf/GlobalHeader.hpp>

namespace mgf
{
    class Spectrum;
    class Parser;
    class Driver;
    
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


            /**
             * \brief get the number of spectrums
             *
             * \return The spectrums number
             */
            inline unsigned int size(){return spectrums.size();}

            /**
             * \brief Get the last spectrum.
             *
             * \return The last spectrum added.
             */
            inline Spectrum& back(){return *spectrums.back();}

            /**
             * \return The spectrums list
             */
            inline const std::list<Spectrum*>& getSpectrums()const{return spectrums;}

            /**
             * \brief Debug print. Print the header and all the spectrums.
             */
            void __print__(std::ostream& stream)const;

            /**
             * \brief Print the Spectrum as MGF format
             * \stream the outout stream
             * \param self the Analyse to print
             * \return stream
             */
            friend std::ostream& operator<<(std::ostream& stream,const Analyse& self);


        private:
            friend class Parser;
            friend class Driver;

            /**
             * \brief Add a Spectrum. When Analyse is destory, all spectrums are
             * delete.
             *
             * \param spect Le spectum pointer to add in current Analyse
             */
            void push(Spectrum* spect);

            std::list<Spectrum*> spectrums; ///< spectrums to store
            GlobalHeader header; ///< meta datas

    };
}
#endif
