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
#define print_case printf("Case %d:\n",++caseno);//cout<<"Case "<<++caseno<<":"<<endl;
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
#define blk 350
vector<ll>v,ans;
struct node
{
    int l;
    int r;
    int i;
};
vector<node>q;
vector<ll>freq(maxsize);
bool cmp(node  a,node b){
    if(a.l/blk != b.l/blk){
        return a.l<b.l;
    }
    return a.r<b.r;
}
ll cnt=0,l=0,r=-1;
void add(int i){
    i=v[i];
    freq[i]++;
    if(freq[i]==1){
        cnt++;
    }
    return;
}
void rem(int i){
    i=v[i];
    freq[i]--;
    if(freq[i]==0)cnt--;
    return;
}
ll n,qr,k;
void solve(){
    cnt=0,l=0,r=-1;
    scanf("%lld%lld",&n,&qr);
    v.resize(n);
    for(auto & i:v)cin>>i;
    q.resize(qr);
    ans.resize(qr);
    fill(freq.begin(),freq.end(),0);
   
    for(int i=0;i<qr;i++){
        scanf("%lld%lld",&q[i].l,&q[i].r);
        q[i].l--,q[i].r--;
        q[i].i = i;
    }
    sort(q.begin(), q.end(),cmp);
    for(int i=0;i<qr;i++){
       
        int lb = q[i].l;
        int rb = q[i].r;
        int idx = q[i].i;
        while(lb<l){
            l--,add(l);
        }
        while(r<rb){
            r++,add(r);
        }
        while(l<lb){
            rem(l),l++;
        }
        while(rb<r){
            rem(r),r--;
        }
 
        ans[idx]=cnt;
    }
    for(auto i:ans)printf("%lld\n",i);
        return;
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
