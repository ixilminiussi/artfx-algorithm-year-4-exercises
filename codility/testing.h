#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <ostream>
#include <ratio>
#include <vector>

inline std::ostream &operator<<(std::ostream &os, const std::vector<int> &A)
{
    os << "[ ";
    for (int a : A)
    {
        os << a << " ";
    }
    os << "]";
    return os;
}

inline void test(int X, int Y, int D, int expected, int (*func)(int, int, int))
{
    int result = func(X, Y, D);

    if (result == expected)
    {
        std::cout << "✔ PASS | ";
        std::cout << "X: " << X << ", Y: " << Y << ", D: " << D << " -> " << result << std::endl;
    }
    else
    {
        std::cout << "✘ FAIL | ";
        std::cout << "X: " << X << ", Y: " << Y << ", D: " << D << " -> " << result << " | expected : " << expected
                  << std::endl;
    }
}

inline void test(int input, int expected, int (*func)(int))
{
    int result = func(input);

    if (result == expected)
    {
        std::cout << "✔ PASS | ";
        std::cout << input << " -> " << result << std::endl;
    }
    else
    {
        std::cout << "✘ FAIL | ";
        std::cout << input << " -> " << result << " | expected : " << expected << std::endl;
    }
}

inline void test(std::vector<int> &input, int K, std::vector<int> expected,
                 std::vector<int> (*func)(std::vector<int> &, int))
{
    std::vector<int> result = func(input, K);

    if (result == expected)
    {
        std::cout << "✔ PASS | ";
        std::cout << input << ", K: " << K << " -> " << result << std::endl;
    }
    else
    {
        std::cout << "✘ FAIL | ";
        std::cout << input << ", K: " << K << " -> " << result << " | expected : " << expected << std::endl;
    }
}

inline void testP(std::vector<int> &input, int K, std::vector<int> (*func)(std::vector<int> &, int))
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    std::vector<int> result = func(input, K);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "⌛ " << duration.count() << "μs | with " << input.size() << " elements and K = " << K << std::endl;
}

inline void test(std::vector<int> &input, int expected, int (*func)(std::vector<int> &))
{
    int result = func(input);

    if (result == expected)
    {
        std::cout << "✔ PASS | ";
        (input.size() <= 15) ? std::cout << input << " -> " << result << std::endl
                             : std::cout << "n = " << input.size() << " -> " << result << std::endl;
    }
    else
    {
        std::cout << "✘ FAIL | ";
        (input.size() <= 10)
            ? std::cout << input << " -> " << result << " | expected : " << expected << std::endl
            : std::cout << "n = " << input.size() << " -> " << result << " | expected : " << expected << std::endl;
    }
}

inline void testP(std::vector<int> &input, int (*func)(std::vector<int> &))
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    int result = func(input);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "⌛ " << duration.count() << "μs | with " << input.size() << " elements." << std::endl;
}
