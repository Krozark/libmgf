#ifndef MGF_GLOBAL_HEADER_HPP
#define MGF_GLOBAL_HEADER_HPP

#include <string>
#include <list>
#include <iostream> 

namespace mgf
{
    /**
     * \brief A class to store all Analyse meta data
     * Note : Not all data are save (not use), even if there is function to set them.
     * A message is print in that case
     */
    class GlobalHeader
    {
        public:
            GlobalHeader(const GlobalHeader&) = delete;
            GlobalHeader& operator=(const GlobalHeader&) = delete;
            
            /**
             * \brief Constructor. Do not set any default value to datas
             */
            GlobalHeader();

            /**
             * \brief Default move constructor
             */
            GlobalHeader(GlobalHeader&& tmp) = default;


            /**
             * \brief Not used
             */
            void setAccession(std::list<double>& l);

            /**
             * \brief Not used
             * \params charges List of possible charges for spectrums
             */
            void setCharge(std::list<int>& charges);

            /**
             * \brief Not used
             */
            void setCle(std::string& s);

            /**
             * \brief Not used
             */
            void setCom(std::string& s);

            /**
             * \brief Not used
             */
            void setComp(std::string& s);

            /**
             * \brief Not used
             */
            void setCutout(std::list<int>& l);

            /**
             * \brief Not used
             */
            void setDb(std::string& s);

            /**
             * \brief Not used
             */
            void setDecoy(int i);

            /**
             * \brief Not used
             */
            void setErrorTolerant(int i);

            /**
             * \brief Not used
             */
            void setFormat(std::string& s);

            /**
             * \brief Not used
             */
            void setFrames(std::list<int>& l);

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
            void setItOl(double d);

            /**
             * \brief Not used
             */
            void setItOlU(std::string& s);

            /**
             * \brief Not used
             */
            void setMass(std::string& s);

            /**
             * \brief Not used
             */
            void setMods(std::string& s);

            /**
             * \brief Not used
             */
            void setMultiSiteMods(int i);

            /**
             * \brief Not used
             */
            void setPepIsotopeError(int i);

            /**
             * \brief Not used
             */
            void setPfa(int i);

            /**
             * \brief Not used
             */
            void setPrecursor(double d);

            /**
             * \brief Not used
             */
            void setQuantitation(std::string& s);

            /**
             * \brief Not used
             */
            void setRepport(int i);

            /**
             * \brief Not used
             */
            void setReptype(std::string& s);

            /**
             * \brief Not used
             */
            void setSearch(std::string& s);

            /**
             * \brief Not used
             */
            void setSeg(double d);

            /**
             * \brief Not used
             */
            void setTaxonomy(std::string& s);

            /**
             * \brief Not used
             */
            void setTol(double d);

            /**
             * \brief Not used
             */
            void setTolU(std::string& s);

            /**
             * \brief Not used
             */
            void setUser(int i);

            /**
             * \brief Not used
             */
            void setUserMail(std::string& s);

            /**
             * \brief Not used
             */
            void setUserName(std::string& s);
            

            /**
             * \brief Debug print. Print all stored datas
             */
            void __print__(std::ostream& stream)const;

            /**
             * \brief Print the Spectrum as MGF format
             * \stream the outout stream
             * \param self the GlobalHeader to print
             * \return stream
             */
            friend std::ostream& operator<<(std::ostream& stream,const GlobalHeader& self);

        protected:

        private:
    };
}
#endif
