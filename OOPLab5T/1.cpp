#include <iostream>
#include <string>

using namespace std;

// Клас "Точка"
class Point {
protected:
    int x, y;

public:
    // Конструктор за замовчуванням
    Point() : x(0), y(0) {}

    // Конструктор з параметрами
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

    // Деструктор
    ~Point() {}

    // Функція друку
    void print() {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }

    // Функція перепризначення координат точки
    void setCoordinates(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

// Клас "Кольорова точка"
class ColoredPoint : public Point {
private:
    string color;

public:
    // Конструктор за замовчуванням
    ColoredPoint() : Point(), color("black") {}

    // Конструктор з параметрами
    ColoredPoint(int xCoord, int yCoord, string clr) : Point(xCoord, yCoord), color(clr) {}

    // Деструктор
    ~ColoredPoint() {}

    // Функція друку
    void print() {
        cout << "Colored Point: (" << x << ", " << y << "), Color: " << color << endl;
    }

    // Функція перепризначення кольору
    void setColor(string newColor) {
        color = newColor;
    }

    // Функція виведення координат точки
    void printCoordinates() {
        cout << "Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Тестування класу "Точка"
    Point p1;
    cout << "Point 1:" << endl;
    p1.print();

    Point p2(3, 4);
    cout << "Point 2:" << endl;
    p2.print();

    p2.setCoordinates(5, 6);
    cout << "Point 2 after setting new coordinates:" << endl;
    p2.print();

    // Тестування класу "Кольорова точка"
    ColoredPoint cp1;
    cout << "Colored Point 1:" << endl;
    cp1.print();

    ColoredPoint cp2(1, 2, "red");
    cout << "Colored Point 2:" << endl;
    cp2.print();

    cp2.setColor("blue");
    cout << "Colored Point 2 after changing color:" << endl;
    cp2.print();

    cout << "Coordinates of Colored Point 2:" << endl;
    cp2.printCoordinates();

    return 0;
}
