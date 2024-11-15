#include "testing.h"
#include <algorithm>
#include <cinttypes>
#include <random>
#include <vector>

int solution(std::vector<int> &A)
{
    int sum = 0;

    for (int a : A)
    {
        sum += a;
    }

    // then we find what the sum WOULD be were the extra number there
    int altSize = A.size() + 1;
    int goal = (altSize + 1) * (altSize / 2);
    goal += (altSize & 1) ? (altSize / 2 + 1) : 0;

    // the result is the expected sum - the actual sum
    return goal - sum;
}

int main(int argc, char *argv[])
{
    std::vector<int> A;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            A.push_back(std::strtoimax(argv[i], NULL, 10));
        }

        std::cout << A << " -> " << solution(A) << std::endl;

        return 0;
    }

    std::cout << "Use program arguments to try your own inputs:" << std::endl;
    std::cout << "  ie ./exercise-4 2 3 1 5" << std::endl << std::endl;
    std::cout << "RUNNING CORRECTNESS TESTS" << std::endl;

    std::cout << std::endl << "Example Test :" << std::endl;
    A = {2, 3, 1, 5};
    test(A, 4, &solution);

    std::cout << std::endl << "Empty and Single Element :" << std::endl;
    A = {};
    test(A, 1, &solution);
    A = {2};
    test(A, 1, &solution);

    std::cout << std::endl << "Missing First or Last Element :" << std::endl;
    A = {2, 3, 4, 5};
    test(A, 1, &solution);
    A = {1, 2, 3, 4};
    test(A, 5, &solution);

    std::cout << std::endl << "Double Elements :" << std::endl;
    A = {1, 3};
    test(A, 2, &solution);
    A = {2, 4};
    test(A, 3, &solution);

    std::cout << std::endl << "Simple Tests :" << std::endl;
    A = {1, 2, 4};
    test(A, 3, &solution);
    A = {5, 4, 1, 2};
    test(A, 3, &solution);

    std::cout << std::endl << std::endl << "RUNNING PERFORMANCE TESTS" << std::endl;

    std::cout << std::endl << "Medium Range :" << std::endl;
    A.clear();
    for (int i = 1; i <= 10000; i++)
    {
        if (i != 5432)
            A.push_back(i);
    }
    testP(A, &solution);

    A.clear();
    for (int i = 1; i <= 10000; i++)
    {
        if (i != 9999)
            A.push_back(i);
    }
    testP(A, &solution);

    std::cout << std::endl << "Large Range :" << std::endl;
    A.clear();
    for (int i = 1; i <= 100000; i++)
    {
        if (i != 98765)
            A.push_back(i);
    }
    testP(A, &solution);

    A.clear();
    for (int i = 1; i <= 100000; i++)
    {
        if (i != 12345)
            A.push_back(i);
    }
    testP(A, &solution);

    std::cout << std::endl << "Large Randomized Test :" << std::endl;
    A.clear();
    for (int i = 1; i <= 100000; i++)
    {
        A.push_back(i);
    }
    A.erase(A.begin() + 75000);
    std::shuffle(A.begin(), A.end(), std::mt19937{std::random_device{}()});
    testP(A, &solution);
}
