class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_count;
        for (int num : nums) {
            num_to_count[num]++;
        }

        priority_queue<NumCount> min_count_and_nums;
        for (auto [num, count] : num_to_count) {
            min_count_and_nums.push({count, num});
            if (min_count_and_nums.size() > k) {
                min_count_and_nums.pop();
            }
        }

        vector<int> answer;
        while (!min_count_and_nums.empty()) {
            answer.push_back(min_count_and_nums.top().num);
            min_count_and_nums.pop();
        }
        return answer;
    }

private:
    struct NumCount {
        int count;
        int num;

        bool operator<(const NumCount& other) const {
            return count > other.count;
        }
    };
};
