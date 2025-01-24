#include<iostream>
#include<string>
using namespace std;
class Forest{
	private:
		void tresStanding(){
			cout<<"Trees are standing.\n";
		}
		void birdFlying(){
			cout<<"Birds are flying.\n";
		}
		void birdsStanding(){
			cout<<"Birds are standing.\n";
		}
		void manMoving(){
			cout<<"man are moving.\n";
		}
		void manStanding(){
			cout<<"Man are standing.\n";
		}
	public:
		void TreeStanding(){
			tresStanding();
		}
		void BirdFlying(){
			birdFlying();
		}
		void BirdsStanding(){
			birdsStanding();
		}
		void ManMoving(){
			manMoving();
		}
		void ManStanding(){
			manStanding();
		}
};

int main(){
	Forest forest;
	int choice;
	do{
		cout<<"\n Forest activity Menu:\n";
		cout<<"1. Trees Standing\n";
		cout<<"2. Birds Flying\n";
		cout<<"3. Birds Standing\n";
		cout<<"4. Man Moving\n";
		cout<<"5. Man Standing\n";
		cout<<"6. Exit\n";
		cout<<" Enter your choice:\n";
		cin>>choice;
		switch(choice){
			case 1:
				forest.TreeStanding();
				break;
			case 2:
				forest.BirdFlying();
				break;
			case 3:
				forest.BirdsStanding();
				break;
			case 4:
				forest.ManMoving();
				break;
			case 5:
				forest.ManStanding();
				break;
			case 6:
				cout<<"Exiting the forest program...\n";
				break;
			default:
				cout<<"Invalid choice.\n";
		}
		
	}
	while(choice!=6);
	return 0;

}
