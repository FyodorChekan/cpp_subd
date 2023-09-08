#include <random>
#include <iostream>
#include <cmath>
#include <array>

using namespace std;

void Sorting(int s, int* arr) {
	for (int i = 0; i < s; i++) {
		arr[i] = arr[i] * 3;
	}
}

int main() {
	cout << "Enter size: ";
	int s;
	try {
		cin >> s;
		if (s <= 0) {
			throw out_of_range("Неправильно введен размер массива");
		}
	}
	catch (out_of_range& e) {
		cerr << e.what();
		return 1000;
	}
	

	cout << "Enter minimum value:";
	int minValue;
	cin >> minValue;

	cout << "Enter max value:";
	int maxValue;
	cin >> maxValue;

	random_device rd;
	mt19937 gen(rd()); // Генератор случайных чисел

	const uniform_int_distribution<int> uniformIntDistribution(minValue, maxValue); // Границы для случайного числа

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