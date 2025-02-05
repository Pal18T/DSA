class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        if(s1.size()!=s2.size()) return false;
        int left = 0; int right = s1.size()-1;
           while(s1[left]==s2[left]) left++;
           while(s1[right]==s2[right]) right--;
           swap(s2[right], s2[left]);
           return s1==s2;   
    }
};