#include<iostream>

using namespace std;

class Box{
	public:
	double le,br,he;
	
	double setLe(double len){
		le=l;
	}
	double setbr(double b){
		br=b;
	}
	double seth(double h){
		he=h;
	}
	double getVol(){
		return le * br * he;
	}
};

int main(){
	Box b1;
	double vol=0.0;
	b1.setLe(10.0);
	b1.setbr(20.0);
	b1.seth(30.0);
	/*b1.le=10.0;
	b1.he=14.0;
	b1.br=12.0;*/
	cout<<"Volume is: "<<b1.getVol()<<endl;
}
