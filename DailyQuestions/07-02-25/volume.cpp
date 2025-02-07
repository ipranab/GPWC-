#include<iostream>
using namespace std;
class Box{
	double width,length,height;
	public:
		friend void print(Box box);
		friend void setWidth(Box &box,double wid);
		friend void setLength(Box &box,double len);
		friend void setHeight(Box &box,double he);
};
void setWidth(Box &box,double wid){
	box.width=wid;
}
void setLength(Box &box,double len){
	box.length=len;
}
void setHeight(Box &box,double he){
	box.height=he;
}
void print(Box box){
	cout<<"Volume: "<<box.width * box.height * box.length<<endl;
}
int main(){
	Box box;
	setWidth(box,15.6);
	setHeight(box,15.6);
	setLength(box,20.6);
	print(box);
	return 0;
}
