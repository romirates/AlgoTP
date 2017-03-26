/* 
   Fichier point.cpp

   Définition des méthodes de Point
*/

#include "point.hpp"
#include <cmath> // utile pour les fonctions mathématiques
#include <sstream> // pour les conversions en chaine

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////
Point::Point()
{
   _x = 0.0;
   _y = 0.0;
}

/////////////////////////////////////////////////////////////////////////
Point::~Point()
{} // rien à faire

/////////////////////////////////////////////////////////////////////////
string Point::enChaine() const
{
   stringstream sst; // flux chaine pour la création du résultat
   sst << "(" << _x << "," << _y << ")"; // format : (x,y)
   return sst.str();
}

/////////////////////////////////////////////////////////////////////////
void Point::deplacer(float dx, float dy)
{
   // calcul au moyen des formules de translation 2D et enregistrement
   _x = _x + dx;
   _y = _y + dy;
}

/////////////////////////////////////////////////////////////////////////
void Point::tourner(float phi)
{
   float rx,ry; // coordonnées après rotation
   // degrés->radians
   phi = float(acos(-1.0)*phi/180.0);
   // calcul au moyen des formules de rotation 2D
   rx = _x*cos(phi) - _y*sin(phi);
   ry = _x*sin(phi) + _y*cos(phi);
   // enregistrement des nouvelles coordonnées
   _x = rx;
   _y = ry;
}
