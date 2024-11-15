#include "testing.h"
#include <cinttypes>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

int solution(std::vector<int> &A)
{
    std::unordered_map<int, int> umap;

    for (int a : A)
    {
        umap[a]++;
    }

    for (auto e : umap)
    {
        if (e.second & 1)
        {
            return e.first;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    std::vector<int> A;
    int K = 1;

    for (int i = 1; i < argc; i++)
    {
        A.push_back(std::strtoimax(argv[i], NULL, 10));
    }

    std::cout << A << " -> " << solution(A) << std::endl;

    if (argc > 1)
        return 0;

    std::cout << "Use program arguments to try your own inputs:" << std::endl;
    std::cout << "  ie ./exercise-3 1 2 12 7 4 1 12 4 2" << std::endl << std::endl;
    std::cout << "RUNNING CORRECTNESS TESTS" << std::endl;
    std::cout << std::endl << "Basic Examples :" << std::endl;
    A = {9, 3, 9, 3, 9, 7, 9};
    test(A, 7, &solution);
    A = {5, 3, 5, 3, 7};
    test(A, 7, &solution);
    A = {1, 2, 3, 2, 3, 1, 4, 5, 4, 5, 9};
    test(A, 9, &solution);

    std::cout << "Single :" << std::endl;
    A = {42};
    test(A, 42, &solution);

    std::cout << "Small Random :" << std::endl;
    A.clear();
    for (int i = 1; i <= 100; i++)
    {
        A.push_back(i);
        A.push_back(i);
    }
    A.push_back(77);
    test(A, 77, &solution);

    A.clear();
    for (int i = 1; i <= 300; i++)
    {
        A.push_back(i);
        A.push_back(i);
    }
    A.push_back(123);
    test(A, 123, &solution);

    std::cout << std::endl << std::endl << "RUNNING PERFORMANCE TESTS" << std::endl;
    std::cout << std::endl << "Medium Random :" << std::endl;
    A.clear();
    for (int i = 1; i <= 1000; i++)
    {
        A.push_back(i);
        A.push_back(i);
    }
    A.push_back(501);
    testP(A, &solution);

    A.clear();
    for (int i = 1; i <= 50001; i++)
    {
        A.push_back(i);
        A.push_back(i);
    }
    A.push_back(49999);
    testP(A, &solution);

    std::cout << std::endl << "Large Ones :" << std::endl;
    A.clear();
    for (int i = 1; i <= 499999; i++)
    {
        A.push_back(i);
        A.push_back(i);
    }
    A.push_back(888888); // The unpaired element
    testP(A, &solution);

    A.clear();
    for (int i = 1; i <= 499999; i++)
    {
        A.push_back(i);
        A.push_back(i);
    }
    A.push_back(777777); // The unpaired element
    testP(A, &solution);
}
