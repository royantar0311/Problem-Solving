class Solution {
public:
    string longestPalindrome(string s) {
    string t;
    t="$";
    for(int i=0;i<s.size();i++){
        t=t+'#'+(char)s[i];
    }
    t=t+"#@";

    int c=0,r=0,mx=0,ansr=0;
    int p[1009*2]={0};
    for(int i=1; i<t.size()-1;i++){
        int mirr = 2*c-i;

        if(i<r){
            p[i]=min(r-i, p[mirr]);
        }

        while(t[i+(1+p[i])]==t[i-(1+p[i])]){
            p[i]++;
        }
        if(i+p[i]>r){
            c=i;
            r=i+p[i];
        }
        if(mx<p[i]){
            mx=p[i];
            ansr=r;
        }
    }
    string ans="";
    for(int i = (ansr-1)/2-mx; i < (ansr-1)/2 ; i++){
        ans=ans+s[i];
    }

    return ans;
        
    }
};
