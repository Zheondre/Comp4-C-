//  Copyright 2015 Z'heondre Calcano 
 
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "MarkovModel.hpp"
#include <map>

std::string MarkovModel::gen(std::string kgram, int T) {
  if(kgram.size() != (unsigned)_order)
    throw
      std::runtime_error(" Kgram is not of length  k");
  if(kgram.size() > (unsigned)T)
    throw
      std::runtime_error(" T s less than K");
  int i;
  std::string tempst = kgram;
  for(i = 0; i < T; i++)
    tempst += randk(kgram) ;
  return tempst;
}

void MarkovModel::printmap(std::ostream &out){

  for(std::map< std::string, int >::iterator it = _kgrams.begin(); it != _kgrams.end(); it++)
    out << it->first << " "<< it->second << "\n" ;
}

int MarkovModel::freq(std::string kgram) {
  if(kgram.size() != (unsigned)_order)
    throw
      std::runtime_error(" Kgram is not of length  k");
  return _kgrams[kgram];
}

int MarkovModel::freq(std::string kgram, char c){
  if(kgram.size() != (unsigned)_order)
    throw
      std::runtime_error(" Kgram is not of length  k");
  //if k == 0 return # of times c appears
  std::string kplus1; 
  kplus1 = kgram; 
  kgram.push_back(c);
  return _kgrams[kgram];
}

char MarkovModel::randk(std::string kgram){
  int stsize = (unsigned)_s.size();
  if(kgram.size() != (unsigned)_order)
    throw
      std::runtime_error(" Kgram is not of length  k");

  if (_kgrams.find(kgram) == _kgrams.end())
    throw
      std::runtime_error(" Kgram doesn't exist in map");

  std::string check; std::vector< char > pbvc;
  int amount, i, totalfreq, j, randpos;
  totalfreq = amount = 0;
  for(std::map< std::string,int>::iterator it = _kgrams.begin(); it != _kgrams.end(); ++it) {    
    if (it->first == kgram) {
      for (i = 0; i < stsize; i++) {
	check = kgram + _s[i];
	amount = _kgrams[check];
	totalfreq += amount;
	for (j = 0; j < amount; j++)
	  pbvc.push_back(check[check.size()-1]);
      }
      randpos = rand() % totalfreq ;
      return pbvc[randpos];
    }
  }
  return 0;
}

void MarkovModel::findAmount(std::string x) {
  if ( _kgrams.find(x) == _kgrams.end()) {
    _kgrams[x] = 1;
    // not found
  } else {
    _kgrams[x] += 1;
    // found
  }
}

int MarkovModel::order(){
  return _order;
}

void MarkovModel::sets() {
  
  int i, j, duplicate, stsize;
  stsize = (unsigned)_s.size();
  
  std::string a, b, temp;
  temp = _alphabet;
  int sizeoftemp = temp.size();
  for(i = 0; i < sizeoftemp; i++){
    duplicate = 0;
    a = temp.substr(i,1);
    for(j = 0; j < stsize; j++){
      b =_s[j];
      if( a == b )
        duplicate = 1;
    }
    if( duplicate == 0 ){
      _s.push_back(a);
      duplicate = 0;
    }
  }
  for(i = 0; i < stsize; i++)
    std::cout << _s[i] << std::endl;
}

MarkovModel::MarkovModel(std::string input, int k) { 
  int i, j, kk, pos, szofinpt; std::string x;
  
  szofinpt = (unsigned)input.size();
  _alphabet = input;
  
  _order = k;
  if(k == 0){ 
  
  
  
  
  }
  else{

	  _alphabet = input;
	  _order = k;
	  kk = k;
	  pos = szofinpt - k;
	  
	  for (i = 0; i < szofinpt-k; i++) {
		findAmount(input.substr(i,k));
		findAmount(input.substr(i,k+1));
	  }
	  
	  x = input.substr(pos,kk);
	  findAmount(x);
	  x.append(input.substr(0,1)); //K+1
	  findAmount(x);
	  pos = 0;
	  j = 1;
	  
	  for (i = input.size()-k; i< szofinpt; i++) {
		kk--;
		x = input.substr(i,kk);
		x.append(input.substr(pos,j));
		pos++; j++;
		findAmount(x);
		
		x.append(input.substr(pos,1));
		findAmount(x);//K+!	
	  }
	  std::string check; 
	  sets();
	  int sof_s = (unsigned)_s.size();
	  for(std::map< std::string,int>::iterator it = _kgrams.begin(); it != _kgrams.end(); ++it) {
		if ((unsigned)it->first.size() == (unsigned)k){ 
			x = it->first;
			for( i = 0; i < sof_s; i++) {
				check = it->first + _s[i];
		
				if ( _kgrams.find(check) == _kgrams.end() ) {
					_kgrams[check] = 0;
				}                                                                                     
		  }
		}
	  }
  }
}

