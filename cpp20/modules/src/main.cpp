#include <concepts>
#include <vector>

#include <type_traits>

// import mymodule;

template <std::is_integral T> void sort(std::vector<T> v) {
    std::sort(v.begin(), v.end());
}

int main() {
    // hello();
    return 0;
}
