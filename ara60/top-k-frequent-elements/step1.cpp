class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> num_count;
        for (int num: nums) {
            num_count[num]++;
        }

        vector<int> buckets(n + 1, 0);
        for (auto [key, value]: num_count) {
            buckets[value]++;
        }
        for (int i = 0; i < n; ++i) {
            buckets[i + 1] += buckets[i];
        }

        vector<int> sorted(num_count.size());
        for (auto [key, value]: num_count) {
            sorted[--buckets[value]] = key;
        }

        return vector<int>(sorted.end() - k, sorted.end());
    }
};
