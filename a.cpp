#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
#define endl "\n"
const ll INF = 1000000001;

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

pair<vector<int>,vector<int>> manachers(string s){
	int n=s.size();
	vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
				k++;
		}
		d1[i] = k--;
		if (i + k > r) {
				l = i - k;
				r = i + k;
		}
	}
	
	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
				k++;
		}
		d2[i] = k--;
		if (i + k > r) {
				l = i - k - 1;
				r = i + k ;
		}
	}
	
	return {d1,d2}; //d1 is for odd;d2 is for even
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
	
	
	if(x-o>1 || x-o<0){return "invalid";}
	if(winx && wino){return "invalid";}
	if((winx && x-o!=1) || (wino && x-o!=0)){return "invalid";}
	if(!winx && !wino && x+o!=9){return "invalid";} //just this extra check from TOE1
	
	return "valid";
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //freopen("in.txt", "r", stdin); //uncomment to read & write from & to files.
  //freopen("out.txt", "w", stdout); //useful in TESTING some UVA qs(let it commented when submit)
	
	string s;cin>>s;
	while(s!="end"){
		vector<string> arr(3,"");
		arr[0]=s.substr(0,3);arr[1]=s.substr(3,3);arr[2]=s.substr(6,3);
		cout<<find(arr)<<endl;
		cin>>s;
	}
	
	return 0;
}
