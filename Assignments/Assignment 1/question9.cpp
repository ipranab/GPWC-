#include<iostream>
#include<stdlib.h>
using namespace std;

class Test {
public:
    Test() { cout << "Constructor called"; }
};

int main() {
    Test *t = (Test *)malloc(sizeof(Test));
    return 0;
}

//output- error (malloc only allocates memory; it does not call constructor.)
