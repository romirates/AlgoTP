// classe Ensemble générique, paramétrée par le type Mot à utiliser pour
// manipuler des ensemble de mots (par défaut : float) 
// Hypothèses sur le type Mot : 
//    - être transtypable en string
//    - admettre l'envoi dans un flux de sortie (opérateur <<)
#include <string>
template < typename Mot = std::string >
class Ensemble{
    private:
    struct Maillon{
        Maillon* suiv;
        Mot mot;
    };
    struct Chaine {
        Maillon* tete;
        unsigned int nb;
    };
    Chaine listeMots;
    public :
    EnsembleC();
    ~EnsembleC();
    bool estVide() const;
    bool contient(Mot mot) const;
    void ajoute(Mot mot);
    void retire(Mot mot);
    std::string contenu();
    std::string contenu(unsigned int, char);
};
