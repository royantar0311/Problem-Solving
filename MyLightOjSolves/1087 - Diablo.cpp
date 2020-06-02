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
const ll maxsize = 2*1000000+9;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define inf 1<<30
ll tree[maxsize],arr[maxsize];
void update(ll x,ll val){
    for(;x<maxsize;x+=(x&-x)){
        tree[x]+=val;  
    }
}
ll query(ll x){
    ll sum=0;
    for(;x>0;x-=(x&-x)){
        sum+=tree[x];
    }
    return sum;
}
ll n,q;
void solve(){
        memset(tree,0,sizeof tree);
        scanf("%lld%lld",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            update(i,1);
        }
        while(q--){
            char type;
            ll val,i;
            getchar();
            //getchar();
            scanf("%c",&type);
            //show(type)
            if(type=='a'){
                scanf("%lld",&val);
                arr[++n]=val;
                update(n,1);
            }
            else {
                scanf("%lld",&i);
                // cout<<"first ";
                // for(int i=1;i<=n;i++){
                //  cout<<query(i)<<" ";
                // }
                // cout<<endl;
                ll left=0,ans=-1,s;
                ll right = n;
                while(left<right){
                    ll mid = (left+right)/2;
                     s = query(mid);
                    if(s>=i){
                        right=mid;
                    }
                    else left=mid+1;
                }
                // show(right)
                if(query(right)==i){
                    update(right,-1);
                    printf("%d\n",arr[right]);
                }
                else printf("none\n");
                // cout<<"Second ";
                // for(int i=1;i<=n;i++){
                //  cout<<query(i)<<" ";
                // }
                // cout<<endl;
            }
        }
 
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
