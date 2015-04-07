// Angel Zheondre Calcano 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath> 
#include <math.h> 
#include <iostream>
#include "sierpinski.hpp" 

using namespace sf ;
using namespace std ;

int Sierpinski( double side, double depth, double p2x, double p2y, sf::RenderWindow& a ) { 

  if(depth == 0) return 0 ;
  
  double p0y, p0x, p1y, p1x, mp1x, mp1y, mp2x, mp2y, mp3x, mp3y ;
   
  double ylnd = (.866)*side ;  
  
  //p0's values, left point inner triangle
  p0y = p2y - ylnd ;
  p0x = p2x - side*(.5) ; 
   
  //p1's values, right point inner triangle  
  p1y = p2y - ylnd ; 
  p1x = p2x + side*(.5) ; 

  //Draw picture of triangle  
  ConvexShape T ;
  T.setPointCount(3) ;
  T.setPoint(0, Vector2f(p2x,p2y));
  T.setPoint(1, Vector2f(p1x,p1y));
  T.setPoint(2, Vector2f(p0x,p0y));
  T.setPosition(0,0);
  a.draw(T) ;
 
  // Find the midpoints of the other triangles 
  mp1x = p2x + side/2 ; 
  mp1y = p2y ;
  mp2x = p2x ;
  mp2y = p0y ;
  mp3x = p2x - side/2 ;
  mp3y = p2y  ;
     
  Sierpinski( side/2 , depth - 1, mp1x, mp1y, a ) ; 
  Sierpinski( side/2 , depth - 1, mp2x, mp2y, a ) ;
  Sierpinski( side/2 , depth - 1, mp3x, mp3y, a ) ;  
  
  return 0 ;  
} 
