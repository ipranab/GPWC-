#include<iostream>
using namespace std;
namespace Maths{
	double sum(int a,int b){
	double add=a+b;
	cout<<"Sum of the numbers"<<add<<endl;
	return add;
	}
	double diff(int a,int b){
	double subt=b-a;
	cout<<"Difference of the numbers"<<subt<<endl;
	}
	double mul(int a,int b){
	double mult=a*b;
	cout<<"Multiplication of the numbers"<<mult<<endl;
	}
	double div(int a,int b){
	double divs=b/a;
	cout<<"Division of the numbers"<<divs<<endl;
	}
}
int main(){
	int a;
	int b;
	cout<<"enter first no."<<endl;
	cin>>a;
	cout<<"Enter second no."<<endl;
	cin>>b;
	Maths::sum(a,b);
	Maths::diff(a,b);
	Maths::mul(a,b);
	Maths::div(a,b);
	return 0;
}
