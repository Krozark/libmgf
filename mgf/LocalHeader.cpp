#include <mgf/LocalHeader.hpp>

#include <iostream>
#include <mgf/defines.hpp>

namespace mgf
{
    
    LocalHeader::LocalHeader()
    {
    }

    void LocalHeader::setCharge(int i)
    {
        MGF_IGNORED("LocalHeader::setCharge");
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

    void LocalHeader::setPepMass(double masse,double it)
    {
        MGF_IGNORED("LocalHeader::setPepMass");
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
        MGF_IGNORED("LocalHeader::setTitle");
    }

    void LocalHeader::setTol(double d)
    {
        MGF_IGNORED("LocalHeader::setTol");
    }

    void LocalHeader::setTolU(std::string& s)
    {
        MGF_IGNORED("LocalHeader::setTolU");
    }
}
