class Solution {
string p,t;
int lps[1000000 + 9];
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
public:
    string shortestPalindrome(string s) {
        memset(lps,0,sizeof lps);
        t=s;
        reverse(t.begin(),t.end());
        p=s;
      
        preCompute();
        int m = kmp();
        //cout<<"debug "<<m<<endl;
    
        string ans="";
        for(int i=0;i<t.size()-m;i++){
            ans+=t[i];
        }
        return ans+s;
    }
};
