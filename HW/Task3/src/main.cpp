#include <iostream>
#include <cmath>
using namespace std;

void add(double x1, double y1, double x2, double y2)
{
    cout << "Vector (" << x1 + x2 << ", " << y1 + y2 << ")" << endl;
}

void subtract(double x1, double y1, double x2, double y2)
{
    cout << "Vector (" << x1 - x2 << ", " << y1 - y2 << ")" << endl;
}

void scale(double x1, double y1, double scalar)
{
    cout << "Vector (" << x1 * scalar << ", " << y1 * scalar << ")" << endl;
}

void length(double x1, double y1)
{
    cout << "Length: " << sqrt(x1 * x1 + y1 * y1) << endl;
}

void normalize(double x1, double y1)
{
    double length = sqrt(x1 * x1 + y1 * y1);
    if (length == 0) {
        cout << "Cannot normalize the zero vector" << endl;
        return;
    }
    double normalizedX = x1 / length;
    double normalizedY = y1 / length;
    cout << "Normalized Vector (" << normalizedX << ", " << normalizedY << ")" << endl;
}

int main()
{   
    double x, y;

    string op;
    cout << "Enter an operation (add, subtract, scale, length, normalize): ";
    cin >> op;

    if (op == "add") {
        double x1, y1, x2, y2;
        cout << "Enter coordinates for vector 1: ";
        cin >> x1 >> y1;
        cout << "Enter coordinates for vector 2: ";
        cin >> x2 >> y2;
        add(x1, y1, x2, y2);
    } else if (op == "subtract") {
        double x1, y1, x2, y2;
        cout << "Enter coordinates for vector 1: ";
        cin >> x1 >> y1;
        cout << "Enter coordinates for vector 2: ";
        cin >> x2 >> y2;
        subtract(x1, y1, x2, y2);
    } else if (op == "scale") {
        double x1, y1, scalar;
        cout << "Enter coordinates for vector: ";
        cin >> x1 >> y1;
        cout << "Enter scalar: ";
        cin >> scalar;
        scale(x1, y1, scalar);
    } else if (op == "length") {
        cout << "Enter coordinates for vector: ";
        cin >> x >> y;
        length(x, y);
    } else if (op == "normalize") {
        cout << "Enter coordinates for vector: ";
        cin >> x >> y;
        normalize(x, y);
    } else {
        cout << "Invalid operation" << endl;
    }

}
