#include "testing.h"
#include <cinttypes>
#include <cmath>
#include <iostream>
#include <ostream>

int solution(int X, int Y, int D)
{
    double n = (double)(Y - X) / (double)D;
    n = std::ceil(n);

    return (int)n;
}

int main(int argc, char *argv[])
{
    int X = 0, Y = 0, D = 1;

    if (argc > 1)
    {
        X = std::strtoimax(argv[1], NULL, 10);
        Y = std::strtoimax(argv[2], NULL, 10);
        D = std::strtoimax(argv[3], NULL, 10);

        std::cout << "X: " << X << ", Y: " << Y << ", D: " << D << " -> " << solution(X, Y, D) << std::endl;

        return 0;
    }

    std::cout << "Use program arguments to try your own inputs:" << std::endl;
    std::cout << "  ie ./exercise-4 10 85 30" << std::endl << std::endl;
    std::cout << "RUNNING CORRECTNESS TESTS" << std::endl;

    std::cout << std::endl << "Basic Example :" << std::endl;
    test(10, 85, 30, 3, &solution);

    std::cout << std::endl << "Simple Tests :" << std::endl;
    test(0, 75, 25, 3, &solution);
    test(5, 100, 15, 7, &solution);

    std::cout << std::endl << "Extreme Position (no jump needed):" << std::endl;
    test(50, 50, 5, 0, &solution);
    test(100, 100, 10, 0, &solution);

    std::cout << std::endl << "Single Big Jump :" << std::endl;
    test(0, 50, 100, 1, &solution);
    test(10, 100, 1000, 1, &solution);

    std::cout << std::endl << "Edge Cases :" << std::endl;
    test(10, 10, 1, 0, &solution); // already at target
    test(1, 1, 1, 0, &solution);

    std::cout << std::endl << "Many Small Jumps :" << std::endl;
    test(0, 1000000, 1, 1000000, &solution);
    test(10, 5000000, 3, 1666664, &solution);

    std::cout << std::endl << "Many Medium Jumps :" << std::endl;
    test(0, 5000000, 100, 50000, &solution);
    test(100, 10000000, 250, 40000, &solution);

    std::cout << std::endl << "Large Jump Intervals :" << std::endl;
    test(0, 1000000000, 999999, 1001, &solution);
    test(500, 1000000000, 99999, 10001, &solution);

    std::cout << std::endl << "Maximum Jump Scenario :" << std::endl;
    test(0, 1000000000, 2, 500000000, &solution);
    test(10, 1000000000, 99, 10101010, &solution);
    test(5, 1000000000, 1283, 779424, &solution);
}
