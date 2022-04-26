#include "ItemDB.h"
#include "ReadUtils.h"
#include <fstream>
#include <iostream>
using namespace std;
CerealDB :: CerealDB(){
numCereal = 0;
  readCereal();
};

 void CerealDB :: readCereal(){
    ifstream cFile("cereal.txt");
    numCereal = 0;
    while(cFile.peek() != EOF && numCereal < 100) {
        Cereals[numCereal].readCereal2(cFile);
        numCereal++;
    }
}

void CerealDB :: printArrayToScreen(){
    for (int index = 0; index < numCereal; index++) {
        cout << "Index " << index << ": ";
        Cereals[index].printCereal(cout);
    }
}

void CerealDB :: printArrayToFile(const char fileName[]) {
    ofstream outFile(fileName);
    for (int index = 0; index < numCereal; index++) {
        Cereals[index].printCereal(outFile);
    }
}

void CerealDB :: addCereal() {
  Cereals[numCereal].readCerealUser();
  numCereal++;
}

void CerealDB :: delCereal(){
  int DeleteIndex = -1;
  DeleteIndex = readInt("What Cereal index do you want to delete? ");
  for(int index = DeleteIndex; index < numCereal - 1; index++){
    Cereals[index] = Cereals[index + 1];
  }
  
  }

void CerealDB :: CerealQuestion(){
  int amount;
  int quest2;
  cout << "1. Minimum or 2. Maximum? " << endl;
  cin >> quest2;
  while(quest2 != 1 && quest2 != 2){
    cout << "1. Minimum or 2. Maximum? " << endl;
  cin >> quest2;
  }
  cout << "How much" << endl;
  cin >> amount;
   for(int index = 0; index < numCereal; index++){
    if(quest2 == 1){
      if(Cereals[index].GetCalories() > amount){
        Cereals[index].printCereal(cout);
      }
      }
     }
  }

     void CerealDB :: cerealMenu(){
  int option = 0;
  cout << "Welcome to my cereal orginization." << endl;
  while(option != 7){
  cout << "Pick an option." << endl;
  cout << "1. Print cereals" << endl;
  cout << "2. Add cereal" << endl;
  cout << "3. Delete cereal" << endl;
  cout << "4. Restore Changes" << endl;
  cout << "5. Save Changes" << endl;
  cout << "6. Print all with specific calories" << endl;
  cout << "7. Quit" << endl;
  cin >> option;
  while(option < 1 && option > 7){
  cout << "Pick an option." << endl;
  cout << "1. Print cereals" << endl;
  cout << "2. Add cereal" << endl;
  cout << "3. Delete cereal" << endl;
  cout << "4. Restore Changes" << endl;
  cout << "5. Save Changes" << endl;
  cout << "6. Print all with specific calories" << endl;
  cout << "7. Quit" << endl;
  cin >> option;
  }
  if(option == 1){
    printArrayToScreen();
  }
  if(option == 2){
    if(numCereal < MaxCereal){
    addCereal();
  }
    }
  if(option == 3){
    delCereal();
    }
    
  if(option == 4){
   readCereal();
      
  }
  if(option == 5){
    printArrayToFile("Cereal1.txt");
  }
  if(option == 6){
    CerealQuestion();
  }
  }
  }