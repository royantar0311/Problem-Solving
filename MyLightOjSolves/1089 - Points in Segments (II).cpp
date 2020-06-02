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
const ll maxsize = 5*10000+9;	
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define inf 1<<30
ll n,q,l[maxsize],r[maxsize],points[maxsize];
void solve(){
	scanf("%lld",&n);
	scanf("%lld",&q);
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
	}
	l[n]=r[n]=inf;
	sort(l,l+n+1);
	sort(r,r+n+1);
	for(int i=0;i<q;i++){
		scanf("%lld",&points[i]);
		ll x=0,y = 0,left=0,right=n+1;
		while(left<right){
			ll mid = (left+right)/2;
			if(l[mid]>points[i]){
				right=mid;
			}
			else left=mid+1;
		}
		
		x=left;
		left=0,right=n+1;
		while(left<right){
			ll mid=(left+right)/2;
			if(r[mid]>=points[i]){
				right=mid;
			}
			else left=mid+1;
		}
		y=left;
		 printf("%d\n",x-y);
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
