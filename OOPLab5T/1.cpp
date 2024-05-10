#include <iostream>
#include <string>

using namespace std;

// ���� "�����"
class Point {
protected:
    int x, y;

public:
    // ����������� �� �������������
    Point() : x(0), y(0) {}

    // ����������� � �����������
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

    // ����������
    ~Point() {}

    // ������� �����
    void print() {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }

    // ������� ��������������� ��������� �����
    void setCoordinates(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

// ���� "��������� �����"
class ColoredPoint : public Point {
private:
    string color;

public:
    // ����������� �� �������������
    ColoredPoint() : Point(), color("black") {}

    // ����������� � �����������
    ColoredPoint(int xCoord, int yCoord, string clr) : Point(xCoord, yCoord), color(clr) {}

    // ����������
    ~ColoredPoint() {}

    // ������� �����
    void print() {
        cout << "Colored Point: (" << x << ", " << y << "), Color: " << color << endl;
    }

    // ������� ��������������� �������
    void setColor(string newColor) {
        color = newColor;
    }

    // ������� ��������� ��������� �����
    void printCoordinates() {
        cout << "Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // ���������� ����� "�����"
    Point p1;
    cout << "Point 1:" << endl;
    p1.print();

    Point p2(3, 4);
    cout << "Point 2:" << endl;
    p2.print();

    p2.setCoordinates(5, 6);
    cout << "Point 2 after setting new coordinates:" << endl;
    p2.print();

    // ���������� ����� "��������� �����"
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
