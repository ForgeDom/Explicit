#include <iostream>
#include <string>
using namespace std;

class Reservoir {
private:
    string name;
    string type;
    double width;
    double length;
    double maxDepth;

public:
    Reservoir()
        : name("Unnamed"), type("Unknown"), width(0), length(0), maxDepth(0) {}

    Reservoir(const string& name, const string& type, double width, double length, double maxDepth)
        : name(name), type(type), width(width), length(length), maxDepth(maxDepth) {}

    Reservoir(const Reservoir& other)
        : name(other.name), type(other.type), width(other.width), length(other.length), maxDepth(other.maxDepth) {}

    ~Reservoir() {}

    double getVolume() const {
        return width * length * maxDepth;
    }

    double getSurfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        return type == other.type;
    }

    bool isLargerSurface(const Reservoir& other) const {
        return isSameType(other) && getSurfaceArea() > other.getSurfaceArea();
    }

    Reservoir& operator=(const Reservoir& other) {
        if (this != &other) {
            name = other.name;
            type = other.type;
            width = other.width;
            length = other.length;
            maxDepth = other.maxDepth;
        }
        return *this;
    }

    void display() const {
        cout << "Reservoir Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Width: " << width << " meters" << endl;
        cout << "Length: " << length << " meters" << endl;
        cout << "Max Depth: " << maxDepth << " meters" << endl;
        cout << "Surface Area: " << getSurfaceArea() << " square meters" << endl;
        cout << "Volume: " << getVolume() << " cubic meters" << endl;
    }
};

int main() {
    Reservoir r1("Lake Superior", "Lake", 200, 500, 50);
    Reservoir r2("Mediterranean Sea", "Sea", 3000, 4000, 1500);

    r1.display();
    cout << endl;
    r2.display();
    cout << endl;

    if (r1.isSameType(r2)) {
        cout << "The reservoirs are of the same type." << endl;
    }
    else {
        cout << "The reservoirs are of different types." << endl;
    }

    if (r1.isLargerSurface(r2)) {
        cout << "Reservoir 1 has a larger surface area than Reservoir 2." << endl;
    }
    else if (r1.isSameType(r2)) {
        cout << "Reservoir 2 has a larger surface area than Reservoir 1." << endl;
    }

    Reservoir r3 = r1;
    cout << "\nCopied Reservoir:" << endl;
    r3.display();

    return 0;
}