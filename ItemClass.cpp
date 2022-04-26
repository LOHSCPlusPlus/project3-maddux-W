#include <iostream>
#include <fstream>
#include <cstring>
#include "ReadUtils.h"
#include "ItemClass.h"
using namespace std;

Cereal::Cereal(){
  Calories = 0;
  Protein = 0;
  Fat = 0;
  Sodium = 0;
  Fiber = 0;
  Carbs = 0;
  Sugar = 0;
  CupsPerServing = 0;
};

void Cereal :: readCereal2(ifstream &cFile){
    cFile.get(name, Cereal::MAX_CHAR_LEN, ';');
    cFile.ignore(100,';');
    cFile >> Calories;
    cFile.ignore(100,';');
    cFile >> Protein;
    cFile.ignore(100,';');
    cFile >> Fat;
    cFile.ignore(100,';');
    cFile >> Sodium;
    cFile.ignore(100,';');
    cFile >> Fiber;
    cFile.ignore(100,';');
    cFile >> Carbs;
    cFile.ignore(100,';');
    cFile >> Sugar;
    cFile.ignore(100,';');
    cFile >> CupsPerServing;
    cFile.ignore(100,'\n');
  }

void Cereal :: printCereal(ostream &out){
    out << name << ";";
    out << Calories << ";";
    out << Protein << ";";
    out << Fat << ";";
    out << Sodium << ";";
    out << Fiber << ";";
    out << Carbs << ";";
    out << Sugar << ";";
    out << CupsPerServing << endl;
}

void Cereal :: readCerealUser(){
     cout << "Enter name: ";
 cin >> name;
  Calories = readDouble("Enter Calories: ");
  Protein = readDouble("Enter Protein: ");
  Fat = readDouble("Enter Fat: ");
  Sodium = readDouble("Enter Sodium: ");
  Fiber = readDouble("Enter Fiber: ");
  Carbs = readDouble("Enter Carbs: ");
  Sugar = readDouble("Enter Sugar: ");
  CupsPerServing = readDouble("Enter CupsPerServing: ");
}

double Cereal :: GetCalories(){
  return Calories;
}