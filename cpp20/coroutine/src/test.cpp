#include <coroutine>
#include <iostream>
#include <vector>

template <typename T> struct Generator {
    struct promise_type {
        T value;
        std::suspend_always yield_value(T v) {
            value = v;
            return {};
        }
        Generator get_return_object() { return Generator{this}; }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::exit(1); }
    };

    bool move_next() { return coro.resume(); }

    T current_value() { return coro.promise().value; }

    Generator(Generator &&) = default;

    ~Generator() {
        if (coro)
            coro.destroy();
    }

  private:
    explicit Generator(promise_type *p)
        : coro(std::coroutine_handle<promise_type>::from_promise(*p)) {}

    std::coroutine_handle<promise_type> coro;
};

Generator<int> range(int from, int to) {
    for (int i = from; i < to; i++) {
        co_yield i;
    }
}

int main() {
    auto r = range(1, 10);
    while (r.move_next()) {
        std::cout << r.current_value() << std::endl;
    }

    return 0;
}
