#include "city.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

City *start;

City::City(std::string nameP) : name(nameP)
{
}

bool City::operator==(const City &B)
{
    return (name.compare(B.name) == 0);
}

bool City::operator!=(const City &B)
{
    return !(*this == B);
}

bool keepWalking(std::unordered_map<City *, bool> &checklist, City *c)
{
    for (auto e : checklist)
    {
        if (e.second == false)
        {
            return true;
        }
    }

    return false;
}

int City::explore(int energy, std::unordered_map<City *, bool> checklist)
{
    // do we have energy to keep walking
    if (energy <= bestPath)
    {
        return 0;
    }

    // check ourselves off the checklist
    checklist[this] = true;

    // if we visited every city...
    if (!keepWalking(checklist, this))
    {
        if (paths[start] == 0) // ...and we aren't one away from the goal...
        {
            return 0; // ...discard this path as a valid option
        }
        else
        {
            if (energy - paths[start] > bestPath)
            {
                forward = nullptr;
                bestPath = energy - paths[start];
                return energy - paths[start]; // otherwise return the final path cost;
            }
            return 0;
        }
    }

    // if we haven't visited every city
    int currentPath = 0;

    // go through potential paths
    for (std::pair<City *, int> path : paths)
    {
        // except those to cities already explored
        if (checklist[path.first])
            continue;

        // recurse into the new path, (checklist is passed by copy)
        currentPath = path.first->explore(energy - path.second, checklist);

        if (currentPath > bestPath)
        {
            bestPath = currentPath;
            forward = path.first;
        }
    }

    return bestPath;
}

int totalPaths;
void connect(City *A, City *B, int distance)
{
    A->paths[B] = distance;
    B->paths[A] = distance;
    totalPaths += distance;
}

void solve(City *A, std::unordered_map<City *, bool> &checklist)
{
    start = A;

    A->explore(totalPaths, checklist);

    City *city;
    city = A;

    while (city != nullptr)
    {
        std::cout << *city << " -> ";
        city = city->forward;
    }

    std::cout << *start << std::endl;
}

// if we wanna be pedantic: Technically the fastest algorithm to solving the
// travelling salesman for this particular graph
void pedanticSolve(City *A)
{
}

int main()
{
    City A{"A"};
    City B{"B"};
    City C{"C"};
    City D{"D"};
    City E{"E"};

    connect(&A, &B, 2);
    connect(&A, &C, 2);
    connect(&B, &C, 3);
    connect(&B, &D, 3);
    connect(&C, &E, 3);
    connect(&D, &E, 3);
    connect(&B, &E, 1);
    connect(&D, &C, 1);

    std::unordered_map<City *, bool> checklist;

    checklist[&A] = false;
    checklist[&B] = false;
    checklist[&C] = false;
    checklist[&D] = false;
    checklist[&E] = false;

    solve(&A, checklist);
    pedanticSolve(&A);
}
