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
#define print_case printf("Case %d: ",++caseno);//cout<<"Case "<<++caseno<<":"<<endl;
#define fout freopen("output.txt","w",stdout);
#define fin freopen("input.txt","r",stdin);
#define pb push_back
typedef long long ll;
void yesno(bool okk) {cout<<(okk?"Yes":"No")<<endl;}
const int primemod=1000000007;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
const ll maxsize = 1*100000+9;	
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define inf 1<<30
std::vector<ll>par,size;
struct edge
{
	ll u,v,cost;
	edge(ll a,ll b,ll c){
		u=a;
		v=b;
		cost=c;
	}
	bool operator<(const edge &t){
		return cost<t.cost;
	}
};
void make_set(ll x){
	par[x] = x;
	size[x]=1;
}
ll find_set(ll x){
	if(x==par[x])return x;
	return par[x]=find_set(par[x]);
}
void union_set(ll a, ll b){
	a= find_set(a);
	b = find_set(b);
	if (a != b) {
        if(size[a]>size[b])swap(a,b);
        size[b]+=size[a];
        par[a]=b;
    }
}
ll n, m,ac;
vector<edge>edges;
void solve(){
	scanf("%lld%lld%lld",&n,&m,&ac);
	edges.clear();
	par.resize(n+1);
	size.resize(n+1);
	while(m--){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(z>=ac)continue;
		edges.pb(edge(x,y,z));
	}
	sort(edges.begin(), edges.end());
	for(int i=0;i<par.size();i++)make_set(i);
	ll sum=0;
	for(int i=0,cnt=0;i<edges.size() and cnt < n-1;i++){	
		ll a= find_set(edges[i].u);
		ll b = find_set(edges[i].v);
		if(a!=b){
			sum+=edges[i].cost;
			//cout<<sum<<endl;
			union_set(a,b);
			cnt++;
		}
	}
	for(int i=1;i<par.size();i++)find_set(i);
	set<ll>s(par.begin()+1, par.end());
	printf("%lld %d\n",sum+ac*s.size(),s.size());
}
int main(){
	#ifndef ONLINE_JUDGE
	 	fin
	 	fout
 	int kase=1; 
 	while(kase--){
 	#endif   
 
 	///-----
 	 //fastio	
 	 int T;	
 	 T=1;
 	 scanf("%d",&T);
 	while(T--){
 		print_case
 		solve();
 	}
 	///-----
 }
 
 #ifndef ONLINE_JUDGE
 	fclose ( stdin );
	fclose ( stdout );
	//system ( "output.txt" );
 }			
 #endif
