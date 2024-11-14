#include "structs.h"
#include <unordered_map>
#include <vector>

class Path;

City::City(const char *nameP)
{
    name = nameP;
}

Path::Path(City *AP, City *BP, int lengthP)
{
    A = AP;
    B = BP;
    length = lengthP;

    A->paths.push_back(this);
    B->paths.push_back(this);
}

Trip City::trip(Path *p)
{
    City *c = p->A != this ? p->A : p->B;

    return {c, p, p->length};
}

std::ostream &operator<<(std::ostream &os, const City &city)
{
    os << city.name; // Print the city name
    return os;
}

bool keepLooking(const std::unordered_map<City *, bool> &soFar)
{
    for (auto p : soFar)
    {
        if (!p.second)
        {
            return true;
        }
    }

    return false;
}

struct GoldenPath
{
    std::vector<City *> cities;
    int cost;
};

GoldenPath check(Trip T, int cost, const int max, std::unordered_map<City *, bool> soFar, City *trueStart)
{
    GoldenPath goldenPath;
    goldenPath.cost = max;

    cost += T.cost;

    soFar[T.C] = true;

    if (T.C == trueStart && !keepLooking(soFar))
    {
        goldenPath.cities.push_back(T.C);
        goldenPath.cost = cost;
        return goldenPath;
    }

    if (cost >= max)
    {
        return goldenPath;
    }

    for (Path *p : T.C->paths)
    {
        if (p != T.P)
        {
            Trip nextTrip = T.C->trip(p);
            GoldenPath candidate = check(nextTrip, cost, max, soFar, trueStart);

            if (candidate.cost < goldenPath.cost)
            {
                goldenPath = candidate;
            }
        }
    }

    goldenPath.cities.push_back(T.C);

    return goldenPath;
}

void lookFrom(City *A, int max, std::unordered_map<City *, bool> &list)
{
    GoldenPath solution = check({A, nullptr, 0}, 0, max, list, A);

    for (City *c : solution.cities)
    {
        std::cout << *c << " -> ";
    }

    std::cout << std::endl;

    std::cout << solution.cost;
}

int main()
{
    City A = City("A");
    City B = City("B");
    City C = City("C");
    City D = City("D");
    City E = City("E");

    City cities[5] = {A, B, C, D, E};
    Path paths[8] = {Path(&A, &B, 2), Path(&A, &C, 2), Path(&B, &C, 3), Path(&B, &D, 3),
                     Path(&D, &E, 3), Path(&E, &C, 3), Path(&B, &E, 1), Path(&D, &C, 1)};

    int maxCost = 0;
    std::unordered_map<City *, bool> list;

    for (int i = 0; i < 8; i++)
    {
        maxCost += paths[i].length;
    }

    for (int i = 0; i < 5; i++)
    {
        list[&cities[i]] = false;
    }

    maxCost *= 2;

    lookFrom(&A, maxCost, list);

    return 0;
}
