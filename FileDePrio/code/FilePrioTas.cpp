template <typename T, int NB>
FilePrioTas<T,NB>::FilePrioTas():nbelem(0){}

template <typename T, int NB>
FilePrioTas<T,NB>::~FilePrioTas(){}

template <typename T, int NB>
bool FilePrioTas<T,NB>::estVide(){
    return (nbelem == 0);
}

template<typename T, int NB>
void FilePrioTas<T,NB>::enfiler(T elem){
    int fils = nbelem;
    int pere = (fils-1)/2;
    T temp;
    file[fils]=elem;
    while(pere >= 0 && file[pere] < file[fils]){
        temp = file[pere];
        file[pere] = file[fils];
        file[fils] = temp;
        fils = pere;
        pere = (fils-1)/2;
    }
    nbelem++;
}

template <typename T, int NB>
void FilePrioTas<T,NB>::tamiser(){
    int pere = 0;
    int fils = 1;
    T temp;
    bool fini = false;
    while(fils < nbelem && !fini){
        if(fils<nbelem-1 && file[fils+1]>file[fils]){//fils n'est pas le dernier noeud du tableau il a donc un frère droit 
            fils++;//si le fils droit est plus grand que le fils gauche on le choisi 
        }
        if(file[pere] < file[fils]){
            temp = file[pere];
            file[pere] = file[fils];
            file[fils] = temp;
            pere = fils;
            fils = 2*pere + 1;
        } else {
            fini = true;
        }
    }
}
template <typename T, int NB>
void FilePrioTas<T,NB>::defiler(){
    file[0] = file[nbelem-1];
    nbelem--;
    FilePrioTas<T>::tamiser();
}

template <typename T, int NB>
T FilePrioTas<T,NB>::premier(){
    return (file[0]);
}

template <typename T, int NB>
std::string FilePrioTas<T,NB>::contenu(){
    std::stringstream sst;
    for(int i = 0; i<nbelem;i++){
        sst << file[i];
        sst << " ";
    }
    return sst.str();
}
