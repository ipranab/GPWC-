#include<iostream>
using namespace std;
class Box{
	double width;
	public:
		friend void print(Box box);
		void setWidth(double wid){
			width=wid;
		}
};
void print(Box box){
	cout<<"width"<<box.width<<endl;
}
int main(){
	Box box;
	box.setWidth(15.6);
	print(box);
	return 0;
}
