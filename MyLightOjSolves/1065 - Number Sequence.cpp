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
#define print_case printf("Case %d: ",++caseno);//cout<<"Case "<<++caseno<<":"<<endl;
#define fout freopen("output.txt","w",stdout);
#define fin freopen("input.txt","r",stdin);
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<vector<int> > vii;
void yesno(bool okk) {cout<<(okk?"YES":"NO")<<endl;}
const int primemod=1000000007;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
const ll maxsize = 3*100000+9;	

#define fi first
#define se second
#define inf 1<<30
const int N = 101;
int mod;
vii multi(vii a,vii b,int m,int p, int n){
	vector<vector<int> >res(m,vector<int>(n,0));
	for(int i=0 ; i<m ; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<p ;k++){
				res[i][j] = (res[i][j]+(a[i][k]%mod * b[k][j]%mod))%mod; 
			}
		}
	}
	return res;
}
vii power(vector<vector<int> > mat, int dim , int p){
	vector<vector<int> >I (dim,vector<int>(dim,0));
	for(int i=0;i<I.size();i++){
		I[i][i]=1;
	}
	while(p){
		if(p&1){
			I = multi(I,mat,dim,dim,dim);
			p--;
		}
		else {
			mat = multi(mat,mat,dim,dim,dim);
			p/=2;

		}
	}
	return I;
}
void solve(){
	int a,b,n,m;
	cin>>a>>b>>n>>m;
	mod = 1;
	while(m--){
		mod=mod*10;
	}
	vector<vector<int> >arr(1,vector<int>(2,0)),ans;
	arr[0][0]=a; arr[0][1]=b;
	vector<vector<int> >sp(2,vector<int>(2,0));
	sp[0][0]=0;sp[0][1]=1;
	sp[1][0]=1;sp[1][1]=1;
	
	ans = power(sp,2,n);
	arr = multi(arr,ans,1,2,2);
	printf("%d\n",arr[0][0]);
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
 	 fastio	
 	 int T;	
 	 //T=1;
 	 cin>>T;
 	while(T--){
 		// yesno(solve());
 		print_case
 		solve();
 	}
 	///-----
	 return 0 ;
 }
 
 #ifndef ONLINE_JUDGE
 }			
 #endif
