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
vector<int> count_div(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
        }
    }
    vector<int> count(n+1,1);
    for(int j=2;j<=n;j++){
        int i=j;
    for (int p = 2; p <= i; p++) {
        if (is_prime[p]) {
            int c = 0;
                while(i%p == 0) {
                    i = i / p;
                    c++;
                }
            count[j] = count[j]*(c+1);
        }
    }
    }
    return count;
}
int find(int n,vector<int>& count){
    int ans=0;
    for(int i=1;i<=n;i++){if(count[i]%2!=0){ans++;}}
    return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> count=count_div(100);
  int n;cin>>n;
  for(int i=0;i<n;i++){
  int x;cin>>x;
  cout<<find(x,count)<<endl;
  }
  return 0;
}
