#include<iostream>
using namespace std;
class BA{
private:
	int acc_no;
	double acc_bal;
	double with_amt;
	
	void deposit(double amount){
		if(amount>0){
			acc_bal+=amount;
			cout<<"Deposited:"<<amount<<endl;
		}
		else{
			cout<<"Invalid deposit amount"<<endl;
		}
	}
	void withdraw(double amount){
		if(amount>0 && amount<= acc_bal){
			acc_bal-=amount;
			with_amt=amount;
			cout<<"Withdrawn"<<amount<<endl;
		}
		else{
			cout<<"Insufficient funds or invalid amount"<<endl;
		}
	}
public:
	BA(int acc_num,double initial_bal=0){
		acc_num=acc_num;
		acc_bal=initial_bal;
		with_amt=0;
	}
	void details(){
		cout<<"\n Account Number:"<<acc_no<<endl;
		cout<<"Account Balance:"<<acc_bal<<endl;
		cout<<"Last Withdrawl:"<<with_amt<<endl;
	}
	void performTransaction(char type,double amount){
		if(type=='D'|| type=='d'){
			deposit(amount);
		}
		else if(type=='W'|| type=='w'){
			withdraw(amount);
		}
		else{
			cout<<"Invalid"<<endl;
		}
	}
};
int main(){
	BA account(987654321,10000);
	cout<<"Initial Account Details:"<<endl;
	account.details();
	account.performTransaction('d',100);
	account.performTransaction('w',100);
	cout<<"Final account details"<<endl;
	account.details();
	return 0;
}
