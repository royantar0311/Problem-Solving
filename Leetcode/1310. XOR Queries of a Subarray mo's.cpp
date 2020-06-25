class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
    int blockSize = sqrt(arr.size())+1;
    vector<int>sqrtblock(blockSize, 0);
    for (int i = 0; i < arr.size(); i++) {
        sqrtblock[i / blockSize] ^= arr[i];
    }
    vector<vector<int>> queries(q.size(), vector<int>(3, 0));
    for (int i = 0; i < q.size(); i++) {
        queries[i][0] = q[i][0];
        queries[i][1] = q[i][1];
        queries[i][2] = i;

    }
    sort(queries.begin(), queries.end(), [&, blockSize](vector<int> a, vector<int> b) -> bool
    {
        if (a[0] / blockSize == b[0] / blockSize) {
            return a[0] < b[0];
        }
        return a[0] / blockSize < b[0] / blockSize;
    });
    vector<int>ans(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++) {
        int q = queries[i][2];
        int left = queries[i][0];
        int lb = left / blockSize;
        int right = queries[i][1] ;
        int rb = right / blockSize;
        if (lb == rb) {
            for (int k = left; k <= right; k++)ans[q] ^= arr[k];
        }
        else {
            for (int k = left; k < blockSize * (lb + 1); k++)ans[q] ^= arr[k];
            for (int k = lb + 1; k < rb; k++)ans[q] ^= sqrtblock[k];
            for (int k = rb * blockSize; k <= right; k++)ans[q] ^= arr[k];
        }
    }
    return ans;
}
};
