#include "customerType.h"




customerType::customerType(string &name, int &accountNumber, vector<videoType> &rentedVideos){
  this->name = name;
  this->accountNumber = accountNumber;
  this->rentedVideos = rentedVideos;
}

  
string customerType::getName() const {
    return name;

  }

int customerType::getAccountNumber() const {
    return accountNumber;
  }
vector<videoType> customerType::getRentList() const {
  return rentedVideos;
  
}

void customerType::rentVideo(vector<videoType> &avaliableList){


while(true){
  
  cout<<"\n"<<"\n"<<"Which video would you like to rent " << endl;
  int choice;
  cin>>choice;
  if(choice > avaliableList.size() || choice < 1){
    cout<<"\n"<<"Invalid choice" << endl;
    break;
  }
  else
  {
    avaliableList[choice-1].setCopies();
    
    videoType rentedVideo = avaliableList[choice-1];
    rentedVideos.push_back(rentedVideo);
  }
    
 
  break;

}
}

void customerType::createRentedVideoList() const{
  if(rentedVideos.size() == 0){
    cout<<"You have no rented videos"<<endl;
    return;
  }
    
  else{
    for(int i = 0; i <rentedVideos.size(); i++){
    cout<<"Title: "<<rentedVideos[i].getMoviename() << endl;
  }
  cout<<"\n"<<"\n"<<"\n";
  return;
  }

}
