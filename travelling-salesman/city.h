#include <string>
#include <unordered_map>
#include <vector>

class City
{
  public:
    City();
    City(std::string name);

    std::string name;
    int explore(int energy, std::unordered_map<City *, bool> checklist);
    bool operator==(const City &B);
    bool operator!=(const City &B);

    void reset();

    int bestPath = 0;
    City *forward; // used to keep track of optimal path

    const City *getStartingCity() const;

  private:
    friend void solve(City *A, std::unordered_map<City *, bool> &checklist);
    friend void connect(City *A, City *B, int distance);
    std::unordered_map<City *, int> paths;

    static int totalDistances;
    static City *startingCity;
};

inline std::ostream &operator<<(std::ostream &os, const City &city)
{
    os << city.name;
    return os;
}
