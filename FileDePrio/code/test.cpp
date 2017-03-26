#include "FilePrioTas.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
using namespace std;
int main(){
    FilePrioTas<> fileP;
    //remplir la file avec nb aléatoire
    for(int i = 0; i<100; i++){
        fileP.enfiler(rand()%100);
    }
    cout<<fileP.contenu()<<endl;
    fileP.enfiler(100);
    cout<<fileP.contenu()<<endl;
    cout<<fileP.premier()<<endl;
    fileP.defiler();
    cout<<fileP.contenu()<<endl;
return 0;
}
