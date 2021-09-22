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

int find(int a,int b,int c,int d){
    if(a>=c){return a;}
    d+=b;
    c-=a;
    int ans=a+((c/d)*b);
    int dist=c-((c/d)*d);
    if(dist==0){return ans;}
    if(dist<b){ans+=dist;}
    else{ans+=b;}
    return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<find(a,b,c,d)<<endl;
  return 0;
}
