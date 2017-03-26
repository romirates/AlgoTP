/* 
   Fichier testPoint.cpp

   Programme illustrant l'utilisation de la bibliothèque point
*/

#include <iostream> // utile pour les entrées/sorties
#include "point.hpp" // pour utiliser le type Point

using namespace std;

// fonction principale
int main()
{
   Point p; // point qui sera déplacé au gré des demandes de l'utilisateur
   char choix; // pour récupérer le choix de l'utilisateur
   float deltax,deltay,angle; // pour les paramètres de ces demandes

   // initier la séquence d'opérations
   cout << "Point actuel : " << p.enChaine() << endl;
   cout << "(t)ranslation, (r)otation ; tout autre caractère pour quitter ? ";
   cin >> choix;
   while ((choix=='t') or (choix=='r'))
   {
      if (choix == 't')
      {
         cout << "déplacement en x : ";
         cin >> deltax;
         cout << "déplacement en y : ";
         cin >> deltay;
         p.deplacer(deltax,deltay);
      }
      else // choix == 'r'
      {
         cout << "angle de rotation : ";
         cin >> angle;
         p.tourner(angle);
      }
      cout << endl;
      cout << "Point actuel : " << p.enChaine()  << endl;
      cout << "(t)ranslation, (r)otation ; tout autre caractère pour quitter ? ";
      cin >> choix;
   }
   return 0;
} // main
