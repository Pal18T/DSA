class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int>freq(26, 0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']+=1;
            if(freq[s[i] -'a']==3){
                freq[s[i]-'a']-=2;
            }

        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            ans+=freq[i];
        }
        return ans;
    }
};