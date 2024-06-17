class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<SumPair> sum_pairs;
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            sum_pairs.emplace_back(nums1, nums2, i, 0);
        }

        priority_queue<SumPair> min_sum_pairs(sum_pairs.begin(), sum_pairs.end());
        vector<vector<int>> answer;
        answer.reserve(k);
        while (answer.size() < k) {
            SumPair sum_pair = move(min_sum_pairs.top());
            min_sum_pairs.pop();
            answer.push_back({sum_pair.elements.first, sum_pair.elements.second});

            int index_nums1 = sum_pair.indice.first;
            int index_nums2 = sum_pair.indice.second;
            if (++index_nums2 >= nums2.size()) continue;
            min_sum_pairs.emplace(nums1, nums2, index_nums1, index_nums2);
        }
        return answer;
    }

private:
    struct SumPair {
        int sum;
        pair<int, int> elements;
        pair<int, int> indice;

        SumPair(vector<int>& nums1, vector<int>& nums2, int index_nums1, int index_nums2)
            : sum(nums1[index_nums1] + nums2[index_nums2]), elements({nums1[index_nums1], nums2[index_nums2]}), indice({index_nums1, index_nums2}) {}

        bool operator<(const SumPair& other) const {
            return sum > other.sum;
        }
    };
};
