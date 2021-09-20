#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
#define endl "\n"
const ll MAX = 1000000001;

int gcd(int a,int b){
	if(b==0){return a;}
	return gcd(b,a%b);
}

vector<int> lps(string s){
	int n=s.size();
	vector<int> arr(n,0);
	
	for(int i=1;i<n;i++){
		int j=arr[i-1];
		while(j>0 && s[j]!=s[i]){
			j=arr[j-1];
		}
		if(s[j]==s[i]){
			j++;
		}
		arr[i]=j;
	}
	return arr;
}

ll find(int b,int p,int m){
	b%=m;
	ll ans=1;
	while(p>0){
		if((p&1)>0){ans=(ans*b)%m;}
		b=(b*b)%m;
		p>>=1;
	}
	return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int b,p,m;
  while(cin>>b>>p>>m){
		res.push_back(find(b,p,m));
 }
  return 0;
}
//how to take input when you don't have pre-knowledge about no. of testcases & also know symbol to that this is last input
/*
 while(cin>>b>>p>>m){
		res.push_back(find(b,p,m));
 }
	this will stop automatically when there are no more inputs. 
	In the cin>>.... part change ac. to number of input in each test case section.
*/
