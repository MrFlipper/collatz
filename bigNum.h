/*Header File for bigNum.cpp 
 * Written by: Rohin Singh
 * This program makes it possible to add numbers up to 100-digits long.
 */
#include<iostream>
using namespace std;
const int MAX_DIGITS = 100;
class bigNum{
public:
    bigNum();
    bigNum(int x);
    friend ostream& operator<<(ostream&, bigNum);
    friend istream& operator>>(istream&, bigNum&);
	bigNum operator+(bigNum);
    bigNum operator++(int); //postincrement
    bigNum operator++(); // preincrement
    bigNum operator+=(bigNum);
    bool operator==(bigNum);
    bool operator>(bigNum);
    bool operator<(bigNum);
    bool operator>=(bigNum);
    bool operator<=(bigNum);
    bool operator!=(bigNum);
    bigNum operator*(bigNum);
    bigNum divideByTwo(); //Divides a given bigNum by 2 (Prerequisite: bigNum is even)
    bool isEven();  //Checks if a given bigNum is even

private:
	int num[MAX_DIGITS];
};
