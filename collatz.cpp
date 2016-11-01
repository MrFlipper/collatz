#include<iostream>
#include"bigNum.h"
using namespace std;
int main(){ 
    bigNum i, j, start, end, count; 
    bigNum max[2]={0,0};
    cout<<"Start: ";
    cin>>start;
    cout<<"End: ";
    cin>>end;
    for(i=start; i<=end; i++){ 
        count = 0; //Set initial chain count to 0
        j = i;
        while(j!=1){    //Runs until j reaches 1
            count++;
            if(j.isEven())  //If J is even, divide by 2
                j.divideByTwo();
            else{
                count++;    //Else multiply by 3 and add 1. This results in an even number so divide by 2 and add 1 to count
                j = j*3;
                j++;
                j.divideByTwo();
            }
        }
        if(count>max[1]){
            max[0] = i;
            max[1] = count;
        }
    }
    cout<<"The longest Collatz Conjecture chain from "; //Overloaded ostream operator crashes program when
    cout<<start;                                        //outputting a bigNum and anything else on the same line. (needs fixing)
    cout<<" to ";
    cout<<end;
    cout<<" is ";
    cout<<max[0];
    cout<<" with a length of ";
    cout<<max[1];
    cout<<endl;
    return 0;
}
