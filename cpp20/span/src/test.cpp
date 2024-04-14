#include <iostream>
#include <span>

void print(const std::span<const int> numbers) {
    for (const auto &num : numbers) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec = {6, 7, 8, 9, 10};
    std::array<int, 5> arry = {11, 12, 13, 14, 15};
    std::span<int, 3> sp(vec);
    auto sp1 = sp.subspan(1, 2);

    print(arr);
    print(vec);
    print(arry);
    print(sp);
    print(sp1);
}
