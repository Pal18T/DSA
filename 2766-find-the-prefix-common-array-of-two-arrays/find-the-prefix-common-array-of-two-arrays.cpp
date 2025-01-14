class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        long long maskA = 0, maskB = 0;
        int cnt = 0;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            maskA |= (1ll << A[i]);
            maskB |= (1ll << B[i]);
            cnt = __builtin_popcountll(maskA & maskB);

            res[i] = cnt;
        }
        return res;
    }
};