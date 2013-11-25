#include <mgf/GlobalHeader.hpp>

#include <iostream>
#include <mgf/defines.hpp>

#define IGNORED(fn) std::cerr<<MGF_JAUNE<<"Function GlobalHeader::"<<fn<<" Ignored."<<MGF_BLANC<<std::endl;

namespace mgf
{
    
    GlobalHeader::GlobalHeader()
    {
    }

    void GlobalHeader::setAccession(std::list<double>& l)
    {
        IGNORED("setAccession");
    }

    void GlobalHeader::setCharge(std::list<int>& l)
    {
        IGNORED("setCharge");
    }

    void GlobalHeader::setCle(std::string& s)
    {
        IGNORED("setCle");
    }

    void GlobalHeader::setCom(std::string& s)
    {
        IGNORED("setCom");
    }

    void GlobalHeader::setComp(std::string& s)
    {
        IGNORED("setComp");
    }

    void GlobalHeader::setCutout(std::list<int>& l)
    {
        IGNORED("setCutout");
    }

    void GlobalHeader::setDb(std::string& s)
    {
        IGNORED("setDb");
    }

    void GlobalHeader::setDecoy(int i)
    {
        IGNORED("setDecoy");
    }

    void GlobalHeader::setErrorTolerant(int i)
    {
        IGNORED("setErrorTolerant");
    }

    void GlobalHeader::setFormat(std::string& s)
    {
        IGNORED("setFormat");
    }

    void GlobalHeader::setFrames(std::list<int>& l)
    {
        IGNORED("setFrames");
    }

    void GlobalHeader::setInstrument(std::string& s)
    {
        IGNORED("setInstrument");
    }

    void GlobalHeader::setItMods(std::string& s)
    {
        IGNORED("setMods");
    }

    void GlobalHeader::setItOl(double d)
    {
        IGNORED("setItOl");
    }

    void GlobalHeader::setItOlU(std::string& s)
    {
        IGNORED("setItOlU");
    }

    void GlobalHeader::setMass(std::string& s)
    {
        IGNORED("setMass");
    }

    void GlobalHeader::setMods(std::string& s)
    {
        IGNORED("setMods");
    }

    void GlobalHeader::setMultiSiteMods(int i)
    {
        IGNORED("setMultiSiteMods");
    }

    void GlobalHeader::setPepIsotopeError(int i)
    {
        IGNORED("setPepIsotopeError");
    }

    void GlobalHeader::setPfa(int i)
    {
        IGNORED("setPfa");
    }

    void GlobalHeader::setPrecursor(double d)
    {
        IGNORED("setPrecursor");
    }

    void GlobalHeader::setQuantitation(std::string& s)
    {
        IGNORED("setQuantitation");
    }

    void GlobalHeader::setRepport(int i)
    {
        IGNORED("setRepport");
    }

    void GlobalHeader::setReptype(std::string& s)
    {
        IGNORED("setReptype");
    }

    void GlobalHeader::setSearch(std::string& s)
    {
        IGNORED("setSearch");
    }

    void GlobalHeader::setSeg(double d)
    {
        IGNORED("setSeg");
    }

    void GlobalHeader::setTaxonomy(std::string& s)
    {
        IGNORED("setTaxonomy");
    }

    void GlobalHeader::setTol(double d)
    {
        IGNORED("setTol");
    }

    void GlobalHeader::setTolU(std::string& s)
    {
        IGNORED("setTolU");
    }

    void GlobalHeader::setUser(int i)
    {
        IGNORED("setUser");
    }

    void GlobalHeader::setUserMail(std::string& s)
    {
        IGNORED("setUserMail");
    }

    void GlobalHeader::setUserName(std::string& s)
    {
        IGNORED("setUserName");
    }
}
