class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>arr(20004,0);
        for(int i=0;i<nums.size();i++)
        {

            arr[10002+nums[i]]++;
        }
        int j=arr.size()-1;
        while(k)
        {
            if(arr[j]!=0)
            {
                if(k-arr[j]>0)
                    k-=arr[j];
                else
                    return j-10002;
            }
            j--;
        }
        return -1;
    }
};