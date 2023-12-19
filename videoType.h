#ifndef VIDEOTYPE_H
#define VIDEOTYPE_H
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <limits> 
#include <stdexcept> 
#include <cstdlib>
using namespace std;


//Video Store

class videoType{

private:
  string moviename, producer, director, prodCompany;
  int copies;
  vector<string> stars; 

public:
  videoType(const string& moviename, const vector<string>& stars, const string& producer, const string& director, const string& prodCompany, const int& copies);
  
  string getMoviename() const;
  vector<string> getStars() const;
  string getProducer() const;
  string getDirector() const;
  string getProdcompany() const;
  int getCopies() const ;
  void setCopies() ;
  void videoReturn();
  ~videoType();
  
    
  };

#endif

  
