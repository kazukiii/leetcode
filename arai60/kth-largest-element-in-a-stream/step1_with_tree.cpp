#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class KthLargest {
private:
    int k;
    ordered_multiset<int> binary_search_tree;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            binary_search_tree.insert(num);
        }
    }

    int add(int val) {
        binary_search_tree.insert(val);
        auto it = binary_search_tree.find_by_order(binary_search_tree.size() - k);
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
