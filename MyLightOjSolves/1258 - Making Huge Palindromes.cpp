#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define show(a) cout<<""#a""<<" is "<<a<<endl;
#define print(arr,xx)for(int i=0;i<xx;i++)cout<<arr[i]<<" \n"[i==xx-1];
#define here cout<<"here\n";
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
string p,t;
int lps[1000000 + 9];
std::vector<int>occurances;
int kmp(){
    int T = t.size();
    int P = p.size();
    int i=0,j=0;
    while(i<T){
        if(t[i]==p[j]){
            i++;
            j++;
        }
        if(j==P){
            return P;
            if(j!=0)j=lps[j-1];
        }
        else if(i<T and p[j]!=t[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else {
                i=i+1;
            }
        }
       
    }
    return j;
}
void preCompute(){
    int P = p.size();
    int i = 1,len=0;
    lps[0]=0;
    while(i<P){
        if(p[len]==p[i]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
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
        cin >> T;
        while(T--){
            memset(lps,0,sizeof lps);
            occurances.clear();
            cin >> t;
            p=t;
            reverse(p.begin(),p.end());
            preCompute();
            //here
            int m = kmp();
            print_case
            cout<<2*t.size()-m<<endl;
           
        }
    ///-----
}
 
#ifndef ONLINE_JUDGE
}
#endif
 
 
/*
