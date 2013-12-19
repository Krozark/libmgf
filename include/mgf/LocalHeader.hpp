#ifndef MGF_LOCALHEADER_HPP
#define MGF_LOCALHEADER_HPP

#include <string>
#include <list>
#include <iostream> 

namespace mgf
{
    class Peak;
    class Spectrum;

    /**
     * \brief Header for Spectrum. Contain meta data from MGF.
     * Note : Not all data are save (not use), even if there is function to set them.
     * A message is print in that case
     */
    class LocalHeader
    {
        public:
            LocalHeader(const LocalHeader&) = delete;
            LocalHeader& operator=(const LocalHeader&) = delete;
            
            /**
             * \brief Constructor. Do not initialize value with default value
             */
            LocalHeader();

            LocalHeader(LocalHeader&& tmp) = default;

            /**
             * \brief Set the Charge
             * \param charge the charge
             */
            void setCharge(const int charge);

            /**
             * \return the charge
             */
            inline char getCharge()const{return charge;}


            /**
             * \brief Not used
             */
            void setComp(std::string& s);

            /**
             * \brief Not used
             */
            void setEtag(std::list<std::string>& l);

            /**
             * \brief Not used
             */
            void setInstrument(std::string& s);

            /**
             * \brief Not used
             */
            void setItMods(std::string& s);

            /**
             * \brief Not used
             */
            void setLocus(std::string& s);

            /**
             * \brief Set the mz and intensity
             * \param mass The M/Z ratio
             * \param itensity intensity
             */
            void setPepMass(const double mass,const double itensity);

            /**
             * \return The intensity
             */
            inline double getIntensity()const{return intensity;}

            /**
             * \brief Not used
             */
            void setRawFile(std::string& s);

            /**
             * \brief Not used
             */
            void setRawScans(int min,int max);

            /**
             * \brief Not used
             */
            void setRtinSeconds(double min, double max);

            /**
             * \brief Not used
             */
            void setScans(int min,int max);

            /**
             * \brief Not used
             */
            void setSeq(std::list<std::string>& s);

            /**
             * \brief Not used
             */
            void setTag(std::list<std::string>&s);

            /**
             * \brief Set the Title
             * \param title The title of the spectrum
             */
            void setTitle(std::string& title);


            /**
             * \return the Title
             */
            const std::string& getTitle()const;

            /**
             * \brief Not used
             */
            void setTol(double d);

            /**
             * \brief Not used
             */
            void setTolU(std::string& s);

            
            /**
             * \brief Debug print. Print all the data used
             */
            void __print__(std::ostream& stream)const;

            /**
             * \brief Print the Spectrum as MGF format
             * \stream the outout stream
             * \param self the LocalHeader to print
             * \return stream
             */
            friend std::ostream& operator<<(std::ostream& stream,const LocalHeader& self);

            /**
             * \brief Reset all datas to zero for numbers, and empty string for string
             */
            void reset();

        protected:

        private:
            friend class Peak;
            friend class Spectrum;

            char charge; ///< the charge
            double mz; ///< the M/Z ratio
            double intensity; ///< the intensity
            std::string title; ///< the title
    };
}
#endif
