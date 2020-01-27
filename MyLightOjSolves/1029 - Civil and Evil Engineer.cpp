#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define show(a) cout<<""#a""<<" is "<<a<<endl;
#define print(arr,xx) cout<<endl<<"debug ->";for(int i=0;i<xx;i++)cout<<arr[i].first<<" "<<arr[i].second<<" \n"[i==xx-1];
#define here cerr<<"here\n";
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
	 
int caseno=0;
#define print_case cout<<"Case "<<++caseno<<": ";
#define fout freopen("output.txt","w",stdout);
#define fin freopen("input.txt","r",stdin);
#define srt(v) sort(v.begin(),v.end());
#define greatersrt(v) sort(v.begin(),v.end(),greater<ll>())
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define ll long long
#define ld long double
#define reto exit(0);
#define sspace <<" "<<
bool sortbysec(pair<int,int>a,pair<int,int>b){return a.second>b.second;}
ll gc(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lc(ll a,ll b){return a/gc(a,b)*b;}
const int primemod=1e9+7;
const ld eps=1e-9;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define inl(x) scanf("%lld",&x
#define in(x) scanf("%d",&x)
#define pii pair<int,int>
#define rshuffle(r...)rshuffle(r,[](int _){return rand()%_;})
ll max(ll a,ll b) {return (a>b)?a:b;}
/**Code Goes Here**/
#define sz 100000
#define pii pair<int,int>
vector<vector<int> >arr,cost;
bool vis[sz];
int n;
void mst_init(int n){
    memset(vis,0,sizeof vis);
}
long long prim(int x){
    mst_init(n);
    priority_queue<pii, vector<pii> ,greater<pii> >pq;
    pq.push(pii(0,x));
    //vis[x]=1;
    ll mincost=0;
    while(!pq.empty()){

        int u = pq.top().second;
        int w = pq.top().first;
        //cout<<u<<endl;
        pq.pop();
        if(vis[u])continue;
        //show(w);
        mincost += w;
        vis[u]=1;
        for(int i=0;i<arr[u].size();i++){
                int v=arr[u][i];
        	if(!vis[v]){
                pq.push(pii(cost[u][i],arr[u][i]));
          	}
        }
    }
    return mincost;
}
long long maxprim(int x){
    mst_init(n);
    priority_queue<pii>pq;
    pq.push(pii(0,x));
    ll mincost=0;
    while(!pq.empty()){

        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(vis[u])continue;
        mincost += w;
        vis[u]=1;
        for(int i=0;i<arr[u].size();i++){
            if(!vis[arr[u][i]]){
                pq.push(pii(cost[u][i],arr[u][i]));
            }
        }
    }
    return mincost;
}

int main(){
	#ifndef ONLINE_JUDGE 
	fout 
	fin 
	int kase=1; 
	while(kase--){
	#endif
    ///-----
	int T;
    cin>>T;
    while(T--){
    cin>>n;
    int x,y,z;
    for(int i=0;i<arr.size();i++)arr[i].clear();
    for(int i=0;i<arr.size();i++)cost[i].clear();

    arr.resize(n+2);
    cost.resize(n+2);
    while(cin>>x>>y>>z and x+y+z){
        arr[x].pb(y);
        arr[y].pb(x);
        cost[x].pb(z);
        cost[y].pb(z);
    }
    print_case
    ll s=prim(0)+maxprim(0);
    if(s%2)cout<<s<<"/2"<<endl;
    else cout<<s/2<<endl;
    }
	///-----
}
 
#ifndef ONLINE_JUDGE
}
#endif
/*
intput
3
1
0 1 10
0 1 20
0 0 0
3
0 1 99
0 2 10
1 2 30
2 3 30
0 0 0
2
0 1 10
0 2 5
0 0 0
output
Case 1: 15
Case 2: 229/2
Case 3: 15
*/
