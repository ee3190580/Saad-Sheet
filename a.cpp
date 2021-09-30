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

string find(vector<string>& arr){
	int x=0,o=0;
	
	bool winx=false,wino=false;
	for(int i=0;i<3;i++){
		if(arr[i]=="OOO"){wino=true;}
		if(arr[i]=="XXX"){winx=true;}
		
		string s="";
		s.push_back(arr[0][i]);
		s.push_back(arr[1][i]);
		s.push_back(arr[2][i]);
		
		if(s=="OOO"){wino=true;}
		if(s=="XXX"){winx=true;}
		
		for(int j=0;j<3;j++){
		if(arr[i][j]=='X'){x++;}
		if(arr[i][j]=='O'){o++;}
		}
	}
	
	string s="";s.push_back(arr[0][0]);s.push_back(arr[1][1]);s.push_back(arr[2][2]);
	if(s=="OOO"){wino=true;}
	if(s=="XXX"){winx=true;}
	s="";s.push_back(arr[0][2]);s.push_back(arr[1][1]);s.push_back(arr[2][0]);
	if(s=="OOO"){wino=true;}
	if(s=="XXX"){winx=true;}
	
	
	if(x-o>1 || x-o<0){return "no";}
	if(winx && wino){return "no";}
	if((winx && x-o!=1) || (wino && x-o!=0)){return "no";}
	
	return "yes";
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t;cin>>t;
	for(int i=0;i<t;i++){
		vector<string> arr(3,"");
		cin>>arr[0]>>arr[1]>>arr[2];
		cout<<find(arr)<<endl;
	}
	return 0;
}
