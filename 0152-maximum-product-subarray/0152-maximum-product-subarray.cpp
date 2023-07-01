class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=1, maxi=-1e9;
        for(int i=0; i<nums.size(); i++){
            ans*=nums[i];
            maxi=max(maxi, ans);
            if(ans==0){
                ans=1;
            }
        }
        ans=1;
        for(int i=nums.size()-1; i>=0; i--){
            ans*=nums[i];
            maxi=max(maxi, ans);
            if(ans==0){
                ans=1;
            }
        }
        return maxi;
    }
};