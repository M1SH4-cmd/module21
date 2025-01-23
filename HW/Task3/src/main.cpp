#include <iostream>
#include <cmath>
using namespace std;

struct vector {
    double x;
    double y;
};


void add(vector vec1, vector vec2)
{
    vector vec3;
    vec3.x = vec1.x + vec2.x;
    vec3.y = vec1.x + vec2.y;
    return vec3;
}

void subtract(vector vec1, vector vec2)
{
    vector vec3;
    vec3.x = vec1.x - vec2.x;
    vec3.y = vec1.x - vec2.y;
    return vec3;
}

vector scale(vector vec1, double scalar)
{
    vector vec2;
    vec2.x = vec1.x * scalar;
    vec2.y = vec1.x * scalar;
    return vec2;
}

double length(vector vec1)
{
    return sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
}

vector normalize(vector vec1)
{
    double length = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
    if (length == 0) {
        cout << "Cannot normalize the zero vector" << endl;
        return;
    }
    vector vec3;
    double normalizedX = vec1.x / length;
    double normalizedY = vec1.y / length;
    return vec3(normalizedX, normalizedY);
}

void printVector(vector vec1) {
    cout << "(" << vec1.x << ", " << vec1.y << ")" << endl;
}

int main()
{   
    double x, y;

    string op;
    cout << "Enter an operation (add, subtract, scale, length, normalize): ";
    cin >> op;

    if (op == "add") {
        vector vec1, vec2;
        cout << "Enter coordinates for vector 1: ";
        cin >> vec1.x >> vec1.y;
        cout << "Enter coordinates for vector 2: ";
        cin >> vec2.x >> vec2.y;
        add(vec1, vec2);
    } else if (op == "subtract") {
        vector vec1, vec2;
        cout << "Enter coordinates for vector 1: ";
        cin >> vec1.x >> vec1.y;
        cout << "Enter coordinates for vector 2: ";
        cin >> vec2.x >> vec2.y;
        subtract(vec1, vec2);
    } else if (op == "scale") {
        double scalar;
        vector vec1;
        cout << "Enter coordinates for vector: ";
        cin >> vec1.x >> vec1.y;
        cout << "Enter scalar: ";
        cin >> scalar;
        scale(vec1, scalar);
    } else if (op == "length") {
        vector vec1;
        cout << "Enter coordinates for vector: ";
        cin >> vec1.x >> vec1.y;
        length(vec1);
    } else if (op == "normalize") {
        vector vec1;
        cout << "Enter coordinates for vector: ";
        cin >> vec1.x >> vec1.y;
        normalize(vec1);
    } else {
        cout << "Invalid operation" << endl;
    }
}