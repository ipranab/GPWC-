#include<iostream>
using namespace std;

class BA{
	private:
		string accholder;
		float balance;
	public:
		void insertHoldername(string name){
			accholder=name;
	}
	void insertAmt(float bal){
		balance= bal;
	}
	void deposit(float amt){
		if(amt>0){
			balance +=amt;
			cout<<"deposited balance: "<<amt<<"balance in acc: "<<balance<<endl;
		}
		else{
			cout<<"Invalid amount"<<endl;
		}
	}
	void withdraw(float amt){
		if(amt>0 && amt<=balance){
			balance -=amt;
		}
		else{
			cout<<"no money available"<<endl;
		}
	}
	void accountdetails(){
		cout<<"Account holder: "<<accholder<<endl;
		cout<<"balance: "<<balance<<endl;
	}
};

int main(){
	BA acc1;
	acc1.insertHoldername("somu");
	acc1.insertAmt(800);
	
	acc1.deposit(100);
	acc1.withdraw(200);
	
	acc1.accountdetails();
}
