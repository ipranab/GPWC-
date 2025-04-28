#include<iostream>
using namespace std;

int x[100];

int main() {
    cout << x[99] << endl;
}

//output - 0 (global arrays are initialised to 0)
