class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto [key, value]: count) {
            min_heap.push({value, key});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> answer;
        while (!min_heap.empty()) {
            answer.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return answer;
    }
};
