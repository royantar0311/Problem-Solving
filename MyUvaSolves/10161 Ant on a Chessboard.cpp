
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define show(a) cout<<""#a""<<" is "<<a<<endl;
#define print(arr,xx)for(int i=0;i<xx;i++)cout<<arr[i]<<" \n"[i==xx-1];
#define here cout<<"here\n"; 
int caseno=0;
#define print_case cout<<"Case "<<++caseno<<": ";
#define fout freopen("output.txt","w",stdout);
#define fin freopen("input.txt","r",stdin);
#define pb push_back
#define ll long long

const int primemod=1e9+7;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll max(ll a,ll b) {return (a>b)?a:b;}
const int maxsize = 300000+9;
/**Code Goes Here**/
ll n,mid,low, up;
 
void solve(){
	low=sqrtl(n-1);
	up=low+1;
	//cout<<low<<" "<<up<<endl;
	mid=(up*up+low*low+1)/2;
	//show(mid)
	if(up%2==0){
		if(n==mid)cout<<up<<" "<<up<<endl;	
		else if(n<mid)cout<<up-(mid-n)<<" "<<up<<endl;
		else if(n>mid)cout<<up<<" "<<up-(n-mid)<<endl;
	}
	else if(up%2){
		if(n==mid)cout<<up<<" "<<up<<endl;	
		else if(n<mid)cout<<up<<" "<<up-(mid-n)<<endl;
		else if(n>mid)cout<<up-(n-mid)<<" "<<up<<endl;
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
	fastio

	while(cin>>n,n){
		solve();
	}
	///-----
}
 
#ifndef ONLINE_JUDGE
}
#endif
