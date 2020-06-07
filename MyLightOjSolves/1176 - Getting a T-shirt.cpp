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
vector<vector<int>> adj(58);
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
    vector<int>par(58);
    while(cur_fl=bfs(s,t,par)){
        flow += cur_fl;
        int cur=t;
        while(cur!=s){
            int prev = par[cur];
            //capacity[cur][prev]+=cur_fl;
            capacity[prev][cur]-=cur_fl;
            cur = prev;
        }
    }
    return flow;
}
map<string, int>mmap;
 
 ll m;
void solve(){
    for(auto i: adj)i.clear();
    memset(capacity, 0 ,sizeof capacity);
   
   cin>>n>>m;
   for(int i=0;i<6;i++){
       adj[51+i].pb(57);
       adj[57].pb(51+i);
       capacity[51+i][57]=n;
       capacity[57][51+i]=n;
    }
    for(int i=1;i<=m;i++){
        string a,b;
        cin>>a>>b;
        adj[0].pb(i);
        adj[i].pb(0);
        capacity[0][i]=1;
        adj[i].pb(mmap[a]);
        adj[i].pb(mmap[b]);
        adj[mmap[b]].pb(i);
        adj[mmap[a]].pb(i);
        capacity[i][mmap[a]]=1;
        capacity[i][mmap[b]]=1;
        capacity[mmap[b]][i]=1;
        capacity[mmap[a]][i]=1;
 
    }
 
   
    //show(maxflow(0,57))
    yesno(m==maxflow(0,57));
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
        mmap["XS"]=51;
   mmap["S"]=52;
   mmap["M"]=53;
   mmap["L"]=54;
   mmap["XL"]=55;
   mmap["XXL"]=56;
     cin>>T;
    while(T--){
        // yesno(solve());
        print_case
        solve();
    }
    ///-----
     return 0 ;
 }
