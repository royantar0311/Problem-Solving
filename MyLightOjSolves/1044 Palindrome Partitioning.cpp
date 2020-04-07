#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define show(a) cout<<""#a""<<" is "<<a<<endl;
#define print(arr,xx)for(int i=0;i<xx;i++)cout<<arr[i]<<" \n"[i==xx-1];
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
const int maxsize = 1000+9;
/**Code Goes Here**/
string t;
int n;
bool pal[maxsize][maxsize];
int cuts[maxsize];

int solve(string t){
	n=t.size();
	t="@"+t;
	memset(pal, false , sizeof pal);
	memset(cuts, INT_MAX, sizeof cuts);
	
	for(int i=1;i<=n;i++){
		pal[i][i]=true;
	}
	for(int i=1;i<=n-1;i++){
		if(t[i]==t[i+1]){
			pal[i][i+1]=true;
		}
	}
	for(int cur=3;cur<=n;cur++){
		for(int i=1;i<=n-cur+1;i++){
			int j=i+cur-1;
			if(t[i]==t[j] and pal[i+1][j-1]){
				pal[i][j]=true;
			}
		}	
	}
	

	for(int i=1;i<=n;i++){
		int mn=INT_MAX;
		if(pal[1][i]){
			cuts[i]=0;
		}
		else {
			for(int j=1;j<=i;j++){
				if(pal[j+1][i]){
					mn=min(cuts[j]+1,mn); 
				}
			}
			cuts[i]=mn;
		}
	}

	return cuts[n];
}

int main(){
	#ifndef ONLINE_JUDGE
	fout	
	fin
	int kase=1;
	while(kase--){
	#endif
	fastio
    ///-----
    	int T;
    	cin>>T;
		while(T--){
			string t;
			cin>>t;
			print_case
			cout<<solve(t)+1<<endl;
		}

	///-----
}		
#ifndef ONLINE_JUDGE
}
#endif
