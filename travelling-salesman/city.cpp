#include "city.h"
#include <string>

int City::totalDistances = 0;
City *City::startingCity;

City::City(std::string nameP) : name(nameP), bestPath(0), forward(nullptr)
{
    paths.clear();
}

void City::reset()
{
    bestPath = 0;
    forward = nullptr;
    City::totalDistances = 0;
    City::startingCity = nullptr;
    paths.clear();
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
    if (energy <= bestPath)
    {
        return 0;
    }

    checklist[this] = true;

    if (!keepWalking(checklist, this))
    {
        if (paths[startingCity] == 0)
        {
            return 0;
        }
        else
        {
            if (energy - paths[startingCity] > bestPath)
            {
                forward = nullptr;
                bestPath = energy - paths[startingCity];
                return energy - paths[startingCity];
            }
            return 0;
        }
    }

    int currentPath = 0;

    for (std::pair<City *, int> path : paths)
    {
        if (checklist[path.first])
            continue;

        currentPath = path.first->explore(energy - path.second, checklist);

        if (currentPath > bestPath)
        {
            bestPath = currentPath;
            forward = path.first;
        }
    }

    return bestPath;
}

void connect(City *A, City *B, int distance)
{
    A->paths[B] = distance;
    B->paths[A] = distance;
    City::totalDistances += distance;
}
