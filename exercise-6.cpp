#include "testing.h"
#include <cinttypes>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

int sum(const std::vector<int> &A)
{
    int n = 0;

    for (int a : A)
    {
        n += a;
    }

    return n;
}

int solution(std::vector<int> &A)
{
    int total = sum(A);

    int bestDiff = INT_MAX;

    int leftTotal = 0;

    for (int i = 0; i < int(A.size()) - 1; i++)
    {
        leftTotal += A[i];

        // int rightTotal = total - leftTotal;
        // int cDiff = abs(leftTotal - rightTotal);
        // can be simplified into:
        int cDiff = abs(2 * leftTotal - total);

        if (cDiff == 0) // cannot be better than that, may as well reply
        {
            return 0;
        }

        if (cDiff < bestDiff)
        {
            bestDiff = cDiff;
        }
    }

    return bestDiff;
}

int main(int argc, char *argv[])
{
    std::vector<int> input;
    for (int i = 1; i < argc; i++)
    {
        input.push_back(std::strtoimax(argv[i], NULL, 10));
    }

    if (argc > 1)
    {
        std::cout << input << " -> " << solution(input);
        return 0;
    }

    std::vector<int> A;
    std::cout << "Use program arguments to try your own inputs:" << std::endl;
    std::cout << "  ie ./exercise-6 1 4 5 2 3 -10 4" << std::endl << std::endl;
    std::cout << "RUNNING CORRECTNESS TESTS" << std::endl;
    std::cout << std::endl << "Basic Examples :" << std::endl;
    A = {3, 1, 2, 4, 3};
    test(A, 1, &solution);
    A = {14, -5, 2, 24, -21};
    test(A, 4, &solution);
    A = {-1, -4, -12, 45, -24};
    test(A, 6, &solution);

    std::cout << std::endl << "Double :" << std::endl;
    A = {-1000, 1000};
    test(A, 2000, &solution);
    A = {5, 6};
    test(A, 1, &solution);
    A = {-10, -12};
    test(A, 2, &solution);

    std::cout << std::endl << "Simple Positive :" << std::endl;
    A = {75, 23, 14, 102, 5};
    test(A, 5, &solution);

    A = {7, 3, 5, 4, 5};
    test(A, 4, &solution);

    std::cout << std::endl << "Simple Negative :" << std::endl;
    A = {-123, -50, -210, -215, -12};
    test(A, 156, &solution);

    A = {-2, -15, -15, -7, -4};
    test(A, 9, &solution);

    std::cout << std::endl << "Simple Boundary :" << std::endl;
    A = {106, -12, 57, 3, 59};
    test(A, 1, &solution);

    A = {59, 3, 57, -12, 106};
    test(A, 1, &solution);

    std::cout << std::endl << "Large List :" << std::endl;
    A.clear();
    std::srand(1);
    for (int i = 0; i < 20; i++)
        A.push_back(std::rand() / 1000000);
    test(A, 204, &solution);

    A.clear();
    for (int i = 0; i < 20; i++)
        A.push_back(std::rand() / 1000000);
    test(A, 77, &solution);

    std::cout << std::endl << std::endl << "RUNNING PERFORMANCE TESTS" << std::endl;
    std::cout << std::endl << "Medium Random :" << std::endl;
    A.clear();
    for (int i = 0; i < 10000; i++)
        A.push_back(std::rand());
    testP(A, &solution);

    A.clear();
    for (int i = 0; i < 10000; i++)
        A.push_back(std::rand());
    testP(A, &solution);

    std::cout << std::endl << "Large Ones :" << std::endl;
    A.clear();
    for (int i = 0; i < 100000; i++)
        A.push_back((i & 1) * 2 - 1);
    testP(A, &solution);

    std::cout << std::endl << "Large Random :" << std::endl;
    A.clear();
    for (int i = 0; i < 100000; i++)
        A.push_back(std::rand());
    testP(A, &solution);

    std::cout << std::endl << "Large Sequence :" << std::endl;
    A.clear();
    for (int i = 0; i < 100000; i++)
        A.push_back(i);
    testP(A, &solution);
}
