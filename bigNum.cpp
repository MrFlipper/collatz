/*Implementation File for bigNum.h
 * Written by: Rohin Singh
 */
#include "bigNum.h"
#include<string>
#include<iostream>
using namespace std;
bigNum::bigNum(){
    for(int i = MAX_DIGITS-1; i>=0; i--){
        num[i]=0;
    }
}
bigNum::bigNum(int x){
    int i, xlength=10, xtemp = x; //Length is intitally set to one because there must be at least one digit. X-temp is copy of x.
    for(i=0; i<=MAX_DIGITS-1; i++) // Intialize array and set all values to 0
        num[i]=0;
    for(xtemp;xtemp!=0;xtemp/=10){
        xlength++;
    }
    i=0;
    for(xlength;xlength >=0;xlength--){
        num[i] = x%10;
        x/=10;
        i++;
    }

}
bigNum bigNum::operator+(bigNum num2){
	int i, ones=0, carry=0;
	bigNum sum;
	for(i = 0; i<=MAX_DIGITS - 1; i++){
		sum.num[i]=0;
	}
	for(i = 0; i<=MAX_DIGITS - 1; i++){
		ones = num[i] + num2.num[i] + carry;
		carry = 0;
		if(ones>=10){
			carry = ones/10;
			ones = ones %10;
		}
		sum.num[i] += ones;
	}
	return sum;
}
bigNum bigNum::operator++(int){
    bigNum c = *this;
    *this = *this+1;
    return c;
}
bigNum bigNum::operator++(){
    *this = *this +1;
    return *this;
}
bigNum bigNum::operator+=(bigNum num2){
    for(int i = 0; i<=MAX_DIGITS-1; i++){
        num[i]+=num2.num[i];
        if(num[i]>=10){
            num[i]%=10;
            num[i+1]+=1;
        }
    }
}
bool bigNum::operator==(bigNum num2){
    bool success = true;
    int i = MAX_DIGITS-1;
    while(num[i] == 0 and num2.num[i] == 0){
        i--;
    }
    for(i; i>=0; i--){
        if(num[i] != num2.num[i])
            success = false;
    }
    return success;
}
bool bigNum::operator!=(bigNum num2){
    bool success = false;
    int i = MAX_DIGITS -1;
    while(num[i]==0 and num2.num[i] == 0)
        i--;
    for(i; i>=0; i--){
        if(num[i] != num2.num[i])
            success = true;
    }
    return success;
}
bool bigNum::operator>(bigNum num2){
    bool success = true;
    bool done = false;
    int i = MAX_DIGITS-1;
    while(num[i]==0 and num2.num[i]==0)
        i--;
    while(not done){
        if(num[i]==num2.num[i]){
            if(i == 0){
                success = false;
                done = true;
            }
            i--;
        }
        else if(num[i] < num2.num[i]){
            success= false;
            done = true;
        }
        else if(num[i]>num2.num[i]){
            success = true;
            done = true;
        }
    }
    return success;
}
bool bigNum::operator<(bigNum num2){
    bigNum num = *this;
    bool success = num2>num;
    return success;
}
ostream& operator<<(ostream &out, bigNum x){
    int i=MAX_DIGITS-1;
    bool found = false;
	while(x.num[i]==0) //Skip Leading zeros
		i--;
    if(i>=0){
        found = true;
	    for(i; i>=0;i--){
            out<<x.num[i];
        }
    }
    if(not found)
        out<<0;
}
istream& operator>>(istream &in, bigNum &x){
    string y;
    int i;
    in>>y;
    int end = y.length()-1;
    for(i = 0;i<=MAX_DIGITS-1;i++)
        x.num[i] = 0;
    for(i=0; i<=y.length()-1;i++){
        x.num[i] = y.at(end) - '0';
        end--;
    }
}
bigNum bigNum::operator*(bigNum num2){
    int i, j, ones=0, carry=0;
    bigNum prod;
    for(i = 0; i<= MAX_DIGITS-1; i++){
        for(j = 0; j<=MAX_DIGITS-1; j++){
            if((i+j)<MAX_DIGITS-1){
                prod.num[i+j] += num[i]*num2.num[j];
            }
            else if(num[i] != 0 and num2.num[j] != 0){
                cout<<"Overflow Error"<<endl;
                i = MAX_DIGITS;
            }
        }
    }
    for(i=0; i<=MAX_DIGITS-1; i++){
        ones = prod.num[i] % 10;
        carry = prod.num[i]/10;
        prod.num[i] = ones;
        prod.num[i+1] += carry;
    }
    return prod;
}
bigNum bigNum::divideByTwo(){
    int i = MAX_DIGITS -1;
    while(num[i]==0)
        i--;
    for(i; i>=0; i--){
        if(num[i] % 2 != 0)
            num[i-1] +=10;
        num[i] = num[i]/2;

       }
}
bool bigNum::isEven(){
    if(num[0] %2 == 0)
        return true;
    else
        return false;
}
