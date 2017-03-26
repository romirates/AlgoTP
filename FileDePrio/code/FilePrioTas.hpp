#pragma once
#include <string>
#include <sstream>
/**
 * @file FilePrioTas.hpp
 * @author Romain Ferrand
 **/
template < typename T = int, int NB = 1000>
/**
 * @class FilePrioTas
 * @brief file de priorité par tas dans un tableau static
 **/
class FilePrioTas{
    private:
        T file[NB];
        int nbelem;
        void tamiser();
    public:
        FilePrioTas();
        ~FilePrioTas();
        void enfiler(T); //passer un T de manière général en ref const est peut être plus sécu
        void defiler();
        T premier();
        bool estVide();
        std::string contenu();
    };
#include "FilePrioTas.cpp"
