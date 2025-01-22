#include<iostream>
using namespace std;
namespace lib1{
	void myName(){
	cout<<"Somu"<<endl;
	}
}
namespace lib2{
	void myName(){
	cout<<"Mani"<<endl;
	}
}
int main(){
	lib1::myName();
	lib2::myName();
	return 0;
}
