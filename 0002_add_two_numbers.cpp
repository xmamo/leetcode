#include <cassert>
#include <cstdlib>
#include <initializer_list>

struct ListNode {
    int val;
    ListNode* next;

    explicit ListNode(int val = 0, ListNode* next = nullptr) noexcept : val(val), next(next) {
        assert(val >= 0 && val <= 9);
    }
};

class Solution {
public:
    static ListNode* addTwoNumbers(const ListNode* n1, const ListNode* n2) {
        ListNode* result = nullptr;
        auto** next = &result;
        auto carry = 0;

        while (n1 != nullptr || n2 != nullptr || carry != 0) {
            auto sum = carry;

            if (n1 != nullptr) {
                sum += n1->val;
                n1 = n1->next;
            }

            if (n2 != nullptr) {
                sum += n2->val;
                n2 = n2->next;
            }

            const auto qr = std::div(sum, 10);
            *next = new ListNode(qr.rem);
            carry = qr.quot;
            next = &(*next)->next;
        }

        return result;
    }
};

static ListNode* list(std::initializer_list<int> vals) {
    ListNode* result = nullptr;
    auto** next = &result;

    for (const auto val : vals) {
        *next = new ListNode(val);
        next = &(*next)->next;
    }

    return result;
}

static bool eq(const ListNode* n1, const ListNode* n2) {
    while (true) {
        if (n1 != nullptr && n2 != nullptr) {
            if (n1->val != n2->val)
                return false;

            n1 = n1->next;
            n2 = n2->next;
        } else {
            return (n1 != nullptr) == (n2 != nullptr);
        }
    }

    return true;
}

int main() {
    assert(eq(Solution::addTwoNumbers(list({2, 4, 3}), list({5, 6, 4})), list({7, 0, 8})));
    assert(eq(Solution::addTwoNumbers(list({0}), list({0})), list({0})));
    assert(eq(Solution::addTwoNumbers(list({9, 9, 9, 9, 9, 9, 9}), list({9, 9, 9, 9})), list({8, 9, 9, 9, 0, 0, 0, 1})));
    return EXIT_SUCCESS;
}
