/*
ID: gautam11
PROG: test
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
//	ofstream fout ("test.out");
//	ifstream fin ("test.in");
	int a[2];
	a[0]=1;
	a[1]=2;
	int *b=&a[0];
	printf("%d\n",*b);
	return 0;
}
