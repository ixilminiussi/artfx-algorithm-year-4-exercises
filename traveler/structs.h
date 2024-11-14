#include <iostream>
#include <ostream>
#include <unordered_map>
#include <utility>
#include <vector>

class City;

class Path
{
  public:
    Path(City *A, City *B, int length);
    Path() = delete;

    ~Path() = default;

    City *A;
    City *B;
    int length;
};

struct Trip
{
    City *C;
    Path *P;
    int cost;
};

class City
{
  public:
    City(const char *name);
    ~City() = default;

    friend std::ostream &operator<<(std::ostream &os, const City &city);
    Trip trip(Path *p);

    std::vector<Path *> paths;
    const char *name;
};
