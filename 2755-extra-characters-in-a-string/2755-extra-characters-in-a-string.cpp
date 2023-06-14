class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // similar to word break
        set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> memo(s.size(), -1);
        
        function<int(int)> solve = [&](int i) {
            if(i == s.size()) return 0;
            if(memo[i] != -1) return memo[i];
            
            // skip this char
            int result = 1 + solve(i+1);
            
            // consider this char
            string str;
            
            for(int j=i; j<s.size(); j++) {
                str.push_back(s[j]);
                
                if(dict.count(str)) {
                    result = min(result, solve(j+1));
                }
            }
            
            return memo[i] = result;
        };
        
        return solve(0);
    }
};