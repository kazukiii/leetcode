class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix_sum = 0;
        unordered_map<int, int> prefix_sum_count = {{0, 1}};

        int answer = 0;
        for (int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            int difference = prefix_sum - k;
            answer += prefix_sum_count[difference];
            prefix_sum_count[prefix_sum]++;
        }
        return answer;
    }
};
