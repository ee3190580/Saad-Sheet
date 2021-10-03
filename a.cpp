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

int find(vector<vector<int>>& seg,int si,int sj,int ei,int ej){
	int n=seg.size();
	
	vector<pair<int,int>> adj{
		{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}
	};
	
	map<pair<int,int>,int> arr;
	
	for(int x=0;x<n;x++){
		int i=seg[x][0];
		for(int j=seg[x][1];j<=seg[x][2];j++){
			arr[{i,j}]=-1;
		}
	}
	
	arr[{si,sj}]=0;
	deque<pair<int,int>> q;
	q.push_back({si,sj});
	while(q.size()>0){
		pair<int,int> u=q.front();
		q.pop_front();
		
		for(auto incr:adj){
			pair<int,int> v= {u.first+incr.first,u.second+incr.second};
			if(arr.count({v.first,v.second})<=0){continue;}
			if(arr[{v.first,v.second}]!=-1){continue;}
			
			arr[{v.first,v.second}]=arr[{u.first,u.second}]+1;
			if(v.first==ei && v.second==ej){return arr[{v.first,v.second}];}
			q.push_back(v);
		}
	}
	return -1;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //freopen("in.txt", "r", stdin); //uncomment to read & write from & to files.
  //freopen("out.txt", "w", stdout); //useful in TESTING some UVA qs(let it commented when submit)
	
	int si,sj,ei,ej;cin>>si>>sj>>ei>>ej;
	int n;cin>>n;
	vector<vector<int>> seg(n,vector<int>(3,0));
	for(int i=0;i<n;i++){
		cin>>seg[i][0]>>seg[i][1]>>seg[i][2];
	}
	cout<<find(seg,si,sj,ei,ej)<<endl;
	return 0;
}
