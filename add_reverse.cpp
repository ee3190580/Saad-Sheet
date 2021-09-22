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

string find(string& a,string& b){
    if(a.size()<b.size()){swap(a,b);}
    int n=a.size(),m=b.size();
    vector<int> ans(n+1,0);
    for(int i=0;i<n;i++){
      int sum=(a[i]-'0')+ans[i];
      if(i<m){sum+=(b[i]-'0');}
      ans[i]=sum%10;
      ans[i+1]+=sum/10;
    }
    string res;
    for(int x:ans){
        if(x==0 && res.size()==0){continue;}
        res.push_back(x+'0');
    }
    int i=res.size()-1;
    while(res[i]=='0'){i--;}
    return res.substr(0,i+1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n=0;
  cin>>n;
  string a,b;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    cout<<find(a,b)<<endl;
  }
 return 0;
}
