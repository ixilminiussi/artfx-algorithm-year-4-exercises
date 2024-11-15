#include "testing.h"
#include <cinttypes>
#include <iostream>

int solution(int N)
{
    int best = 0;
    int current = 0;
    bool started = false;

    while (N != 0)
    {
        if (N & 1)
        {
            if (current > best && started)
                best = current;
            current = 0;
            started = true;
        }
        else
        {
            current++;
        }

        N = N >> 1;
    }

    return best;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << " -> " << solution(std::strtoimax(argv[i], NULL, 10)) << std::endl;
    }

    if (argc > 1)
        return 0;

    std::cout << "Use program arguments to try your own inputs:" << std::endl;
    std::cout << "  ie ./exercise-1 10 22 1024 526342" << std::endl << std::endl;
    std::cout << "RUNNING TESTS" << std::endl;
    std::cout << std::endl << "Basic Examples :" << std::endl;
    test(1041, 5, &solution);
    test(15, 0, &solution);
    test(32, 0, &solution);

    std::cout << std::endl << "Extremes :" << std::endl;
    test(1, 0, &solution);
    test(2147483647, 0, &solution);

    std::cout << std::endl << "Trailing zeroes :" << std::endl;
    test(6, 0, &solution);
    test(328, 2, &solution);

    std::cout << std::endl << "Power of 2 :" << std::endl;
    test(16, 0, &solution);
    test(1024, 0, &solution);

    std::cout << std::endl << "Simple :" << std::endl;
    test(9, 2, &solution);
    test(11, 1, &solution);
    test(19, 2, &solution);
    test(42, 1, &solution);
    test(1162, 3, &solution);

    std::cout << std::endl << "Medium :" << std::endl;
    test(51712, 2, &solution);
    test(561892, 3, &solution);
    test(66561, 9, &solution);

    std::cout << std::endl << "Large :" << std::endl;
    test(6291457, 20, &solution);
    test(74901729, 4, &solution);
    test(805306373, 25, &solution);
    test(1376796946, 5, &solution);
    test(1073741825, 29, &solution);
    test(1610612737, 28, &solution);
}
