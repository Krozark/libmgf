#ifndef MGF_LOCALHEADER_HPP
#define MGF_LOCALHEADER_HPP

#include <string>
#include <list>
#include <iostream> 

namespace mgf
{
    class Peak;
    class Spectrum;

    class LocalHeader
    {
        public:
            LocalHeader();
            LocalHeader(const LocalHeader&) = delete;
            LocalHeader& operator=(const LocalHeader&) = delete;

            LocalHeader(LocalHeader&& tmp) = default;

            void setCharge(const int i);
            void setComp(std::string& s);
            void setEtag(std::list<std::string>& l);
            void setInstrument(std::string& s);
            void setItMods(std::string& s);
            void setLocus(std::string& s);
            void setPepMass(const double masse,const double it);
            void setRawFile(std::string& s);
            void setRawScans(int min,int max);
            void setRtinSeconds(double min, double max);
            void setScans(int min,int max);
            void setSeq(std::list<std::string>& s);
            void setTag(std::list<std::string>&s);
            void setTitle(std::string& s);
            void setTol(double d);
            void setTolU(std::string& s);

            void __print__(std::ostream& stream)const;

            void reset();

        protected:

        private:
            friend class Peak;
            friend class Spectrum;

            char charge;
            double mz;
            double intensity;
            std::string title;
    };
}
#endif
