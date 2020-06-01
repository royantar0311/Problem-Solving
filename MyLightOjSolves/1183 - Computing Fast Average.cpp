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
ll tree[maxsize*4],lazy[maxsize*4];
ll query(int node, int s, int e,int i, int j){
	if(lazy[node]!=-1){
		tree[node]=lazy[node]*(e-s+1);
		if(s!=e){
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
		}
		lazy[node]=-1;
	}
	if(j<s || e<i)return 0;
	if(i<=s and e<=j)return tree[node];
	int mid = (s+e)/2;
	ll x = query(node*2,s,mid,i,j);
	ll y = query(node*2+1,mid+1,e,i,j);
	return x+y;
}
void update(int node, int s, int e, int i, int j , ll val){
	if(lazy[node]!=-1){
		tree[node]=lazy[node]*(e-s+1);
		if(s!=e){
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
		}
		lazy[node]=-1;
	}
	if(j<s || e<i)return ;
	if(i<=s and e<=j){ 
		//cout<<s<<" "<<e<<" "<<i<<" "<<j<<endl;
		tree[node]=val*(e-s+1);
		if(s!=e){
			lazy[2*node]=val;
			lazy[2*node+1]=val;
		}
		lazy[node]=-1;
		return;
	}
	int mid = (s+e)/2;
	update(node*2, s, mid,i,j,val );
	update(node*2+1, mid+1,e,i,j,val);
	tree[node] = tree[node*2]+tree[node*2+1];
}
ll n,q;
void solve(){
		memset(tree,0,sizeof tree);
		memset(lazy,-1,sizeof lazy);
		scanf("%lld%lld",&n,&q);
		while(q--){
			int type,i,j;
			ll val; 
			scanf("%d",&type);
			if(type==1){
				scanf("%d%d%lld",&i,&j,&val);
				update(1,1,n,i+1,j+1,val);
			}
			else {
				scanf("%d%d",&i,&j);
				ll x = query(1,1,n,i+1,j+1);
				ll y = j-i+1;

				if(x%y==0){
					cout<<x/y<<endl;
				}
				else {
					ll gc = __gcd(x,y);
					cout<<x/gc<<"/"<<y/gc<<endl;
				}
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
