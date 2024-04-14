#include <iostream>
#include <string>

void testLikely(auto x, auto y) {
    [[likely]] if (x < y)
        std::cout << x << std::endl;
    switch (x) {
    [[unlikely]] case 1:
        std::cout << x << std::endl;
    }
}

[[nodiscard("Ignoring the return value will be valied")]] std::string
testNoDiscard() {
    return "xx";
}

int main() {
    testLikely(2, 3);
    testNoDiscard();
}
