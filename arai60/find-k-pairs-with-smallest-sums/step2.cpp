class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<SumPair> min_sum_pairs;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = nums1[i] + nums2[j];
                if (min_sum_pairs.size() < k) {
                    min_sum_pairs.push({sum, {nums1[i], nums2[j]}});
                } else if (min_sum_pairs.size() == k && sum < min_sum_pairs.top().sum) {
                    min_sum_pairs.pop();
                    min_sum_pairs.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }

        vector<vector<int>> answer;
        while (!min_sum_pairs.empty()) {
            answer.push_back(min_sum_pairs.top().pair);
            min_sum_pairs.pop();
        }
        return answer;
    }

private:
    struct SumPair {
        int sum;
        vector<int> pair;

        bool operator<(const SumPair& other) const {
            return sum < other.sum;
        }
    };
};
