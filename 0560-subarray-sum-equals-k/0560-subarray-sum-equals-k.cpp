class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int subarraySumEqualToK = 0, subarraySum = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for(int i=0; i<n; i++){
            subarraySum += nums[i];
            if(map.find(subarraySum-k) != map.end()){
                subarraySumEqualToK += map[subarraySum-k];
            }
            map[subarraySum]++;
        }
        return subarraySumEqualToK;
    }
};