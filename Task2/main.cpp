#include <iostream>
#include <vector>
#include "Task2/Headers/HashMap.h"

using namespace std;

int main() {
    HashMap<string, int> car;

    car.Insert("Kia", 123);
    car.Insert("BMW", 420);
    car.Insert("Tesla", 1020);

    cout << "Value of Kia: " << car.GetValue("Kia") << endl;
    cout << "Value of BMW: " << car.GetValue("BMW") << endl;
    cout << "Value of Tesla: " << car.GetValue("Tesla") << endl;

    car.Insert("Ford", 100);
    cout << "Value of Ford: " << car.GetValue("Ford") << endl;

    cout << "Remove value of BMW" << endl;

    car.Remove("BMW");

    cout << "Remove successful" << endl;

    cout << "Updating value of Kia: " << endl;

    car.Update("Kia", 130);

    cout << "Update successful" << endl;

    cout << "Value of Kia after update: " << car.GetValue("Kia") << endl;

    cout << "Value of BMW after remove" << car.GetValue("BMW") << endl;

    return 0;
}