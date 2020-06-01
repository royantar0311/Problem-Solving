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
ll tree[4*maxsize],lazy[4*maxsize];
// void build(int node, int s, int e){
// 	if(s==e){
// 		tree[node]=arr[s];
// 		return;
// 	}
// 	int mid = (s+e)/2;
// 	build(node*2,s,mid);
// 	build(node*2+1,mid+1,e);
// 	tree[node]=tree[node*2]+tree[node*2+1];
// 	return;
// }
ll query(int node , int s, int e, int i, int j){
	if(lazy[node]!=0){
		tree[node]+=lazy[node]*(e-s+1);
		
		if(s!=e){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(j<s or e<i)return 0;
	if(i<=s and e<=j)return tree[node];
	int mid = (s+e)/2;
	ll x=query(node*2,s,mid,i,j);
	ll y=query(node*2+1,mid+1,e,i,j);
	return x+y;	
}
void update(int node, int s, int e, int i, int j, ll v){
	if(lazy[node]!=0){
		tree[node]+=lazy[node]*(e-s+1);
		
		if(s!=e){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(j<s or e<i)return ;
	if(i<=s and e<=j){
		tree[node]+=v*(e-s+1);
		if(s!=e){
			lazy[node*2]+=v;
			lazy[node*2+1]+=v;
		}
		return;
	}
	int mid=(s+e)/2;
	update(node*2,s,mid,i,j,v);
	update(node*2+1,mid+1,e,i,j,v);
	tree[node] = tree[node*2]+tree[node*2+1];
	return;
}
int n,q;
void solve(){
	memset(lazy, 0 , sizeof lazy);
	memset(tree, 0 , sizeof tree);
	scanf("%d%d",&n,&q);
	while(q--){
		int type,x,y;
		ll v;
		scanf("%d",&type);
		//show(type)
		if(type==0){
			scanf("%d%d%lld",&x,&y,&v);
			update(1,1,n,x+1,y+1,v);
			
		}
		else {
			scanf("%d%d",&x,&y);
			ll ktp = query(1,1,n,x+1,y+1);
			printf("%lld\n",ktp);
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
