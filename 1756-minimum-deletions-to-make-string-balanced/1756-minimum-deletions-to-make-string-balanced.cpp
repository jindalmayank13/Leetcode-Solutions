class Solution {
public:
    int n;
    vector<int> dp;
    
    int f(int i, int &cntA, string& s) {
        if(i==n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans=f(i+1, cntA, s);
        
        if (s[i]=='a') cntA++;
        else ans=min(ans+1, cntA);
        
        return dp[i]=ans;
    }
    
    int minimumDeletions(string& s) {
        n = s.size();
        dp.assign(n, -1); 
        int cntA=0;
        return f(0, cntA, s);
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();