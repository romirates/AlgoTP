
template <typename T>
FilePrioCh<T>::FilePrioCh():tete(nullptr){}

template<typename T>
FilePrioCh<T>::~FilePrioCh(){
    FilePrioCh<T>::supprCh(tete);
}

template<typename T>
bool FilePrioCh<T>::estVide(){
    return (tete == nullptr);
}

template<typename T>
void FilePrioCh<T>::enfiler(T elem){
    tete = FilePrioCh<T>::ajout(tete,elem);
}

template < typename T >
std::string FilePrioCh<T>::contenu(){
    std::stringstream sst;
    Maillon_T * courant = tete;
    
    while (courant != nullptr){
        sst << courant->elem;
        sst << " ";
        courant = courant->suiv;
    }
    return sst.str();
}

template<typename T>
void FilePrioCh< T >::supprCh(Maillon_T* courant){
    if(courant != nullptr){
        FilePrioCh<T>::supprCh(courant->suiv);
        delete(courant);
    }
}

template<typename T>
typename FilePrioCh< T >::Maillon_T* FilePrioCh<T>::ajout(Maillon_T* courant, T elem){
    if(courant == nullptr || elem >= courant->elem){
        Maillon_T* nvElem = new Maillon_T;
        nvElem->elem = elem;
        nvElem->suiv = courant;
        return nvElem;
    }else{
        courant->suiv = ajout(courant->suiv, elem);
        return courant;
    }
}

template<typename T>
void FilePrioCh< T >::defiler(){
    Maillon_T* courant = tete;
    tete = tete->suiv;
    delete(courant);
}

template<typename T>
T FilePrioCh< T >::premier(){
    return tete->elem;
    }
