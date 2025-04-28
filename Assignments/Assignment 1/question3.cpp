#include<iostream>
using namespace std;

int x = 1;

void fun() {
    int x = 2;
    {
        int x = 3;
        cout << ::x << endl;
    }
}

int main() {
    fun();
    return 0;
}

//output: 1 (as x initialised globally is 1 and scope resolution takes global value)
