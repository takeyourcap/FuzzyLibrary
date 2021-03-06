/*
  FuzzyLibrary_Example1 
  
  Created by Amir Zahlan, November, 2014
  
  https://github.com/Amimaro/embFuzzyLibrary.git
  
  Released into the public domain.
*/

#include <FuzzyLibrary.h>

Fuzzy fuzzy;
uint8_t service, food, tip; //Variables
uint8_t excellent, good, poor; //Service Terms
uint8_t rancid, delicious; //Food Terms
uint8_t generous, average, cheap; //Tip Terms

void setVariables(){
  service = fuzzy.createVariable(INPUT);
  excellent = fuzzy.addTerm(service);
  good = fuzzy.addTerm(service);
  poor = fuzzy.addTerm(service);
  food = fuzzy.createVariable(INPUT);
  rancid = fuzzy.addTerm(food);
  delicious = fuzzy.addTerm(food);
  tip = fuzzy.createVariable(OUTPUT);
  generous = fuzzy.addTerm(tip);
  average = fuzzy.addTerm(tip);
  cheap = fuzzy.addTerm(tip);
}

void setPoints(){
  fuzzy.addPointsTo(poor, 0, 0, 0, 4);
  fuzzy.addPointsTo(good, 1, 4, 6, 9);
  fuzzy.addPointsTo(excellent, 6, 9, 9, 9);  
  
  fuzzy.addPointsTo(rancid, 0, 0, 1, 3);
  fuzzy.addPointsTo(delicious, 7, 9, 9, 9);
  
  fuzzy.addPointsTo(cheap, 0, 5, 5, 10);
  fuzzy.addPointsTo(average, 10, 15, 15, 20);
  fuzzy.addPointsTo(generous, 20, 25, 25, 30);
}

void createRules(){
  fuzzy.createRule(service, poor, tip, cheap);
  fuzzy.createRule(food, rancid, tip, cheap);
  fuzzy.createRule(service, good, tip, average);
  fuzzy.createRule(service, excellent, tip, generous);
  fuzzy.createRule(food, delicious, tip, generous);  
}

void setup(){
  Serial.begin(9600);  
  
  setVariables();
  setPoints();
  createRules();  
  
  fuzzy.setVariableValue(service, 9);
  fuzzy.setVariableValue(food, 9);
  Serial.println(fuzzy.calculate());
}
void loop(){

}
