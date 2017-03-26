#include "EnsembleC.hpp"
#include <string>
#include <iostream>

using namespace std;

EnsembleC::EnsembleC(){
    listeMots.tete = nullptr;
    listeMots.nb = 0;
    }
    
EnsembleC::~EnsembleC(){
    Maillon* ptrCourant = listeMots.tete;
    for (unsigned int i =0;i<listeMots.nb;i++){
        listeMots.tete = ptrCourant->suiv;
        delete(ptrCourant);
        ptrCourant = listeMots.tete;
    }
    listeMots.nb = 0;
}

bool EnsembleC::estVide() const{
    return listeMots.nb == 0;
}

/**
 * Méthode permetant de savoir si mot appartient à l'ensembleC concidéré 
 */    
bool EnsembleC::contient(string mot) const {

    if(mot.size() <= 26){
        unsigned int i=0;
        Maillon* ptrCourant = listeMots.tete;
        while(i<listeMots.nb && ptrCourant->mot != mot){
            ptrCourant = ptrCourant->suiv;
            i++;
        }
        return (i<listeMots.nb);
    }
    return false;
}
/**
 *
 */ 
void EnsembleC::ajoute(string mot){
    if(mot.size() <= 26 && !contient(mot)){
        Maillon* nvMot = new Maillon;
        nvMot->mot = mot;
        nvMot->suiv = nullptr;
        if(listeMots.nb == 0){
            listeMots.tete = nvMot;
        } else {
            Maillon* ptrCourant = listeMots.tete;
            for(unsigned int i=1;i<listeMots.nb;i++){
                ptrCourant = ptrCourant->suiv;
            }
            ptrCourant->suiv = nvMot;
        }
        listeMots.nb++;
    }
}
void EnsembleC::retire(string mot){
    unsigned int i = 0;
    Maillon* ptrAjout = new Maillon;
    ptrAjout->suiv = listeMots.tete;
    listeMots.tete = ptrAjout;
    Maillon* ptrCourant = listeMots.tete;
    while(i<listeMots.nb && mot != ptrCourant->suiv->mot){
        ptrCourant = ptrCourant->suiv;
        i++;
    }
    if(i<listeMots.nb){
        Maillon* ptrCopie = ptrCourant->suiv;
        ptrCourant->suiv = ptrCourant->suiv->suiv;
        delete(ptrCopie);
        listeMots.nb--;
    }
    listeMots.tete = ptrAjout->suiv;
    delete(ptrAjout);
}
string EnsembleC::contenu(){
    Maillon* ptrCourant = listeMots.tete;
    string phrase ="";
    for(unsigned int i = 0; i<listeMots.nb; i++){
        phrase = phrase + ptrCourant->mot+" ";
        ptrCourant = ptrCourant->suiv;
    }
    return phrase;
}
string EnsembleC::contenu(unsigned int ind, char cara){
    Maillon* ptrCourant = listeMots.tete;
    string phrase = "";
    for(unsigned int i = 0; i<listeMots.nb; i++){
        if(ptrCourant->mot.at(ind-1) == cara){
            phrase += ptrCourant->mot+" ";
        }
        ptrCourant = ptrCourant->suiv;
    }
    return phrase;
}
