#pragma once
#include <string>
#include <sstream>
/**
 * @file FilePrioCh.hpp
 * @author Romain Ferrand
 **/
template < typename T = int >
/**
 * @class FilePrioCh
 * @brief file de priorité par chainage simple trié
 **/
class FilePrioCh{
    private:
    struct Maillon_T{
        T elem;
        Maillon_T* suiv;

    };
    
    Maillon_T* tete;
    void supprCh(Maillon_T*);
    Maillon_T* ajout(Maillon_T*, T);
    public:
        FilePrioCh();
        ~FilePrioCh();
        void enfiler(T); //passer un T de manière général en ref const est peut être plus sécu
        void defiler();
        T premier();
        bool estVide();
        std::string contenu();
};
#include "FilePrioCh.cpp"
/**
 * Axiomes  :
 * estVide (fileVide)=VRAI estVide (enfiler (_,_))=FAUX
 * premier (fileVide)=ε premier (enfiler (fileVide ,e))=e
 * premier (enfiler (fp,e))=max (e,premier (fp)) si non estVide (fp) 
 * défiler (fileVide)= ε défiler (enfiler (fileVide ,_))=fileVide
 * défiler (enfiler(fp,e))=fp si non estVide (fp) et e > premier (fp)
 * défiler (enfiler(fp,e))=enfiler (défiler (fp),e) si non estVide (fp) et e ≤ premier (fp)
**/
