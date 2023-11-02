#include <random>
#include <iostream>
#include <cmath>
#include <array>

using namespace std;

/*	\brief Функция ввода размера массива
*	\return Размер массива
*/
int EnterSize();

/*	\brief Функция сортировки массива (умножение каждого элемента на 3)
*	\param s Размер массива
*	\param arr Сортируемый массив
*	\return Отсортированный массив
*/
void Sorting(int s, int* arr);

int main() {
    int s = EnterSize();

	cout << "Enter minimum value:";
	int minValue;
	cin >> minValue;

	cout << "Enter max value:";
	int maxValue;
	cin >> maxValue;

	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> uniformIntDistribution(minValue, maxValue);

	int* arr = new int[s];

	for (int i = 0; i < s; i++) {
		arr[i] = uniformIntDistribution(gen);
	}

	cout << "Array before sorting: \n";

	for (int i = 0; i < s - 1; i++) {
		cout << arr[i] << ", ";
	}

	cout << arr[s - 1] << ".\n";

	Sorting(s, arr);

	cout << "Array after sorting: \n";

	for (int i = 0; i < s - 1; i++) {
		cout << arr[i] << ", ";
	}

	cout << arr[s - 1] << ".";

	delete[] arr;

	return 0;
}

int EnterSize() {
    cout << "Enter size: ";
    int s;
    try {
        cin >> s;
        if (s <= 0) {
            throw out_of_range("Size can't be less than 0");
        }
    }
    catch (out_of_range &e) {
        cerr << e.what();
        return 1000;
    }
    return s;
}

void Sorting(int s, int* arr) {
    for (int i = 0; i < s; i++) {
        arr[i] = arr[i] * 3;
    }
}