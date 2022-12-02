// Name: Aveline Villaganas
// Class (CECS 282-04)
// Project Name (Program 5 - goldRabbits: BigInt using vectors and maps)
// Due Date (4/26/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from any other source. 
// I further certify that I typed each and every line of code in this program.
#ifndef BigInt_hpp
#define BigInt_hpp
#include <iostream>
#include <vector> 
#include <map> 
using namespace std; 

class BigInt{
  private: 
    vector<char> digits; 

  public:
    BigInt(); // default constructor 
    BigInt(int num); // constructor
    BigInt(string num); // overloaded constructor 
    BigInt(const BigInt &num); // copy constructor 
    ~BigInt(); // destructor 

    void print();

    // Overload Operators
    // = assignment operator 
    void operator=(BigInt num);
    void operator=(int num);
    // ==
    bool operator==(const BigInt &num)const; 
    // ==
    bool operator==(const int &num)const; 
    // < 
    bool operator<(const BigInt num)const;  
    // <=
    bool operator<=(const BigInt num)const; 
    // + 
    BigInt operator+(BigInt num); 
    // - 
    BigInt operator-(BigInt num);
    // ++ 
    void operator++(int nothing); 

    friend ostream &operator<<(ostream &out, const BigInt num);

};




#endif 