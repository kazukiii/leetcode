#include <coroutine>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

template<std::movable T>
class Generator
{
public:
    struct promise_type
    {
        Generator<T> get_return_object()
        {
            return Generator{Handle::from_promise(*this)};
        }
        static std::suspend_always initial_suspend() noexcept
        {
            return {};
        }
        static std::suspend_always final_suspend() noexcept
        {
            return {};
        }
        std::suspend_always yield_value(T value) noexcept
        {
            current_value = std::move(value);
            return {};
        }
        // Disallow co_await in generator coroutines.
        void await_transform() = delete;
        [[noreturn]]
        static void unhandled_exception() { throw; }

        std::optional<T> current_value;
    };

    using Handle = std::coroutine_handle<promise_type>;

    explicit Generator(const Handle coroutine) :
        m_coroutine{coroutine}
    {}

    Generator() = default;
    ~Generator()
    {
        if (m_coroutine)
            m_coroutine.destroy();
    }

    Generator(const Generator&) = delete;
    Generator& operator=(const Generator&) = delete;

    Generator(Generator&& other) noexcept :
        m_coroutine{other.m_coroutine}
    {
        other.m_coroutine = {};
    }
    Generator& operator=(Generator&& other) noexcept
    {
        if (this != &other)
        {
            if (m_coroutine)
                m_coroutine.destroy();
            m_coroutine = other.m_coroutine;
            other.m_coroutine = {};
        }
        return *this;
    }

    // Range-based for loop support.
    class Iter
    {
    public:
        void operator++()
        {
            m_coroutine.resume();
        }
        const T& operator*() const
        {
            return *m_coroutine.promise().current_value;
        }
        bool operator==(std::default_sentinel_t) const
        {
            return !m_coroutine || m_coroutine.done();
        }

        explicit Iter(const Handle coroutine) :
            m_coroutine{coroutine}
        {}

    private:
        Handle m_coroutine;
    };

    Iter begin()
    {
        if (m_coroutine)
            m_coroutine.resume();
        return Iter{m_coroutine};
    }

    std::default_sentinel_t end() { return {}; }

private:
    Handle m_coroutine;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto generator = traverse_inorder(root);
        long long previous_value = std::numeric_limits<long long>::min();
        for (int value : generator) {
            if (value <= previous_value) {
                return false;
            }
            previous_value = value;
        }
        return true;
    }

private:
    Generator<int> traverse_inorder(TreeNode* root) {
        if (root->left) {
            for (int value : traverse_inorder(root->left)) {
                co_yield value;
            }
        }
        co_yield root->val;
        if (root->right) {
            for (int value : traverse_inorder(root->right)) {
                co_yield value;
            }
        }
    }
};
