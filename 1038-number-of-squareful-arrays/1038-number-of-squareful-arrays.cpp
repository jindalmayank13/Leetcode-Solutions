class Solution {
public:
    
    // function for checking perfect square
    
    bool is_possible(int num)
    {
        int s_root = sqrt(num);
        
        return s_root * s_root == num;
    }
    
    void permutation(vector<int> nums, int i, int n, int &count)
    {
        // base case
        
        if(i == n)
        {
            count++;
        }
        
        for(int idx = i; idx < n; idx++)
        {
            if(idx != i && nums[i] == nums[idx])
            {
                continue;
            }
            
            swap(nums[i], nums[idx]);
            
            if(i == 0 || (i > 0 && is_possible(nums[i] + nums[i - 1])))
            {
                permutation(nums, i + 1, n, count);
            }
        }
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        
        int n = nums.size();
        
        // sort the array
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        permutation(nums, 0, n, count);
        
        return count;
    }
};