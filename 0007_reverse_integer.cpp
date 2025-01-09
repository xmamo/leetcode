#include <cassert>
#include <cstdlib>
#include <limits>

class Solution {
public:
    static int reverse(int number) noexcept {
        auto reversed = 0LL;

        while (number != 0) {
            const auto rq = std::div(number, 10);
            reversed = 10 * reversed + rq.rem;
            number = rq.quot;
        }

        constexpr auto min = std::numeric_limits<int>::min();
        constexpr auto max = std::numeric_limits<int>::max();
        return reversed >= min && reversed <= max ? static_cast<int>(reversed) : 0;
    }
};

int main() {
    assert(Solution::reverse(123) == 321);
    assert(Solution::reverse(-123) == -321);
    assert(Solution::reverse(120) == 21);
    return EXIT_SUCCESS;
}
