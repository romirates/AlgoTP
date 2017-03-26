#include <string>

class EnsembleC{
    private:
    struct Maillon{
        Maillon* suiv;
        std::string mot;
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
    bool contient(std::string mot) const;
    void ajoute(std::string mot);
    void retire(std::string mot);
    std::string contenu();
    std::string contenu(unsigned int, char);
};
