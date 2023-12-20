#include <iostream>
#include<SortedAlghs.h> 
using namespace Sorted;
using namespace std;
class Vector2D {
public:
    double x, y;

    Vector2D(double a, double b) : x(a), y(b) {}

    bool operator>(const Vector2D& other) const {
        double length1 = x * x + y * y;
        double length2 = other.x * other.x + other.y * other.y;
        return length1 > length2;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

int main() {
    std::vector<Vector2D> vectors({ Vector2D(1, 0), Vector2D(0, 8), Vector2D(1.1, 0.6), Vector2D(3, 3), Vector2D(4, 4) });
    bubbleSort(vectors);

    for (int i = 0; i < size(vectors); i++) {
        cout << vectors[i];
    }
}