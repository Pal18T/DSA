class Solution {
public:
vector<int> Freq(string s)
    {
        vector<int> freq(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans; 
       vector<int> max_Freq_w2(26, 0); 
		for(auto &x : words2) 
        {
            vector<int> freq = Freq(x);
            for(int i = 0; i < 26; i++)
            {
                max_Freq_w2[i] = max(freq[i], max_Freq_w2[i]);
            }
        }
        
		
        for(auto &x : words1)
        {
            vector<int> freq = Freq(x);  
            bool flag = true;
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] < max_Freq_w2[i]) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(x);   
        }
        return ans;
    }
};