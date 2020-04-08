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
const int maxsize = 100+9;
/**Code Goes Here**/
int lcs[maxsize][maxsize];
string lx[maxsize][maxsize];
string a,b;
void solve(){
	memset(lcs,0,sizeof lcs);
	for(int i=0;i<maxsize;i++){
		for(string j:lx[i]){
			j="";
		}
	}
	int m=a.size(); int n=b.size();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i-1]==b[j-1]){
				lcs[i][j]=1+lcs[i-1][j-1];
				lx[i][j]=lx[i-1][j-1]+a[i-1]+"";
			}
			else if(lcs[i][j-1]>lcs[i-1][j]){
				lcs[i][j]=lcs[i][j-1];
				lx[i][j]=lx[i][j-1];
			}
			else if(lcs[i-1][j]>lcs[i][j-1]){
				lcs[i][j]=lcs[i-1][j];
				lx[i][j]=lx[i-1][j];
			}
			else {
				if(lx[i][j-1].size()>lx[i-1][j].size()){
					lx[i][j]=lx[i][j-1];
				}
				else lx[i][j]=min(lx[i-1][j],lx[i][j-1]);
				 lcs[i][j]=lcs[i-1][j];
			}
		}
	}
	//cout<<lcs[m][n]<<endl;
	if(lcs[m][n])cout<<lx[m][n]<<endl;
	else cout<<":("<<endl;
	// cout<<endl;
	// for(int i=1;i<=m;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<lcs[i][j]<<lx[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
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
			print_case
			cin>>a>>b;
			solve();
		}
	///-----
}
 
#ifndef ONLINE_JUDGE
}
#endif
