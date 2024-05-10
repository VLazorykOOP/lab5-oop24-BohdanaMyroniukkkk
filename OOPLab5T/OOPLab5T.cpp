#include <iostream>
#include <cstring>

using namespace std;

// Клас "Процесор"
class Processor {
private:
    int speed; // Потужність в Мгц

public:
    // Конструктор з параметром
    Processor(int MHz) : speed(MHz) {}

    // Метод доступу для потужності
    int getSpeed() const {
        return speed;
    }
};

// Клас "Комп'ютер"
class Computer {
protected: // Змінив доступ на protected
    Processor cpu; // Об'єкт процесора
    char* brand;   // Марка комп'ютера
    double price;  // Ціна комп'ютера

public:
    // Конструктор з параметрами
    Computer(int MHz, const char* brandName, double computerPrice)
        : cpu(MHz), price(computerPrice) {
        // Виділення пам'яті для марки та копіювання рядка
        brand = new char[strlen(brandName) + 1];
        strcpy_s(brand, strlen(brandName) + 1, brandName);

    }

    // Деструктор
    ~Computer() {
        delete[] brand; // Звільнення виділеної пам'яті
    }

    // Функція друку
    void print() const {
        cout << "Brand: " << brand << ", CPU Speed: " << cpu.getSpeed() << "MHz, Price: $" << price << endl;
    }
};

// Похідний клас "Комп'ютер з монітором"
class ComputerWithMonitor : public Computer {
private:
    double monitorSize; // Розмір монітора в дюймах

public:
    // Конструктор з параметрами
    ComputerWithMonitor(int MHz, const char* brandName, double computerPrice, double monitorSize)
        : Computer(MHz, brandName, computerPrice), monitorSize(monitorSize) {}

    // Деструктор
    ~ComputerWithMonitor() {}

    // Функція друку
    void print() const {
        cout << "Brand: " << brand << ", CPU Speed: " << cpu.getSpeed() << "MHz, Price: $" << price
            << ", Monitor Size: " << monitorSize << " inches" << endl;
    }
};

int main() {
    // Тестування класу "Комп'ютер"
    Computer pc1(3000, "Dell", 800.0);
    cout << "Computer 1:" << endl;
    pc1.print();

    // Тестування класу "Комп'ютер з монітором"
    ComputerWithMonitor pc2(3500, "HP", 1000.0, 24.0);
    cout << "Computer with Monitor 1:" << endl;
    pc2.print();

    return 0;
}
