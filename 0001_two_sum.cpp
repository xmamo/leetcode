#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        assert(numbers.size() <= static_cast<unsigned>(std::numeric_limits<int>::max()));

        std::vector<int> indices(numbers.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&numbers](int i1, int i2) { return numbers[i1] < numbers[i2]; });

        for (auto it1 = indices.cbegin(), end = indices.cend(); it1 != end; ++it1) {
            const auto n1 = numbers[*it1];
            const auto n2 = target - n1;
            const auto it2 = std::lower_bound(it1 + 1, end, n2, [&numbers](int i, int n) { return numbers[i] < n; });

            if (it2 != indices.cend() && numbers[*it2] == n2)
                return std::vector({*it1, *it2});
        }

        return std::vector<int>();
    }
};

int main() {
    assert(Solution::twoSum(std::vector({2, 7, 11, 15}), 9) == std::vector({0, 1}));
    assert(Solution::twoSum(std::vector({3, 2, 4}), 6) == std::vector({1, 2}));
    assert(Solution::twoSum(std::vector({3, 3}), 6) == std::vector({0, 1}));
    assert(Solution::twoSum(std::vector({3, 2, 3}), 6) == std::vector({0, 2}));
    return EXIT_SUCCESS;
}
