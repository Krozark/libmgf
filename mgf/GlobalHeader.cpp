#include <mgf/GlobalHeader.hpp>

#include <mgf/defines.hpp>


namespace mgf
{
    
    GlobalHeader::GlobalHeader()
    {
    }

    /*GlobalHeader::GlobalHeader(GlobalHeader&& tmp)
    {
    }*/

    void GlobalHeader::setAccession(std::list<double>& l)
    {
        MGF_IGNORED("GlobalHeader::setAccession");
    }

    void GlobalHeader::setCharge(std::list<int>& l)
    {
        MGF_IGNORED("GlobalHeader::setCharge");
    }

    void GlobalHeader::setCle(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setCle");
    }

    void GlobalHeader::setCom(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setCom");
    }

    void GlobalHeader::setComp(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setComp");
    }

    void GlobalHeader::setCutout(std::list<int>& l)
    {
        MGF_IGNORED("GlobalHeader::setCutout");
    }

    void GlobalHeader::setDb(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setDb");
    }

    void GlobalHeader::setDecoy(int i)
    {
        MGF_IGNORED("GlobalHeader::setDecoy");
    }

    void GlobalHeader::setErrorTolerant(int i)
    {
        MGF_IGNORED("GlobalHeader::setErrorTolerant");
    }

    void GlobalHeader::setFormat(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setFormat");
    }

    void GlobalHeader::setFrames(std::list<int>& l)
    {
        MGF_IGNORED("GlobalHeader::setFrames");
    }

    void GlobalHeader::setInstrument(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setInstrument");
    }

    void GlobalHeader::setItMods(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setMods");
    }

    void GlobalHeader::setItOl(double d)
    {
        MGF_IGNORED("GlobalHeader::setItOl");
    }

    void GlobalHeader::setItOlU(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setItOlU");
    }

    void GlobalHeader::setMass(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setMass");
    }

    void GlobalHeader::setMods(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setMods");
    }

    void GlobalHeader::setMultiSiteMods(int i)
    {
        MGF_IGNORED("GlobalHeader::setMultiSiteMods");
    }

    void GlobalHeader::setPepIsotopeError(int i)
    {
        MGF_IGNORED("GlobalHeader::setPepIsotopeError");
    }

    void GlobalHeader::setPfa(int i)
    {
        MGF_IGNORED("GlobalHeader::setPfa");
    }

    void GlobalHeader::setPrecursor(double d)
    {
        MGF_IGNORED("GlobalHeader::setPrecursor");
    }

    void GlobalHeader::setQuantitation(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setQuantitation");
    }

    void GlobalHeader::setRepport(int i)
    {
        MGF_IGNORED("GlobalHeader::setRepport");
    }

    void GlobalHeader::setReptype(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setReptype");
    }

    void GlobalHeader::setSearch(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setSearch");
    }

    void GlobalHeader::setSeg(double d)
    {
        MGF_IGNORED("GlobalHeader::setSeg");
    }

    void GlobalHeader::setTaxonomy(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setTaxonomy");
    }

    void GlobalHeader::setTol(double d)
    {
        MGF_IGNORED("GlobalHeader::setTol");
    }

    void GlobalHeader::setTolU(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setTolU");
    }

    void GlobalHeader::setUser(int i)
    {
        MGF_IGNORED("GlobalHeader::setUser");
    }

    void GlobalHeader::setUserMail(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setUserMail");
    }

    void GlobalHeader::setUserName(std::string& s)
    {
        MGF_IGNORED("GlobalHeader::setUserName");
    }

    void GlobalHeader::__print__(std::ostream& stream)
    {
        stream<<"GlobalHeader:\n";
        stream<<"End GlobalHeader:\n";

    }
}
