#include <mgf/Driver.hpp>

#include <fstream>

#include <mgf/defines.hpp>

//#include <mgf/Spectrum.hpp>


namespace mgf
{

    Driver::Driver(std::istream& in) : scanner(in), parser(scanner,*this)
    {
    }

    Driver::~Driver()
    {
    }

    
    Analyse Driver::parse()
    {
        mgf::Analyse analyse;
        while (parser.parse() == MGF_END_IONS)
        {
            analyse.push(new Spectrum(std::move(currentSpectrum)));
            currentSpectrum.reset();
            analyse.back().prepare();
        }

        return analyse;
    }

    Spectrum* Driver::next()
    {
        mgf::Spectrum* r = nullptr;
        if (parser.parse() == MGF_END_IONS)
        {
            r = new Spectrum(std::move(currentSpectrum));
            r->prepare();
            currentSpectrum.clear();
        }
        return r;
    }

    Analyse Driver::parse(std::istream& in)
    {
        Analyse res;
        Driver::parse(in,res);
        return res;
    }

    int Driver::parse(std::istream& in,Analyse& a)
    {
        int res = 0;
        Driver driver(in);
        Spectrum* spectrum = nullptr;
        while((spectrum = driver.next())!= nullptr)
        {
            a.push(spectrum);
            ++res;
        }
        return res;
    }

    Analyse Driver::parse_file(const std::string& filename)
    {
        Analyse res;
        Driver::parse_file(filename,res);
        return res;
    }

    int Driver::parse_file(const std::string& filename,Analyse& a)
    {
        int res = -1;
        std::ifstream file(filename, std::ifstream::in);
        if (file.good())
        {
            res = Driver::parse(file,a);
            file.close();
        }
        return res;
    }
}
