#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {

	lli N;
	cin >> N;

	lli *arr = new lli[N];
	lli K;
	

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> K;

	for(int i = 0; i < N; i++) {
		if(K == arr[i]) {
			cout << i;
			break;
		}
			
	}
	
	return 0;
}
