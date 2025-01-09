#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <string>

class Solution {
public:
    static int lengthOfLongestSubstring(const std::string& string) noexcept {
        assert(string.size() <= static_cast<unsigned>(std::numeric_limits<int>::max()));

        auto result = 0;

        for (auto it1 = string.cbegin(), end = string.cend(); it1 != end; ++it1) {
            auto it2 = it1;
            std::array<bool, (static_cast<std::size_t>(1) << CHAR_BIT)> chars{};

            while (it2 != end) {
                const int c = static_cast<unsigned char>(*it2);

                if (chars[c]) {
                    break;
                } else {
                    chars[c] = true;
                    it2++;
                }
            }

            result = std::max(static_cast<int>(it2 - it1), result);
        }

        return result;
    }
};

int main() {
    assert(Solution::lengthOfLongestSubstring("abcabcbb") == 3);
    assert(Solution::lengthOfLongestSubstring("bbbbb") == 1);
    assert(Solution::lengthOfLongestSubstring("pwwkew") == 3);
    assert(Solution::lengthOfLongestSubstring(" ") == 1);
    return EXIT_SUCCESS;
}
