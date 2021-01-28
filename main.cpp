
#include <iostream>
#include <iomanip>
#include <functional>

int main() {
  std::function<uint64_t(uint64_t)> factorial = [&](auto n_) -> uint64_t {
    return n_ <= 1 ? 1 : n_ * factorial(n_ - 1);
  };

  auto constexpr fx(20);
  auto ff = factorial(fx);
  std::cout << "\n" << std::setw(3) << fx
            << "!: " << std::setw(20) << ff
            << '\n';
  std::cout << std::endl;

  std::function<uint64_t(uint64_t)> fibonacci = [&](uint64_t n_) -> uint64_t {
    auto rf = n_ < 2 ? n_ : fibonacci(n_ - 2) + fibonacci(n_ - 1);
    return rf;
  };

  // 0  1  2  3  4  5  6   7   8   9  10  11   12   13   14   15   16    17    18    19    20     21     22     23     24     25      26      27      28
  // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811
  auto constexpr fm(30);
  std::cout << "fibonacci sequence up to " << fm << ":\n";
  for (auto nn = 0; nn < fm + 1; ++nn) {
    auto fn = fibonacci(nn);
    std::cout << std::setw(2) << nn
              << std::setw(10) << fn
              << std::endl;
  }
  std::cout << std::endl;

  return 0;
}