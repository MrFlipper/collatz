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
    for(i=start; i<end; i++){
        count = 0;
        j = i;
        while(j!=1){
            count++;
            if(j.isEven())
                j.divideByTwo();
            else{
                j = j*3;
                j++;
            }
        }
        if(count>max[1]){
            max[0] = i;
            max[1] = count;
        }
    }
    cout<<"The longest Collatz Conjecture chain from ";
    cout<<start;
    cout<<" to ";
    cout<<end;
    cout<<" is ";
    cout<<max[0];
    cout<<" with a length of ";
    cout<<max[1];
    cout<<endl;
    return 0;
}
