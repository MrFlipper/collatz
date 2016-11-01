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
    void readBig();
	void printBig();
	bigNum operator+(bigNum);
    bigNum operator++(int); //postincrement
    bigNum operator++(); // preincrement
//    bigNum operator=(bigNum num2);
    bigNum operator+=(bigNum num2);
    bool operator==(bigNum num2);
    bool operator>(bigNum num2);
    bool operator<(bigNum num2);
    bool operator!=(bigNum);
    bigNum operator*(bigNum);
    bigNum divideByTwo();
    bool isEven();

private:
	int num[MAX_DIGITS];
};
