/**
  in a directional flow graph every back edge is there with 0 capacity, if x unit of water flows, then the capacity of backedge increases 
  x unit. that means we can stop the flow of some or possibly 0 unit of water. but the mistake i made was i didn't draw the backedge. 
  it should have been in the adjacency list. 
**/

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
#define inf 1<<25
const int N = 210;
ll n;
vector<vector<int>> adj;
int capacity[N][N];
int bfs(int s, int t, vector<int>&par){
    fill(par.begin(), par.end(),-1);
    par[s]=-2;
    queue<pair<int,int>>q;
    q.push({s,inf});
    while(!q.empty()){
        int cap = q.front().se;
        int cur = q.front().fi;
        q.pop();
        //if(cur==t)return cap;
        for(auto next : adj[cur]){
            if(capacity[cur][next]>0 and par[next]==-1 ){
                par[next]=cur;
                int flow = min(capacity[cur][next],cap);
                if(next == t) return flow;
                q.push({next,flow});
            }
        }
    }
    return 0;
}
int maxflow(int s,int t){
    int flow  = 0,cur_fl;
    vector<int>par(2*n+3);
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
    for(int i=0;i<adj.size();i++)adj[i].clear();
    adj.resize(2*n+2);
    memset(capacity, 0, sizeof capacity);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        adj[i].pb(i+n);
        capacity[i][i+n]+=x;
    }
    int m;
    cin>>m;
    while(m--){
        int i, j, k;
        cin>>i>>j>>k;
        adj[i+n].pb(j);
        adj[j].pb(i+n);
        capacity[i+n][j]+=k;
    }
    int b,d;
    cin>>b>>d;
    while(b--){
        int i;
        cin>>i;
        adj[0].pb(i);
        adj[i].pb(0);
        capacity[0][i] = inf;
    }
    while(d--){
        int i;
        cin>>i;
        adj[i+n].pb(2*n+1);
        adj[2*n+1].pb(i+n);
        capacity[i+n][2*n+1] = inf;
    }
    cout<<maxflow(0,2*n+1)<<endl;
 
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
