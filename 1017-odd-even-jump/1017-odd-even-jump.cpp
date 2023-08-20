class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        const int maxn = 1e5+5;
        bool dp[maxn][2]; int n = arr.size();
        map<int, int> mp; map<int, int>::iterator it;
        
        for (int i=0; i<n; i++) dp[i][0] = dp[i][1] = false;
        dp[n-1][0] = dp[n-1][1] = true;
        mp[arr[n-1]] = n-1; mp[-1] = mp[maxn] = -1;

        int ans = 1;
        for (int i=n-2; i>=0; i--) {
            it = mp.lower_bound(arr[i]);
            if (it->second != -1) dp[i][1] = dp[it->second][0]; 

            if (it->first != arr[i]) it--;
            if (it->second != -1) dp[i][0] = dp[it->second][1]; 

            mp[arr[i]] = i;
            if (dp[i][1]) ans++;
        }

        return ans;
    }
};