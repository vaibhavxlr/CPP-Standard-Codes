
#include <bits/stdc++.h>
typedef long long int LLI;
using namespace std;

int main() {
	//int num;
	//cin >> num;										// Reading input from STDIN
	//cout << "Input number is " << num << endl;		// Writing output to STDOUT

	LLI N;
	cin >> N;

	LLI *A = new LLI[N];

	LLI posSum = 0, posNum = 0, totalNum = 0, totalSum = 0, negSum = INT_MIN, negNum = 0;

	for(int i = 0; i < N; i++) {
		cin >> A[i];
		totalNum++;
		totalSum += A[i];
		
		if(A[i] >= 0) {
			posSum += A[i] ;
			posNum++;
		}

		if(A[i] <= 0) {
			negNum = 1;
			if(negSum < A[i]) {
				negSum = A[i];
			}
		}
	}


	if(negNum && posNum == 0)
		cout << negSum << " " << negNum;
	else
		cout << posSum << " " << posNum;
}