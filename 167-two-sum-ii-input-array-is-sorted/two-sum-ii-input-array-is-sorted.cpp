class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0;
        int last = numbers.size()-1;
        while(first<=last){
            int sum =numbers[first]+numbers[last];
            if (sum>target) last--;
            else if(sum<target) first++;
            else return {first+1, last+1};
        }
        return {-1, -1};
    }
};