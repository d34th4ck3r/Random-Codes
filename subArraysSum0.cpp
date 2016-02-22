#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<set>
#include<stack>
#include<queue>
#define P(s) printf("%s\n",s)
#define Pint(n) printf("%d",n)
#define Sint(n) scanf("%d",&n)
#define TEST printf("Test Called!")
#define NL printf("\n")
typedef struct node{
	int value;
	struct node *next;
}node;

typedef struct BinaryTree{
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BinaryTree;

using namespace std;

int solution(int A[],int N){
	int start=0;
	int end=1;
	int current_sum=A[start];
	int counter=0;
	while(start<N && end<N){
		if(current_sum==0){
			counter++;
			end++;
		}
	}
}
int subArraySum(int arr[], int n, int sum)
{
	/* Initialize curr_sum as value of first element
	   and starting point as 0 */
	int curr_sum = arr[0], start = 0, i;

	/* Add elements one by one to curr_sum and if the curr_sum exceeds the
	   sum, then remove starting element */
	for (i = 1; i <= n; i++)
	{
		// If curr_sum exceeds the sum, then remove the starting elements
		while (curr_sum > sum && start < i-1)
		{
			curr_sum = curr_sum - arr[start];
			start++;
		}

		// If curr_sum becomes equal to sum, then return true
		if (curr_sum == sum)
		{
			printf ("Sum found between indexes %d and %d", start, i-1);
			return 1;
		}

		// Add this element to curr_sum
		if (i < n)
			curr_sum = curr_sum + arr[i];
	}

	// If we reach here, then no subarray
	printf("No subarray found");
	return 0;
}

int main()
{
	int N;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++){
		A[i]=0;
		cin>>A[i];
	}
//	solution(A,N);
	cout<<subArraySum(A,N,0)<<endl;
	return 0;
}
