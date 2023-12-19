#include "customerType.h"


//create hidden id for movies 
//instead of calling the function to keep creating a vector of mives judst have the functions need an input of the vetor so it is kept updated 
vector<customerType> createCustomerList(){
  ifstream custfile;
  custfile.open("customer.txt");
  string line;
  vector<customerType> customerList;
  vector<videoType> rented;
  if(custfile.is_open()){
    while(getline(custfile,line)){
      stringstream iss(line);
      string name;
      int accountNumber;
      getline(iss,name,',');
      iss>>accountNumber;
      customerList.emplace_back(name,accountNumber,rented);
      
    }
    custfile.close();
    
  }
  return customerList;
}

vector<videoType> createVideoList(){
  ifstream myfile;
  myfile.open("video.txt");
  
  string line;
  vector<videoType> videolist;
  if(myfile.is_open()){
    
    while(getline(myfile,line)){
      stringstream iss(line);
      string moviename, producer, director, productionCompany, star;
      vector<string> stars;
      int copies;
      int starcount = 0;
      getline(iss, moviename, ',');
      while(getline(iss, star, ',')){
        stars.push_back(star);
        starcount++;
        if(starcount >= 2)
            break;
        
      }
      getline(iss, producer, ',');
      getline(iss, director, ',' );
      getline(iss, productionCompany, ',');
      iss >> copies;
      videolist.emplace_back(moviename, stars, producer, director, productionCompany, copies);
      
    }
    myfile.close();
}
  return videolist;
      
}




void avaliableVideo(vector<videoType> &videoList){
 
  for(int i = 0; i < videoList.size(); i++){
      if(videoList[i].getCopies() > 0){
        cout <<"Title: "<<videoList[i].getMoviename() << endl;
        cout << "Stars: ";
        vector<string> stars = videoList[i].getStars();

        for(int j = 0; j < stars.size(); j++){
          cout<<stars[j];
          if(j==0)
            cout<<",";
          else
            cout<<"\n";
            
        }
        
        cout<<"Producer : "<<videoList[i].getProducer()<<endl;
        cout<< "Director: "<<videoList[i].getDirector()<<endl;
        cout<<"Production Company: "<<videoList[i].getProdcompany()<<endl;
        cout<<"Copies: "<<videoList[i].getCopies()<<endl;

        cout<<"\n"<<"\n"<<"\n";
        
      }
  }
}

  
  
  





void MainMenu(){
  
  vector<videoType> avaliableList = createVideoList();
  vector<customerType> customerList = createCustomerList();
  
  
  while(true){
    cout << "Welcome to the Video Store!" << endl;
    cout << "What would you like to do?" << endl;
    cout<<"1. Rent a video"<<endl;
    cout<<"2. Return a video"<<endl;
    cout<<"3. See Avalialble videos to rent" << endl;
    cout<<"4. Check if a video is avaliable"<<endl;
    cout<<"5. See list of your rented videos"<<endl;
    cout<<"6. Owner Login"<<endl;
    cout<<"Enter Q to quit"<<endl;
    
   
    string choice1;
    cin>>choice1;
    
    
    try {
        if (choice1 == "Q" || choice1 == "q") {
            cout << "Goodbye!" << endl;
            break;
        }

        int choice = stoi(choice1);
        switch (choice) {
            case 1:
                while(true){
                  avaliableVideo(avaliableList);
                  customerList[0].rentVideo(avaliableList);
                  cout<<"\n \n Would you like to continue renting? (Y or any character to return to Main Menu)"<<endl;
                  string c;
                  cin>>c;
                  if(!(c == "Y" || c == "y"))
                    break;
                

                }
                
                break;
                
            case 2:
                cout<<"Which video would you like to return"<<endl;
                
                break;
            case 3:
                
                break;
            case 4:
                break;
            case 5:
                customerList[0].createRentedVideoList();
              
                
                break;
            case 6:
                
                break;
            default:
                throw invalid_argument("Invalid choice. Please enter a number between 1 and 5.\n\n");
        }
    } catch (const invalid_argument& ex) {
        cout << "This Character is not valid. \n\n" << endl;
    }
}
}

int main(){
  MainMenu();
  
    
  }
  
  


