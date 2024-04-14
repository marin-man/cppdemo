#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

template <typename T> void testView(std::vector<T> const &v) {
    auto rng = v | std::views::transform([](int i) { return i * i; }) |
               std::views::filter([](int i) { return i % 2 == 1; });
    for (auto i : rng) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::vector<T> res_v(rng.begin(), rng.end());
    for (auto &i : res_v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

template <typename T> void testUnique(std::vector<T> &v) {
    auto x = std::ranges::unique(v);
    for (auto i : x) {
        std::cout << &i << ' ';
    }
    std::cout << std::endl;
    for (auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

template <typename T> void testSort(std::vector<T> &v) {
    std::ranges::sort(v);
    for (auto &i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

// template <typename T> void testGroupBy(std::vector<T> const &v) {
//     std::vector<T> rng = v | std::views::group_by;
//     for (auto &i : rng) {
//         std::cout << i << ' ';
//     }
//     std::cout << std::endl;
// }

void testIota() {
    auto numbers = std::views::iota(1) | std::views::take(10);
    for (auto n : numbers)
        std::cout << n << ' ';
    std::cout << '\n';
}

void testToupper() {
    std::string str = "hello, world!";

    auto upper =
        str | std::views::transform([](char c) { return std::toupper(c); });
    std::cout << std::string(upper.begin(), upper.end()) << std::endl;
}

int main() {
    std::vector<int> ints{0, 1, 2, 3, 4, 5};
    testView(ints);
    ints.push_back(1);
    ints.push_back(2);
    testUnique(ints);
    testSort(ints);
    testIota();
    testToupper();
}
