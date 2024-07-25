class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        split(nums,temp,0,nums.size());
        return nums;
    }
    private:
    void split(vector<int> &nums,vector<int> &temp,int lo,int hi){
        if(hi-lo<2) return;
        int m=(hi+lo)/2;
        split(nums,temp,lo,m),split(nums,temp,m,hi);
        
        if(nums[m]>nums[m-1]) return;
        int l=lo,r=m;
        for(int i=lo;i<hi;++i){
            if(r==hi ||(l<m && nums[l]<=nums[r])) temp[i]=nums[l++];
            else temp[i]=nums[r++];
        }
        copy(begin(temp)+lo,begin(temp)+hi,begin(nums)+lo);


    }
};