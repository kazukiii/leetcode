class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> frequency_to_num;
        for (auto& [key, value] : count) {
            frequency_to_num.push_back({value, key});
        }

        int n = frequency_to_num.size();
        quick_select(frequency_to_num, 0, n - 1, n - k);
        vector<int> answer;
        for (int i = n - 1; i >= n - k; --i) {
            answer.push_back(frequency_to_num[i].second);
        }
        return answer;
    }

private:
    void quick_select(vector<pair<int, int>>& array, int left, int right, int k) {
        while (left < right) {
            int pivot_index = partition(array, left, right);
            if (pivot_index == k) return;
            else if (pivot_index < k) left = pivot_index + 1;
            else right = pivot_index - 1;
        }
    }

    int partition(vector<pair<int, int>>& array, int left, int right) {
        int pivot_index = rand_int(left, right);
        int pivot_value = array[pivot_index].first;
        swap(array[pivot_index], array[right]);
        int store_index = left;
        for (int i = left; i < right; ++i) {
            if (array[i].first < pivot_value) {
                swap(array[i], array[store_index]);
                store_index++;
            }
        }
        swap(array[store_index], array[right]);
        return store_index;
    }

    int rand_int(int from, int to) {
        return from + rand() % (to - from + 1);
    }
};
