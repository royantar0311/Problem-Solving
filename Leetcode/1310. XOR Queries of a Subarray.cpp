class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int>prefix(arr.size() + 1 , 0), ans(queries.size());
    for (int i = 1; i < prefix.size(); i++) {
        prefix[i] = prefix[i - 1] ^ arr[i - 1];
    }
    for (int i = 0; i < queries.size(); i++) {
        int l = queries[i][0] + 1;
        int r = queries[i][1] + 1;
        ans[i] = prefix[r] ^ prefix[l - 1];
    }
    return ans;
}
};
