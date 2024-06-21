class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix_sum = 0;
        unordered_map<int, int> prefix_sum_to_count = {{0, 1}};

        int total = 0;
        for (int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            int difference = prefix_sum - k;
            total += prefix_sum_to_count[difference];
            prefix_sum_to_count[prefix_sum]++;
        }
        return total;
    }
};
