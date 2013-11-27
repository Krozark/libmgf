#ifndef MGF_DRIVER_HPP
#define MGF_DRIVER_HPP

#include <iostream>

#include <mgf/Spectrum.hpp>
#include <mgf/GlobalHeader.hpp>
#include <mgf/Analyse.hpp>

#include <mgf/Scanner.hpp>

namespace mgf
{
    class Analyse;
    class Spectrum;

    /**
     * A class that have to be use to parse a MGF input
     */
    class Driver
    {
        public:
            /**
             * \brief Construct a Driver from a stream
             * \param in input stream
             */
            Driver(std::istream& in);

            Driver(const Driver&) = delete;
            Driver& operator=(const Driver&) = delete;

            /**
             * \brief Destructor
             */
            ~Driver();

            /**
             * \brief Parse all the input (until \0)
             * \result A analyse tha contain all the datas
             */
            Analyse parse();

            /**
             * \brief PArse only the next spectrum
             * \result a pointer to the Spectrum. if nullptr is recive, all the input have been pase. You have to manualy delete the Spectrum
             */
            Spectrum* next();

            /**
             * \brief Parse a input
             * \param in The input stream to parse
             * \result The analyse tha contain all the datas
             */
            static Analyse parse(std::istream& in);

            /**
             * \brief Parse a input, and add the data parse to the analyse
             * \param in Input to parse
             * \param a Analyse where data will be saves
             * \result number of spectrum parsed
             */
            static int parse(std::istream& in,Analyse& a);
            
            /**
             * \brief Parse a file and return a Analyse
             * \param filename the mgf file name
             * \return A Analyse tha contain all the datas parsed
             */
            static Analyse parse_file(const std::string& filename);

            /**
             * \brief Parse a file, and store data in the analyse
             * \param filename file to parse
             * \param a Analyse where data will be saved
             * \result number of spectrum parsed
             */
            static int parse_file(const std::string& filename,Analyse& a);

             
        private:
            friend class Parser;
                
            Scanner scanner; ///< The lexer
            Parser parser; ///< The parser

            mgf::GlobalHeader header; ///< the tmp global header 
            mgf::Spectrum currentSpectrum; ///< the current spectrum parsed
    };
}
#endif
