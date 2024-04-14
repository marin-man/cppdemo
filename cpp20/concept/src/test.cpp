#include <concepts>
#include <iostream>
#include <iterator>
#include <vector>

// ========= Example1 ===========
template <typename T>
concept Iterable = requires(T x) {
    { begin(x) } -> std::forward_iterator;
    { end(x) } -> std::forward_iterator;
};

void printIfIterable(auto container) {
    if constexpr (Iterable<decltype(container)>) {
        for (const auto &v : container) {
            std::cout << v << ' ';
        }
        std::cout << '\n';
    }
}

// ========= Example2 ===========
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

template <Addable T> T add(T a, T b) { return a + b; }

// ========= Example3 ===========
template <typename T>
concept Comparable = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};

template <Comparable T> int compare(const T &a, const T &b) {
    if (a == b)
        return 0;
    else
        return (a < b) ? -1 : 1;
}

// ========= Example4 ===========
template <typename T>
concept StreamInsertable = requires(std::ostream &os, T a) {
    { os << a } -> std::same_as<std::ostream &>;
};

// 使用方法：
template <StreamInsertable T> void print(const T &t) {
    std::cout << t << std::endl;
}

int main() {
    std::vector<int> v(5, 1);
    printIfIterable(v);
    int x = 0;
    printIfIterable(x);
}
