#include <iostream>
#include <string>

using namespace std;

// Базовий клас "Людина"
class Person {
protected:
    string name;
    int age;

public:
    // Конструктор за замовчуванням
    Person() : name(""), age(0) {}

    // Конструктор з параметрами
    Person(string personName, int personAge) : name(personName), age(personAge) {}

    // Конструктор копіювання
    Person(const Person& other) : name(other.name), age(other.age) {}

    // Оператор присвоювання
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

   
};

// Похідний клас "Службовець"
class Employee : public Person {
private:
    string position;

public:
    // Конструктор за замовчуванням
    Employee() : position("") {}

    // Конструктор з параметрами
    Employee(string personName, int personAge, string empPosition)
        : Person(personName, personAge), position(empPosition) {}

    // Функція виводу у потік
    friend ostream& operator<<(ostream& out, const Employee& employee) ;
    // Функція введення з потоку
    friend istream& operator>>(istream& in, Employee& employee) ;
};

 // Функція виводу у потік
    ostream& operator<<(ostream& out, const Person& person) {
        out << "Name: " << person.name << ", Age: " << person.age;
        return out;
    }

    // Функція введення з потоку
     istream& operator>>(istream& in, Person& person) {
        cout << "Enter name: ";
        in >> person.name;
        cout << "Enter age: ";
        in >> person.age;
        return in;
    }
int main() {
    // Тестування класу "Людина"
    cout << "Enter information for a person:" << endl;
    Person person1;
    cin >> person1;
    cout << "Person information: " << person1 << endl;

    // Тестування класу "Службовець"
    cout << "Enter information for an employee:" << endl;
    Employee employee1;
    cin >> employee1;
    cout << "Employee information: " << employee1 << endl;

    return 0;
}
