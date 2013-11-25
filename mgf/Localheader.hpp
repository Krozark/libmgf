#ifndef MGF_LOCALHEADER_HPP
#define MGF_LOCALHEADER_HPP

#include <string>
#include <list>

namespace mgf
{
    class LocalHeader
    {
        public:
            LocalHeader();
            LocalHeader(const LocalHeader&) = delete;
            LocalHeader& operator=(const LocalHeader&) = delete;

            void setCharge(int i);
            void setComp(std::string& s);
            void setEtag(std::list<std::string>& l);
            void setInstrument(std::string& s);
            void setItMods(std::string& s);
            void setLocus(std::string& s);
            void setPepMass(double masse,double it);
            void setRawFile(std::string& s);
            void setRawScans(int min,int max);
            void setRtinSeconds(double min, double max);
            void setScans(int min,int max);
            void setSeq(std::list<std::string>& s);
            void setTag(std::list<std::string>&s);
            void setTitle(std::string& s);
            void setTol(double d);
            void setTolU(std::string& s);

        protected:

        private:
    };
}
#endif
