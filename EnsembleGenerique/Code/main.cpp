#include <iostream>
#include <sstream>
#include <vector>
#include "EnsembleC.hpp"

using namespace std;

int main(){
    string texte;
    vector<EnsembleC> listePhrases(26);
    cout<<"Entrez votre texte :"<<endl;
    getline(cin, texte);
    stringstream ss(texte);
    vector<string> mots;
    string motCourant;
    while(getline(ss,motCourant,' ')){
        mots.push_back(motCourant);
    }
    for(const auto &mot : mots){
        for(unsigned int i=0; i<mot.size();i++){
            unsigned int indice = (int(mot.at(i)) - int('a'));
            if(indice == i && !(listePhrases.at(indice).contient(mot))){
                listePhrases.at(indice).ajoute(mot);
            }
        }
    }
    for(unsigned int i = 0; i<26;i++){
        cout<<"lettre "<<char(65+i)<<" en pos "<<i+1<<" : "<<listePhrases.at(i).contenu()<<endl;
    }
    cout<<listePhrases.at(int('d')-int('a')).contenu(5,'e');
}
