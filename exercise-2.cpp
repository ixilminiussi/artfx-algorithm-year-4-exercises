#include "testing.h"
#include <cinttypes>
#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>

std::vector<int> solution(std::vector<int> &A, int K)
{
    std::vector<int> B = A;

    for (int a : A)
    {
        K = ((K % A.size()) + A.size()) % A.size();

        B[K] = a;
        K++;
    }

    return B;
}

int main(int argc, char *argv[])
{
    std::vector<int> A;
    int K = 1;

    for (int i = 1; i < argc; i++)
    {
        if (std::strcmp(argv[i], "-K") == 0)
        {
            K = std::strtoimax(argv[i + 1], NULL, 10);
            break;
        }
        A.push_back(std::strtoimax(argv[i], NULL, 10));
    }

    std::cout << A << " -> " << solution(A, K) << std::endl;

    if (argc > 1)
        return 0;

    std::cout << "Use program arguments to try your own inputs:" << std::endl;
    std::cout << "  ie ./exercise-2 1 2 3 4 5 -K 4" << std::endl << std::endl;
    std::cout << "RUNNING CORRECTNESS TESTS" << std::endl;
    std::cout << std::endl << "Basic Examples :" << std::endl;
    A = {3, 8, 9, 7, 6};
    test(A, 3, {9, 7, 6, 3, 8}, &solution);
    A = {0, 0, 0};
    test(A, 1, {0, 0, 0}, &solution);
    A = {1, 2, 3, 4};
    test(A, 4, {1, 2, 3, 4}, &solution);

    std::cout << std::endl << "Empty :" << std::endl;
    A = {};
    test(A, 0, {}, &solution);
    test(A, 1, {}, &solution);

    std::cout << std::endl << "Single :" << std::endl;
    A = {42};
    test(A, 0, {42}, &solution);
    test(A, 1, {42}, &solution);
    test(A, 2, {42}, &solution);
    test(A, 5, {42}, &solution);

    std::cout << std::endl << "Double :" << std::endl;
    A = {1, 2};
    test(A, 1, {2, 1}, &solution);
    test(A, 2, {1, 2}, &solution);
    test(A, 3, {2, 1}, &solution);

    std::cout << std::endl << "Small (K <= N) :" << std::endl;
    A = {3, 8, 9, 7, 6};
    test(A, 1, {6, 3, 8, 9, 7}, &solution);
    test(A, 2, {7, 6, 3, 8, 9}, &solution);
    test(A, 3, {9, 7, 6, 3, 8}, &solution);
    test(A, 4, {8, 9, 7, 6, 3}, &solution);
    test(A, 5, {3, 8, 9, 7, 6}, &solution);

    std::cout << std::endl << "Small (K >= N) :" << std::endl;
    test(A, 6, {6, 3, 8, 9, 7}, &solution);
    test(A, 10, {3, 8, 9, 7, 6}, &solution);

    std::cout << std::endl << std::endl << "RUNNING PERFORMANCE TESTS" << std::endl;
    std::cout << std::endl << "Medium Random :" << std::endl;
    A.clear();
    for (int i = 0; i < 10000; i++)
        A.push_back(std::rand());
    testP(A, 1, &solution);
    testP(A, 5000, &solution);
    testP(A, 10000, &solution);

    std::cout << std::endl << "Large Ones :" << std::endl;
    A.clear();
    for (int i = 0; i < 100000; i++)
        A.push_back((i & 1) * 2 - 1);
    testP(A, 1, &solution);
    testP(A, 50000, &solution);
    testP(A, 100000, &solution);

    std::cout << std::endl << "Large Random :" << std::endl;
    A.clear();
    for (int i = 0; i < 100000; i++)
        A.push_back(std::rand());
    testP(A, 1, &solution);
    testP(A, 50000, &solution);
    testP(A, 100000, &solution);

    std::cout << std::endl << "Large Sequence :" << std::endl;
    A.clear();
    for (int i = 0; i < 100000; i++)
        A.push_back(i);
    testP(A, 1, &solution);
    testP(A, 50000, &solution);
    testP(A, 100000, &solution);
}
