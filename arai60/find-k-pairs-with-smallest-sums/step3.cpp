class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<SumPair> sum_pairs;
        for (int i = 0; i < nums1.size(); ++i) {
            int sum = nums1[i] + nums2[0];
            sum_pairs.push_back({sum, {nums1[i], nums2[0]}, {i, 0}});
        }

        priority_queue<SumPair> min_sum_pairs(sum_pairs.begin(), sum_pairs.end());
        vector<vector<int>> answer;
        while (answer.size() < k) {
            SumPair sum_pair = min_sum_pairs.top();
            min_sum_pairs.pop();
            answer.push_back(sum_pair.pair);

            int index_nums1 = sum_pair.indice[0];
            int index_nums2 = sum_pair.indice[1];
            if (++index_nums2 >= nums2.size()) continue;
            int sum = nums1[index_nums1] + nums2[index_nums2];
            min_sum_pairs.push({sum, {nums1[index_nums1], nums2[index_nums2]}, {index_nums1, index_nums2}});
        }
        return answer;
    }

private:
    struct SumPair {
        int sum;
        vector<int> pair;
        vector<int> indice;

        bool operator<(const SumPair& other) const {
            return sum > other.sum;
        }
    };
};
