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

    int bestPath = 0;
    City *forward; // used to keep track of optimal path

  private:
    friend void connect(City *A, City *B, int distance);
    std::unordered_map<City *, int> paths;
};

inline std::ostream &operator<<(std::ostream &os, const City &city)
{
    os << city.name;
    return os;
}
