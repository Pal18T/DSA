class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0;
        int curr = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                curr+=nums[i];
            }else{
                max_sum = max(max_sum, curr);
                curr = nums[i];
            }

        }
        return max(max_sum, curr);

        
    }
};