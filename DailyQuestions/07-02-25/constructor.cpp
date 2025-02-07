#include<iostream>
using namespace std;
class Box{
	private:
		double width,length,height;
	public:
		//constructor
		Box(double w,double h,double l){
			width=w;
			height=h;
			length=l;
		}
		void print(){
			cout<<"width: "<<width<<endl;
			cout<<"height: "<<height<<endl;
			cout<<"length: "<<length<<endl;
		}
		void insertDetails(double l,double w,double h){
			width=w;
			length=l;
			height=h;
		}
		friend void callByValue(Box b);
		friend void callByReference(Box &b);
		friend void usingPtr (Box *b);
		
};
void callByValue(Box b){
	b.insertDetails(44.5,55.5,66.5);
}
int main(){
	Box box (12.5,12.4,12.3);
	box.print();
	callByValue(box);
	box.print();
}
