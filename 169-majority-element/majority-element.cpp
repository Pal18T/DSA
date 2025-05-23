class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int majority = nums[0];
        for(int i=1;i<n;i++){
            if(cnt==0){
                majority = nums[i];
                cnt = 1;
            } else if(nums[i]==majority) cnt++;
            else cnt--;
        }
        return majority;
    }
};