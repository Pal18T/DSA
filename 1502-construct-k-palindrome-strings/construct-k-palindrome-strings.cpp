class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        int cnt = 0;
        unordered_map<char, int>mp;
        for(char c : s){
            mp[c]++;

        }
        for(auto i : mp){
            if(i.second%2!=0){
                cnt++;
            }
        }
        return (cnt<=k && k<=n);
    }
};