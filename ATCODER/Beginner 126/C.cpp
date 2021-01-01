#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkOctal(int a) {

    while(a != 0) {
        int remain = a % 8;
        if(remain == 7) 
            return true;
        a = a / 8;
    }
    return false;
}

bool checkDecimal(int a) {
    
    while(a != 0) {
        int remain = a % 10;
        if(remain == 7)
            return true;
        a = a / 10;
    }
    return false;
}

int main() {
    
    int N;
    cin >> N;
    int count = 0;
    
    for(int i = 1; i <= N; i++) {
        if(checkOctal(i) || checkDecimal(i)) count++;
    }
    
    cout << N - count;
}