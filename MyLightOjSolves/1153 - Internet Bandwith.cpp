#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#ifndef ONLINE_JUDGE
#define show(a) cout<<""#a""<<" is "<<a<<endl;
#define shw(a,b)cout<<"-->"<<a<<" "<<b<<endl;
#define print(arr,xx)for(int i=0;i<xx;i++)cout<<arr[i]<<" \n"[i==xx-1];
#define here cout<<"here\n"; 
#define fastio ;
#else 
#define show(a)  ; 
#define shw(a,b) ;
#define print(arr,xx) ;
#define here 
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#endif
int caseno=0;
#define print_case cout<<"Case "<<++caseno<<": ";
#define fout freopen("output.txt","w",stdout);
#define fin freopen("input.txt","r",stdin);
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<vector<int> > vii;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
void yesno(bool okk) {cout<<(okk?"YES":"NO")<<endl;}
const int primemod=1000000007;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
const ll maxsize = 3*100000+9;	
#define fi first
#define se second
#define inf 1<<30
const int N = 105;
ll n;
int capacity[N][N];
vector<vector<int>>adj;
int bfs(int s, int t, vector<int>&par){
	fill(par.begin(), par.end(),-1);
	par[s]=-2;
	queue<pair<int,int>>q;
	q.push({s,inf});
	while(!q.empty()){
		int cap = q.front().se;
		int cur = q.front().fi;
		q.pop();
		for(auto next:adj[cur]){
			if(par[next]==-1 and capacity[cur][next]>0){
				par[next]=cur;
				int flow = min(capacity[cur][next],cap);
				if(next==t)return flow;
				q.push({next,flow});
			}
		}
	}
	return 0;
}
int maxflow(int s,int t){
	int flow  = 0,cur_fl;
	vector<int>par(n);
	while(cur_fl=bfs(s,t,par)){
		flow += cur_fl;
		int cur=t;
		while(cur!=s){
			int prev = par[cur];
			capacity[cur][prev]+=cur_fl;
			capacity[prev][cur]-=cur_fl;
			cur = prev;
		}
	}
	return flow;
}

void solve(){
	cin>>n;
	int s, t, c;
	cin>>s>>t>>c;
	--s,--t;
	memset(capacity, 0 ,sizeof capacity);
	for(auto i:adj)i.clear();
	adj.resize(n);
	while(c--){
		int u, v,cost;
		cin>>u>>v>>cost;
		--u,--v;
		capacity[u][v] += cost;
		capacity[v][u] += cost;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	//cout<<s<<t<<c<<endl;
	cout<<maxflow(s,t)<<endl;;
}
int main(){
	#ifndef ONLINE_JUDGE
 	fin
 	fout
 	#endif   
 	///-----
 	 fastio	
 	 int T;	
 	 T=1;
 	 cin>>T;
 	while(T--){
 		// yesno(solve());
 		print_case
 		solve();
 	}
 	///-----
	 return 0 ;
 }
