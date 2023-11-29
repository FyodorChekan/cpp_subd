#include <random>
#include <iostream>
#include <cmath>
#include <array>

using namespace std;

/**
*@brief Функция ввода размера массива
*@return Размер массива
*/
size_t EnterSize();

/**
*@brief Функция вывода массива на экран
*@param s Размер массива
*@param array Массив
*/
void PrintArray(size_t s, const int* array);

/**
*@brief Функция сортировки массива (умножение каждого элемента на 3)
*@param s Размер массива
*@param arr Сортируемый массив
*@return Отсортированный массив
*/
int* SortArray(size_t s, const int* arr);

/**
*@brief Функция заполнения массива
*@param s Размер массива
*@param minValue Минимальное значение элемента
*@param maxValue Максимальное значение элемента
*@return Заполненный массив
*/
int* RandomFillArray(size_t s, int minValue, int maxValue);

/**
*@brief main-функция демонстрации работы программы
*@return возвращение 0 при успешной работе
*/
int main();

int main() {
    size_t s = EnterSize();

	cout << "Enter minimum value:";
	int minValue;
	cin >> minValue;

	cout << "Enter max value:";
	int maxValue;
	cin >> maxValue;

    int* arr = RandomFillArray(s, minValue, maxValue);

	cout << "Array before sorting: \n";

	PrintArray(s, arr);

	int* arrayAfterSort = SortArray(s, arr);

	cout << "Array after sorting: \n";

    PrintArray(s, arrayAfterSort);

    if (nullptr != arr)
    {
        delete[] arr;
        arr = nullptr;
    }

    if (nullptr != arrayAfterSort)
    {
        delete[] arrayAfterSort;
        arrayAfterSort = nullptr;
    }

	return 0;
}

size_t EnterSize() {
    cout << "Enter size: ";
    size_t s;
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

int* RandomFillArray(size_t s, int minValue, int maxValue) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> uniformIntDistribution(minValue, maxValue);

    int* arr = new int[s];

    for (size_t i = 0; i < s; i++) {
        arr[i] = uniformIntDistribution(gen);
    }

    return arr;
}

int* SortArray(size_t s, const int* arr) {
    int* array = new int[s];

    for (size_t i = 0; i < s; i++) {
        array[i] = arr[i] * 3;
    }

    return array;
}

void PrintArray(size_t s, const int* array) {
    for (size_t i = 0; i < s - 1; i++) {
        cout << array[i] << ", ";
    }

    cout << array[s - 1] << ".\n";
}