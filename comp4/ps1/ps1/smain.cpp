/* Angel Zheondre Calcano */

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <cmath> 
#include <iostream> 
#include "sierpinski.hpp" 

using namespace sf ; 
using namespace std ; 

int main(int argc, char* argv[]) { 

  if( argc < 3 ) { 
    cout << "sierpinski [recursion-depth][side-length]" << endl ; 
    return -1 ;
    }
  int depth = atoi(argv[1]) ;
  int  w = atoi(argv[2]) ;
  
  int l = (int)(.5*sqrt(3.)*(float)w) ;

  sf::RenderWindow window(VideoMode(w,l), "Angel Zheondre Calcano ID# 01141688" ) ; 
  window.setFramerateLimit(1) ;  
  ConvexShape polygon;
  polygon.setPointCount(3);
  polygon.setPoint(0, Vector2f(w/2,0));
  polygon.setPoint(1, Vector2f(0,l));
  polygon.setPoint(2, Vector2f(w,l));
  polygon.setFillColor(Color::Black);
  polygon.setPosition(0,0);
  
  while( window.isOpen()){ 

    Event event ; 
    while( window.pollEvent(event)) { 
      if(event.type == Event::Closed ) 
	window.close() ; 
    }

    window.clear(Color::Red) ;
    window.draw(polygon);
    Sierpinski( w/2, depth, w/2, l, window) ;
    window.display() ;
  } 

  return 0 ; 
} 
