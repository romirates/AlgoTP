/* 
   Fichier point.hpp

   Définition du type point en coordonnées cartésiennes
*/

#ifndef POINT_HPP
#define POINT_HPP

#include <string> // pour le type std::string

/******************************************************************************/
class Point
{
   private :
      float _x,_y; // coordonnées cartésiennes

   public :
      /* création/destruction */
      Point(); // constructeur par défaut --> point origine
      ~Point(); // destructeur
   
      std::string enChaine() const; // représentation sous forme "(x,y)"

      void deplacer(float dx, float dy); // translation de (dx,dy)
      void tourner(float phi); // rotation de phi°
}; // class Point
/******************************************************************************/

#endif // POINT_HPP
