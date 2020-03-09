class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int v[1000][1000];
        for(int i=0 ;i <=m ; i++){ v[i][0] = 0; }
        for(int i=0 ;i <=n ; i++){ v[0][i] = 0; }
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(text1[i-1] == text2[j-1]){
                    v[i][j] = 1 + v[i-1][j-1];
                }
                else if(v[i-1][j] >= v[i][j-1]){
                    v[i][j] = v[i-1][j];

                }
                else {
                    v[i][j] = v[i][j-1];
                }
            }
        }
        return v[m][n];
    }
};