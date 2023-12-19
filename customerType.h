#include "videoType.h"

class customerType {

private:
  string name;
  int accountNumber;
  vector<videoType> rentedVideos;


public:
  customerType(string &name, int &accountNumber, vector<videoType> &rentedVideos);

  string getName() const;
  vector<videoType> getRentList() const;
    
  
  int getAccountNumber() const;
  void rentVideo(vector<videoType>&);
  void createRentedVideoList() const;
  
  

};