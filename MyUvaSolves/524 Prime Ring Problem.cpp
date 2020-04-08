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
#define print_case cout<<"Case "<<++caseno<<":"<<endl;
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
const int maxsize = 100000+9;
/**Code Goes Here**/
int n;
bool primes[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
bool vis[17];
vector<int>ans;

void backTrack(int i){
	if(i==n){
		if(ans.size()==n and primes[ans.back()+1]){
			for(auto i:ans){
				if(i!=1)cout<<" ";
				cout<<i;
			}
			cout<<endl;
		} 
		return;
	}
	for(int j=2;j<=n;j++){
		if(vis[j])continue;
		if(primes[ans.back()+j]){
			vis[j]=1;
			ans.pb(j);
			backTrack(i+1);
			ans.pop_back();
			vis[j]=0;
		}

	}
}

void solve(){

	memset(vis, 0, sizeof vis);
	ans.clear();
	ans.pb(1);
	backTrack(1);

}

int main(){
	#ifndef ONLINE_JUDGE
	fout	
	fin
	int kase=1;
	while(kase--){
	#endif
    ///-----
		bool ok =0;
		cin>>n;
		while(1){
			print_case
			solve();
			
			if(cin>>n)cout<<endl;
			else exit(0);
		}
	///-----
}
 
#ifndef ONLINE_JUDGE
}
#endif
