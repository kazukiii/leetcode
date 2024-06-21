class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix_sum = 0;
        unordered_map<int, int> prefix_sum_count_mod_k = {{0, 1}};
        int answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            int needed = (prefix_sum % k + k) % k;
            answer += prefix_sum_count_mod_k[needed];
            prefix_sum_count_mod_k[needed]++;
        }
        return answer;
    }
};
