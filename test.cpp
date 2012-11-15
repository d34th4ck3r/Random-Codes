/*
ID: gautam11
PROG: milk2
LANG: C++
*/

#include <iostream>
#include<stdio.h>
using namespace std;

int main () {

	freopen ("milk2.in", "r", stdin);
	freopen ("milk2.out", "w", stdout);

	int n;
	cin >> n;
	int a [2] [5005];
	int i;


	for ( i = 0; i < n; i++ ) {
		cin >> a [0] [i];
		cin >> a [1] [i];
	}

	for ( i = 0; i < n; i++ ) {
		for ( int j = i + 1; j < n; j++ ) {
			if ( a [0] [i] > a [0] [j] ) {
				int temp = a [0] [i];
				a [0] [i] = a [0] [j];
				a [0] [j] = temp;

				temp = a [1] [i];
				a [1] [i] = a [1] [j];
				a [1] [j] = temp;
			}
		}
	}

	int start_continue = a [0] [0];
	int finish_continue = a [1] [0];
	int max_continue = finish_continue - start_continue;
	int max_idle = 0;

	for ( i = 1; i < n; i++ ) {

		if ( finish_continue < a [1] [i] ) {

			if ( a [0] [i] <= finish_continue )
				finish_continue = a [1] [i];

			else {

				if ( finish_continue - start_continue > max_continue )
					max_continue = finish_continue - start_continue;

				if ( a [0] [i] - finish_continue > max_idle )
					max_idle = a [0] [i] - finish_continue;

				start_continue = a [0] [i];
				finish_continue = a [1] [i];
			}
		}
	}

	printf ("%d %d\n", max_continue, max_idle);

	return 0;

}

