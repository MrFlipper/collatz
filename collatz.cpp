#include<iostream>
#include"bigNum.h"
#include <ctime>
using namespace std;
int interval();
int run(bigNum num);
int main(){
	int c;
	cout<<"1: Largest chain in an interval"<<endl<<"2: Single run"<<endl<<"Choice: ";
	cin>>c;
	switch (c){
		case 1:
			interval();
			break;
		case 2: 
			bigNum n;
			cout<<"N = ";
			cin>>n;
			cout<<"The Collatz chain for ";
			cout<<n;
			cout<<" is "<<run(n)<<" runs."<<endl;
			break;
	}
}
int run(bigNum num){
	int count=0;
	clock_t begin = clock();
	while (num != 1){
		if(count != 0){
		}
		count++;
		if(num.isEven())
			num.divideByTwo();
		else{
			num = num*3;
			num++;
			num.divideByTwo();
			count++;
		}
		
	}
	return count;
}
int interval(){
	bigNum i, j, start, end, count; 
   	bigNum max[2]={0,0};
	cout<<"Start: ";
	cin>>start;
	cout<<"End: ";
	cin>>end;
	clock_t begin = clock();
	for(i=start; i<=end; i++){ 
		count = 0; //Set initial chain count to 0
		j = i;
		count = run(j);
		if(count>max[1]){
			max[0] = i;
			max[1] = count;
			cout<<"New max [";
			cout<<max[1];
			cout<<"] at [";
			cout<<max[0];
			cout<<"]";
			cout<<endl;
		}
	}
	clock_t cend = clock();
	cout<<"The longest Collatz Conjecture chain from "; //Overloaded ostream operator crashes program when
	cout<<start;                                        //outputting a bigNum and anything else on the same line. (needs fixing)
	cout<<" to ";
	cout<<end;
	cout<<" is ";
	cout<<max[0];
	cout<<" with a length of ";
	cout<<max[1];
	cout<<endl;
	cout<<"Time elapsed: ";
	double elapsed = double(cend - begin) / CLOCKS_PER_SEC;
	cout<<elapsed<<endl;
}
