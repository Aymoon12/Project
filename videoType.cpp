#include "videoType.h"



videoType::videoType(const string& moviename, const vector<string>& stars, const string& producer, const string& director, const string& prodCompany, const int& copies){
  this->moviename = moviename;
  this->stars = stars;
  this->producer = producer;
  this->director = director;
  this->prodCompany = prodCompany;
  this->copies = copies;
  
}

string videoType::getMoviename() const{
  return moviename;
}

vector<string> videoType::getStars() const {
  return stars;
}
string videoType::getProducer() const{
  return producer;
  
}
string videoType::getDirector() const{
  return director;
}
string videoType::getProdcompany() const{
  return prodCompany;
}
int videoType::getCopies() const {
  return copies;
}
void videoType::setCopies() {
  int copy = getCopies();
  if(copy == 0){
    cout<<"No more copies. Cannot rent."<<endl;
    copies = 0;
    return;
  }

  
  copies = copy - 1;
  
}
void videoType::videoReturn(){
  int copy = getCopies();
  copies = copy + 1;


}
videoType::~videoType(){
  
}