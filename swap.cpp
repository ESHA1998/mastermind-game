//swapping function without using temp variable
#include<iostream>
using namespace std;
int main(){
	int a,b;
	cout<<"enter the two numbers you want to swap";
	cin>>a>>b;
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"Number 1: "<<a<<endl<<"Number 2: "<<b;
	return 0;
}
