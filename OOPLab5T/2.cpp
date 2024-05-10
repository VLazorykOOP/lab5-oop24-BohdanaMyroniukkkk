#include <iostream>
#include <cstring>

using namespace std;

// ���� "��������"
class Processor {
private:
    int speed; // ��������� � ���

public:
    // ����������� � ����������
    Processor(int MHz) : speed(MHz) {}

    // ����� ������� ��� ���������
    int getSpeed() const {
        return speed;
    }
};

// ���� "����'����"
class Computer {
protected: // ����� ������ �� protected
    Processor cpu; // ��'��� ���������
    char* brand;   // ����� ����'�����
    double price;  // ֳ�� ����'�����

public:
    // ����������� � �����������
    Computer(int MHz, const char* brandName, double computerPrice)
        : cpu(MHz), price(computerPrice) {
        // �������� ���'�� ��� ����� �� ��������� �����
        brand = new char[strlen(brandName) + 1];
        strcpy_s(brand, strlen(brandName) + 1, brandName);

    }

    // ����������
    ~Computer() {
        delete[] brand; // ��������� ������� ���'��
    }

    // ������� �����
    void print() const {
        cout << "Brand: " << brand << ", CPU Speed: " << cpu.getSpeed() << "MHz, Price: $" << price << endl;
    }
};

// �������� ���� "����'���� � ��������"
class ComputerWithMonitor : public Computer {
private:
    double monitorSize; // ����� ������� � ������

public:
    // ����������� � �����������
    ComputerWithMonitor(int MHz, const char* brandName, double computerPrice, double monitorSize)
        : Computer(MHz, brandName, computerPrice), monitorSize(monitorSize) {}

    // ����������
    ~ComputerWithMonitor() {}

    // ������� �����
    void print() const {
        cout << "Brand: " << brand << ", CPU Speed: " << cpu.getSpeed() << "MHz, Price: $" << price
            << ", Monitor Size: " << monitorSize << " inches" << endl;
    }
};

int main2() {
    // ���������� ����� "����'����"
    Computer pc1(3000, "Dell", 800.0);
    cout << "Computer 1:" << endl;
    pc1.print();

    // ���������� ����� "����'���� � ��������"
    ComputerWithMonitor pc2(3500, "HP", 1000.0, 24.0);
    cout << "Computer with Monitor 1:" << endl;
    pc2.print();

    return 0;
}
