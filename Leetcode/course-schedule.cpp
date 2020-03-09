#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
#define show(a) cout<<""#a""<<" is "<<a<<endll;
int caseno=0;
#define print_case cout<<"Case "<<++caseno<<": ";
#define fout freopen("output.txt","w",stdout);
#define fin freopen("input.txt","r",stdin);
#define srt(v) sort(v.begin(),v.end());
#define greatersrt(v) sort(v.begin(),v.end(),greater<ll>())
#define pb push_back
#define mp make_pair
#define here cerr<<"here\n";
#define PI acos(-1.0)
#define ll long long
#define ld long double
#define reto exit(0);
#define sspace <<" "<<
#define print(arr) for(int i=0;i<arr.size();i++)cout<<arr[i]<<" \n"[i==arr.size()-1];
bool sortbysec(pair<int,int>a,pair<int,int>b){return a.second>b.second;}
ll gc(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lc(ll a,ll b){return a/gc(a,b)*b;}
const int primemod=1e9+7;
const ld eps=1e-9;
#define inl(x) scanf("%lld",&x)
#define in(x) scanf("%d",&x)
/**Code Goes Here**/

map<string, int>mymap;
map<int,string>mymap2;
set<string>ans;
#define sz 109
set<int>art;
vector<int>arr[sz];
bool visited[sz];
int d[sz], l[sz];
int t=0;

void articulate(int u, int par){
    l[u]=d[u]=++t;
    visited[u]=true;
    int child=0;
    for(int i=0;i<arr[u].size();i++){
        int v=arr[u][i];
        if(v==par){continue;}
        if(visited[v]){l[u]=min(l[u],d[v]);}
        else {
            articulate(v,u);
            l[u]=min(l[v],l[u]);
            if(d[u]<=l[v] and par!=-1)art.insert(u);
            child++;
        }
        if(child>1 and par==-1)art.insert(u);
    }
}

void adjclear(){
    memset(d, 0 , sizeof d);
    memset(visited, 0 , sizeof visited);
    memset(l, 0 , sizeof l);
    art.clear();
    for(int i=0;i<sz;i++){arr[i].clear();}
    mymap2.clear();
    mymap.clear();
    ans.clear();
}
int main()
{
    fout;
    int n;
    while(cin>>n and n){
    adjclear();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mymap[s]=i+1;
        mymap2[i+1]=s;
    }
    int m; cin>>m;
    while(m--){
        string x,y;
        cin>>x>>y;
        arr[mymap[x]].pb(mymap[y]);
        arr[mymap[y]].pb(mymap[x]);
    }
    articulate(1,-1);
    if(caseno)puts("");
    cout<<"City map #"<<++caseno<<": "<<art.size()<<" camera(s) found"<<endl;

    for(auto i : art){
        ans.insert(mymap2[i]);
    }
    for(auto s : ans){
        cout<<s<<endl;
    }
    }
}
