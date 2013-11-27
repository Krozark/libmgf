#include <mgf/LocalHeader.hpp>

#include <mgf/defines.hpp>

namespace mgf
{
    
    LocalHeader::LocalHeader() /*charge(0),mz(0),intensity(0)*/
    {
    }

    void LocalHeader::setCharge(const int i)
    {
        charge = i;
    }

    void LocalHeader::setComp(std::string& s)
    {
        MGF_IGNORED("LocalHeader::setComp");
    }

    void LocalHeader::setEtag(std::list<std::string>& l)
    {
        MGF_IGNORED("LocalHeader::setEtag");
    }

    void LocalHeader::setInstrument(std::string& s)
    {
        MGF_IGNORED("LocalHeader::setInstrument");
    }

    void LocalHeader::setItMods(std::string& s)
    {
        MGF_IGNORED("LocalHeader::setItMods");
    }

    void LocalHeader::setLocus(std::string& s)
    {
        MGF_IGNORED("LocalHeader::setLocus");
    }

    void LocalHeader::setPepMass(const double masse,const double it)
    {
        mz = masse;
        intensity = it;
    }

    void LocalHeader::setRawFile(std::string& s)
    {
        MGF_IGNORED("LocalHeader::setRawFile");
    }

    void LocalHeader::setRawScans(int min,int max)
    {
        MGF_IGNORED("LocalHeader::setRawScans");
    }

    void LocalHeader::setRtinSeconds(double min, double max)
    {
        MGF_IGNORED("LocalHeader::setRtinSeconds");
    }

    void LocalHeader::setScans(int min,int max)
    {
        MGF_IGNORED("LocalHeader::setScans");
    }

    void LocalHeader::setSeq(std::list<std::string>& s)
    {
        MGF_IGNORED("LocalHeader::setSeq");
    }

    void LocalHeader::setTag(std::list<std::string>&s)
    {
        MGF_IGNORED("LocalHeader::setTag");
    }

    void LocalHeader::setTitle(std::string& s)
    {
        title = s;
    }

    void LocalHeader::setTol(double d)
    {
        MGF_IGNORED("LocalHeader::setTol");
    }

    void LocalHeader::setTolU(std::string& s)
    {
        MGF_IGNORED("LocalHeader::setTolU");
    }

    void LocalHeader::__print__(std::ostream& stream)const
    {
        stream<<"LocalHeader:"
            <<"\n\tTitle: "<<title
            <<"\n\tCharge: "<<(short int)charge
            <<"\n\tIntensity: "<<intensity
            <<"\n\tMz: "<<mz
            <<"\nEnd LocalHeader:\n";

    }

    void LocalHeader::reset()
    {
        charge = 0;
        mz = 0;
        intensity = 0;
        title.clear();
    }
}
