#include "city.h"
#include <chrono>
#include <cstring>
#include <iostream>
#include <ostream>
#include <unordered_map>

void solve(City *A, std::unordered_map<City *, bool> &checklist)
{
    using namespace std::chrono;

    City::startingCity = A;

    auto start = high_resolution_clock::now();
    A->explore(City::totalDistances, checklist);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "  ⌛ " << duration.count() << "μs" << std::endl << "  ";

    City *city;
    city = A;

    while (city != nullptr)
    {
        std::cout << *city << " -> ";
        city = city->forward;
    }

    std::cout << *City::startingCity << " : " << City::totalDistances - City::startingCity->bestPath << std::endl;
}

City *A = new City("A");
City *B = new City("B");
City *C = new City("C");
City *D = new City("D");
City *E = new City("E");

std::unordered_map<City *, bool> checklist;

void reset()
{
    A->reset();
    B->reset();
    C->reset();
    D->reset();
    E->reset();

    checklist[A] = false;
    checklist[B] = false;
    checklist[C] = false;
    checklist[D] = false;
    checklist[E] = false;
}

void graph1()
{
    reset();

    connect(A, B, 2);
    connect(A, C, 2);
    connect(B, C, 3);
    connect(B, D, 3);
    connect(C, E, 3);
    connect(D, E, 3);
    connect(B, E, 1);
    connect(D, C, 1);

    solve(A, checklist);
}

void graph2()
{
    reset();

    connect(A, B, 2);
    connect(A, C, 3);
    connect(A, D, 4);
    connect(A, E, 5);
    connect(B, C, 1);
    connect(B, D, 3);
    connect(B, E, 4);
    connect(C, D, 2);
    connect(C, E, 3);
    connect(D, E, 1);

    solve(A, checklist);
}

void graph3()
{
    reset();

    connect(A, B, 1);
    connect(A, C, 4);
    connect(A, D, 3);
    connect(A, E, 5);
    connect(B, C, 2);
    connect(B, D, 4);
    connect(B, E, 3);
    connect(C, D, 1);
    connect(C, E, 2);
    connect(D, E, 4);

    solve(A, checklist);
}

void graph4()
{
    reset();

    connect(A, B, 5);
    connect(A, C, 3);
    connect(A, D, 4);
    connect(A, E, 2);
    connect(B, C, 4);
    connect(B, D, 1);
    connect(B, E, 3);
    connect(C, D, 2);
    connect(C, E, 1);
    connect(D, E, 5);

    solve(A, checklist);
}

void graph5()
{
    reset();

    connect(A, B, 3);
    connect(A, C, 4);
    connect(A, D, 5);
    connect(A, E, 2);
    connect(B, C, 1);
    connect(B, D, 2);
    connect(B, E, 3);
    connect(C, D, 3);
    connect(C, E, 4);
    connect(D, E, 1);

    solve(A, checklist);
}

int main()
{
    graph1();
    std::cout << std::endl;
    graph2();
    std::cout << std::endl;
    graph3();
    std::cout << std::endl;
    graph4();
    std::cout << std::endl;
    graph5();
}
