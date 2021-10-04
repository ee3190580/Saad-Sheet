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

void dfs(int u,int& t,vector<vector<int>>& adj,vector<bool>& visited,vector<int>& dt){
	visited[u]=true;
	for(auto v:adj[u]){
		if(visited[v]){continue;}
		dfs(v,t,adj,visited,dt);
	}
	t+=dt[u];
}

int find(int u,int T,vector<int>& dt,vector<vector<int>>& adj,vector<vector<int>>& adj_T){
	int v=dt.size();
	int t=0;
	vector<bool> visited(v,false);
	dfs(u,t,adj,visited,dt);
	int a=t;
	t=0;
	fill(visited.begin(),visited.end(),false);
	dfs(u,t,adj_T,visited,dt);
	int b=T-(t-dt[u]);
	return b-a;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //freopen("in.txt", "r", stdin); //uncomment to read & write from & to files.
  //freopen("out.txt", "w", stdout); //useful in TESTING some UVA qs(let it commented when submit)
	
	int v,e;cin>>v>>e;
	int c=1;
	while(v!=0){
		vector<int> dt(v);
		int T=0;
		for(int i=0;i<v;i++){cin>>dt[i];T+=dt[i];}
		
		vector<vector<int>> ed(e,vector<int>(2));
		for(int i=0;i<e;i++){cin>>ed[i][1]>>ed[i][0];ed[i][0]--;ed[i][1]--;}
		
		vector<vector<int>> adj(v,vector<int>());
		vector<vector<int>> adj_T(v,vector<int>());
		for(int i=0;i<e;i++){
			adj[ed[i][0]].push_back(ed[i][1]);
			adj_T[ed[i][1]].push_back(ed[i][0]);
		}
		
		int q;cin>>q;
		cout<<"Case #"<<c++<<":"<<endl;
		while(q-->0){
			int u;cin>>u;
			cout<<find(u-1,T,dt,adj,adj_T)<<endl;
		}
		cout<<endl;
		cin>>v>>e;
	}
	
	return 0;
}
