#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char s[1001];
    char c;
    unordered_map<char, int> mp;
    int len = 0;

  	cin.getline(s, sizeof(s)); //can't use string 
  	//class for this as we need to have 
  	//a count of spaces too

  	for(int i = 0; s[i] != '\0'; i++) {
  		mp[s[i]]++;
  	}

  	char maxChar;
  	int freq = INT_MIN;

  	for(auto itr = mp.begin(); itr != mp.end(); itr++) {
  		if(itr -> second > freq) {
  			maxChar = itr -> first;
  			freq = itr -> second;
  		}

  		else if(itr -> second == freq) {
  				if(itr -> first < maxChar) {
  					maxChar = itr -> first;
  			}
  		}
  		
  	}

  	cout << maxChar << " " << freq;
    
}

