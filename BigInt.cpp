// Name: Aveline Villaganas
// Class (CECS 282-04)
// Project Name (Program 5 - goldRabbits: BigInt using vectors and maps)
// Due Date (4/26/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from any other source. 
// I further certify that I typed each and every line of code in this program.
#include "BigInt.h"
#include <iostream> 
#include <math.h>
#include <string> 
#include <vector> 
#include <map> 
using namespace std; 
 

/* Default Constructor */
BigInt::BigInt(){
  // Nothing. 
}

/* Constructor */
BigInt::BigInt(int num){
  int digit = 0;
  if(num == 0){
    digits.push_back('0');
  }else{
    while(num > 0){
      digit = num % 10;
      num = num / 10; 
      digits.push_back('0' + digit); 
    }
  }
}

/* Overloaded Constructor */
BigInt::BigInt(string snum){  
  for(int i = snum.length()-1 ; i >=0; i--){
    digits.push_back(snum[i]);
  }
}

/* Destructor */
BigInt::~BigInt(){
  // Dont vectors clean up after themselves? 
}

/* Copy Constructor */
BigInt::BigInt(const BigInt &num){ 
  this->digits = num.digits; 
}
 
/* Prints the value of BigInt
 * IN: None
 * OUT: None
 */
void BigInt::print(){
  vector<char>::reverse_iterator rit;
  for(rit = digits.rbegin(); rit != digits.rend(); rit++)
    cout << *rit;
  cout << endl;
}

// Operator Overloading ===========================================

/* Assignment operator
 * IN: BigInt
 * OUT: None
 */
void BigInt::operator=(const BigInt num){ 
  this->digits = num.digits; 
}

/* Assignment operator
 * IN: int
 * OUT: None
 */
void BigInt::operator=(const int num){
  BigInt temp(num); 
  this->digits = temp.digits; 
}


/* Boolean less than comparison 
 * IN: BigInt
 * OUT: boolean
 */
bool BigInt::operator<(const BigInt num)const{
  BigInt temp1 = *this; 
  BigInt temp2 = num; 
  // For uneven lengths  
  if(temp1.digits.size() > temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp2.digits.push_back('0');
    }
  }else if(temp1.digits.size() < temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp1.digits.push_back('0');
    }
  }
  string num1 = "";
  string num2 = "";
  vector<char>::reverse_iterator rit1,rit2; 

  for(rit1 = temp1.digits.rbegin(); rit1 != temp1.digits.rend(); rit1++){
    num1 += *rit1;
  }
  for(rit2 = temp2.digits.rbegin(); rit2 != temp2.digits.rend(); rit2++){
    num2 += *rit2;
  }
  if(num1 < num2){
    return true; 
  }
  return false; 
}

/* Boolean less than or equals to comparison 
 * IN: BigInt
 * OUT: boolean
 */
bool BigInt::operator<=(const BigInt num)const{
  BigInt temp1 = *this; 
  BigInt temp2 = num; 
  // For uneven lengths  
  if(temp1.digits.size() > temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp2.digits.push_back('0');
    }
  }
  if(temp1.digits.size() < temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp1.digits.push_back('0');
    }
  }   
  string num1 = "";
  string num2 = "";
  vector<char>::reverse_iterator rit1,rit2; 

  for(rit1 = temp1.digits.rbegin(); rit1 != temp1.digits.rend(); rit1++){
    num1 += *rit1;
  }
  for(rit2 = temp2.digits.rbegin(); rit2 != temp2.digits.rend(); rit2++){
    num2 += *rit2;
  }
  if(num1 <= num2){
    return true; 
  }
  return false; 
}

/* Boolean equals to comparison 
 * IN: int
 * OUT: boolean
 */
bool BigInt::operator==(const int &num) const{
  BigInt temp1 = *this; 
  BigInt temp2(num); 
  // For uneven lengths  
  if(temp1.digits.size() > temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp2.digits.push_back('0');
    }
  }else if(temp1.digits.size() < temp2.digits.size()){
    while(temp2.digits.size() != temp2.digits.size()){
      temp1.digits.push_back('0');
    }
  }
  return temp1.digits == temp2.digits;
}

/* Boolean equals to comparison 
 * IN: BigInt
 * OUT: boolean
 */
bool BigInt::operator==(const BigInt &num) const{
  BigInt temp1 = *this; 
  BigInt temp2 = num; 
  // For uneven lengths  
  if(temp1.digits.size() > temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp2.digits.push_back('0');
    }
  }else if(temp1.digits.size() < temp2.digits.size()){
    while(temp2.digits.size() != temp2.digits.size()){
      temp1.digits.push_back('0');
    }
  }
  return temp1.digits == temp2.digits;
}

/* Adds two BigInt objects together, returns a BigInt
 * IN: BigInt
 * OUT: BigInt
 */
BigInt BigInt::operator+(BigInt num){
  //cout << "here" << endl;
  BigInt temp1 = *this; 
  BigInt temp2 = num; 
  // For uneven lengths  
  if(temp1.digits.size() > temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp2.digits.push_back('0');
    }
  }else if(temp1.digits.size() < temp2.digits.size()){
    while(temp2.digits.size() != temp2.digits.size()){
      temp1.digits.push_back('0');
    }
  }
  
  bool carry = false;
  string concatNums = ""; 
  int numHolder = 0;
  int forConvert = 0; 
  for(int i = 0; i < temp1.digits.size(); i++){
    if(carry == true){
      numHolder = (temp1.digits.at(i) - '0') + (temp2.digits.at(i) - '0') + 1; 
      carry = false; 
    } else {
      numHolder = (temp1.digits.at(i) - '0') + (temp2.digits.at(i) - '0');
    }
    if(numHolder > 9){
      carry = true; 
      forConvert = numHolder % 10; 
      concatNums = to_string(forConvert) + concatNums;
    }else{
      concatNums = to_string(numHolder) + concatNums;
    }
  }
  if(carry == true){
    concatNums = '1' + concatNums;  
  }
  BigInt toBigInt(concatNums); 
  return toBigInt;
}


/* Post ++, adds one to BigInt 
 * IN: None (to differentiate to prefix)
 * OUT: None
 */
void BigInt::operator++(int nothing){
  BigInt temp1 = *this; 
  BigInt temp2 = 1; 
  // For uneven lengths  
  if(temp1.digits.size() > temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp2.digits.push_back('0');
    }
  }else if(temp1.digits.size() < temp2.digits.size()){
    while(temp2.digits.size() != temp2.digits.size()){
      temp1.digits.push_back('0');
    }
  }
  bool carry = false;
  string concatNums = ""; 
  int numHolder = 0;
  int forConvert = 0; 
  for(int i = 0; i < temp1.digits.size(); i++){
    if(carry == true){
      numHolder = (temp1.digits.at(i) - '0') + (temp2.digits.at(i) - '0') + 1; 
      carry = false; 
    } else {
      numHolder = (temp1.digits.at(i) - '0') + (temp2.digits.at(i) - '0');
    }
    if(numHolder > 9){
      carry = true; 
      forConvert = numHolder % 10; 
      concatNums = to_string(forConvert) + concatNums;
    }else{
      concatNums = to_string(numHolder) + concatNums;
    }
  }
  if(carry == true){
    concatNums = '1' + concatNums; 
  }
  BigInt toBigInt(concatNums); 
  this->digits = toBigInt.digits;
}

/* Subtracts two BigInt objects together, returns a BigInt
 * Can assume there will be no negatives
 * IN: BigInt
 * OUT: BigInt
 */
BigInt BigInt::operator-(BigInt num){
  BigInt temp1 = *this; 
  BigInt temp2 = num; 
  if(temp1.digits.size() > temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp2.digits.push_back('0');
    }
  }else if(temp1.digits.size() < temp2.digits.size()){
    while(temp1.digits.size() != temp2.digits.size()){
      temp1.digits.push_back('0');
    }
  }
  int digit = 0; 
  int digitsConcat = 0; 
  
  for(int i=0; i < temp1.digits.size(); i++){ 
    digit = (temp1.digits.at(i) - '0') - (temp2.digits.at(i) - '0');
    
    if(digit < 0){
      digit = 10 + digit; 
      temp1.digits[i+1] = (temp1.digits.at(i+1) - '1') + '0';
    }
    digitsConcat = digitsConcat + (digit * pow(10,i)); 
  } 
  BigInt returnThis(digitsConcat); 
  return returnThis; 
}

/* Out Stream << */
ostream &operator<<(ostream &out, const BigInt num){
  //cout << "i am in the os operator" << endl;
  BigInt temp1 = num; 
  int sizeOf = temp1.digits.size(); 

  if(sizeOf < 13){
    vector<char>::reverse_iterator rit;
    for(rit = temp1.digits.rbegin(); rit != temp1.digits.rend(); rit++){
      out << *rit;
    }
  }else{
    int trace = sizeOf-1; 
    int iters = 0; 
    for(int i = trace; i > sizeOf-14; i--){
      out << num.digits[i]; 
      if(i == trace){
        out << ".";
      }
      if(i == sizeOf-13){
        out << "e";
      }
    }
    out << sizeOf-1;
  }
  return out; 
}