class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, long>mp;
        for( int &num : nums1){
            mp[num]+=m;
        }
        for( int &num : nums2){
            mp[num]+=n;
        }
        int ans = 0;
        for(auto &it : mp){
            int num = it.first;
            int freq = it.second;
            if(freq%2 !=0){
                ans^=num;
            }
        }
        return ans;
    }
};