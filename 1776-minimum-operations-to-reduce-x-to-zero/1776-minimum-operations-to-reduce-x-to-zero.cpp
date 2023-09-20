class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int prefix=nums[0]; // Initialize the prefix sum with the first element.
        unordered_map<int, int> mp={{prefix, 0}};
        int ans = INT_MAX;

        for (int i=1; i < n; i++) {
            prefix+=nums[i];
            if (prefix>x) break;
            mp[prefix]=i;   
        }
    //    for (auto [k, v]: mp)
    //       cout<<k<<"->"<<v<<endl;

        if (mp.count(x)) ans=mp[x]+1;
    //    cout<<"x="<<x<<" idx="<<ans-1<<" ans="<<ans<<endl;

        for (int j=n-1; j >= 0; j--) {
            x-=nums[j];
            if (x<0) break;
            if (x==0) ans=min(ans, (n-j));
            int idx=-1;
            if (mp.count(x) && (idx=mp[x])<j) {
            //    cout<<"x="<<x<<" idx="<<idx<<" ans="<<idx+(n-j)+1<<endl;
                ans=min(ans, idx+1+(n-j));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
