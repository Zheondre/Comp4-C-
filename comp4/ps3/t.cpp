#include <iostream> 

using namespace std ; 

int main( int argc,char *argv[] ) { 

  double f, g, m1, m2, r, a, v, pos ; 
  a = v = 0 ; 
  g = 6.67e-11 ; 
  m1 = 5.974e+24 ; 
  m2 = 1.989e+30 ; 
  r = 1.496e+11 ; 
  
  f = ( g * m1 * m2 )/(r*r) ; 
  
  cout << f << endl  ; 
  
  a = f/m1  ; 
  v = v + 100 * a; 
   
  pos = 1.49e+11 ; 
  pos = pos + 100 * v ; 
  
  cout << pos << endl ; 
  /*  m2 = 6.419e+23 ; 
  r = 2.279e+11 - 1.496e+11 ; 
  
  f = ( g * m1 * m2 )/(r*r) ;

  //cout << f << endl ; 
  */
}   
