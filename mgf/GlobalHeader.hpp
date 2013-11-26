#ifndef MGF_GLOBAL_HEADER_HPP
#define MGF_GLOBAL_HEADER_HPP

#include <string>
#include <list>
#include <iostream> 

namespace mgf
{
    class GlobalHeader
    {
        public:
            GlobalHeader(const GlobalHeader&) = delete;
            GlobalHeader& operator=(const GlobalHeader&) = delete;

            GlobalHeader();
            GlobalHeader(GlobalHeader&& tmp) = default;

            void setAccession(std::list<double>& l);
            void setCharge(std::list<int>& l);
            void setCle(std::string& s);
            void setCom(std::string& s);
            void setComp(std::string& s);
            void setCutout(std::list<int>& l);
            void setDb(std::string& s);
            void setDecoy(int i);
            void setErrorTolerant(int i);
            void setFormat(std::string& s);
            void setFrames(std::list<int>& l);
            void setInstrument(std::string& s);
            void setItMods(std::string& s);
            void setItOl(double d);
            void setItOlU(std::string& s);
            void setMass(std::string& s);
            void setMods(std::string& s);
            void setMultiSiteMods(int i);
            void setPepIsotopeError(int i);
            void setPfa(int i);
            void setPrecursor(double d);
            void setQuantitation(std::string& s);
            void setRepport(int i);
            void setReptype(std::string& s);
            void setSearch(std::string& s);
            void setSeg(double d);
            void setTaxonomy(std::string& s);
            void setTol(double d);
            void setTolU(std::string& s);
            void setUser(int i);
            void setUserMail(std::string& s);
            void setUserName(std::string& s);
            
            void __print__(std::ostream& stream)const;

        protected:

        private:
    };
}
#endif
