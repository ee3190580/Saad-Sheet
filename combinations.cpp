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

ll find(ll n,ll m){
    vector<ll> dp(n+1);
    for(int i=1;i<=n;i++){dp[i]=i;}
    for(int i=2;i<=m;i++){
        vector<ll> temp(n+1);
        temp[i]=1;
        for(int j=i+1;j<=n;j++){
            temp[j]=temp[j-1]+dp[j-1];
        }
        dp=temp;
    }
    return dp[n];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m;
  cin>>n>>m;
  vector<ll> res;
  while(n>0){
    //res.push_back(find(n,m));
    cout<<n<<" things taken "<<m<<" at a time is "<<find(n,m)<<" exactly."<<endl;
    cin>>n>>m;
  }
/*  for(auto x:res){
    cout<<n<<" things taken "<<m<<" at a time is "<<x<<" exactly."<<endl;
  }*/
  return 0;
}
