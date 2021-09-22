#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
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

ld find(vector<int>& arr){
    int n=arr.size();
    int c=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(gcd(arr[i],arr[j])<=1){c++;}
        }
    }
    int t=(n*(n-1))/2;
    return c>0?sqrtl((6.0*t)/c):0.0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n=0;
  cin>>n;
  while(n>0){
    vector<int> arr(n);
    for(int i=0;i<n;i++){cin>>arr[i];}
    ld ans=find(arr);
    if(ans==0.0){cout<<"No estimate for this data set."<<endl;}
    else{cout<<fixed<<setprecision(6)<<ans<<endl;}
    cin>>n;
  }
 return 0;
}
