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
void yesno(bool okk) {cout<<(okk?"YES":"NO")<<endl;}
const int primemod=1000000007;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
const ll maxsize = 3*100000+9;	
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define inf 1<<30
ll x,y,n;
void binpow(ll x,ll y, ll n){
	ll ans = 1;
	while(y){
		if(y%2){
			ans=(ans%n * x%n)%n;
			y--;
		}
		else {
			x=(x%n * x%n)%n;
			y/=2;
		}
	}
	cout<<ans<<endl;
}
void solve(){
	while(cin>>x>>y>>n)
	binpow(x,y,n);
}		

 
 	
int main(){
	#ifndef ONLINE_JUDGE
 	fin
 	fout
 	int kase=1; 
 	while(kase--){
 	#endif   
 	
 	///-----
 	 fastio	
 	 int T;	
 	 T=1;
 	 // cin>>T;
 	while(T--){
 		// yesno(solve());
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
