class Solution {
public:

   void solve(int ind,int n,vector<int>& nums,vector<int>& childGet,int k,int &ans)
    {
        if(ind==n)
        {
            int maxi=INT_MIN;
            for(int i=0;i<k;i++)
            {
                maxi=max(maxi,childGet[i]);
            }
            ans=min(ans,maxi);
            return ;
        }

        for(int i=0;i<k;i++)
        {
            childGet[i]+=nums[ind];
            solve(ind+1,n,nums,childGet,k,ans);
            childGet[i]-=nums[ind];
        }
    }
    int distributeCookies(vector<int>& nums, int k) 
    {
    
       int n=nums.size();
       int ans=INT_MAX;
       vector<int> childGet(k,0);
       solve(0,n,nums,childGet,k,ans);
       return ans;
    }
};