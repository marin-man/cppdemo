// #include <fmt>
#include <format>
#include <iostream>
#include <source_location>
#include <string>

void testFormat() {
    std::string s = std::format("Hello, world!");
    std::cout << s << std::endl;
    s = std::format("The answer is {}.", 42);
    std::cout << s << std::endl;
    s = std::format("I'd rather be {1} than {0}.", "right", "happy");
    std::cout << s << std::endl;
}

void testSourceLocation(
    std::string_view info,
    const std::source_location &location = std::source_location::current()) {
    auto s = std::format("[{0}:{1}][{2}] {3}", location.file_name(),
                         location.line(), location.function_name(), info);
    std::cout << s << std::endl;
}

int main() {
    testFormat();
    testSourceLocation("test");
    return 0;
}
