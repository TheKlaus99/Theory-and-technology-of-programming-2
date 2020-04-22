#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	// Размер массива
	int a;

	cout << "Введите размер массива: ";
	cin >> a;

	// Условия для ввода
	if (cin.fail()) {
		cout << "Для ввода разрешены только числа!" << endl;
		return 0;
	}
	while (a > 15 || a < 2) {
		cout << "Значение долно быть в диапазоне от 2 до 15. Введите еще раз размер массива: ";
		cin >> a;
	}

	// Выделение памяти под массив
	int** arr;
	arr = new int* [a];
	for (int i = 0; i < a; i++)
	{
		arr[i] = new int[a];
	}

	// Массив
	cout << endl << "Массив: " << endl << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			arr[i][j] = rand() % 79 + 1;
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}

	cout << endl;




	cout << endl << ">>>   ПОСЛЕДОВАТЕЛЬНЫЙ ПОИСК   <<<" << endl;
	printf("========================================================================\n");

	cout << endl << "Простые числа, которые меньше пятидесяти: " << endl << endl;

	int m = 0, n;

	for (int j = 0; j < a; j++) {
		for (int i = 0; i < a; i++) {
			if (arr[i][j] < 50) {

				n = arr[i][j];

				if (n == 1 ||
					n == 2 ||
					n == 3 ||
					n == 5 ||
					n == 7 ||
					n == 11 ||
					n == 13 ||
					n == 17 ||
					n == 19 ||
					n == 23 ||
					n == 29 ||
					n == 31 ||
					n == 37 ||
					n == 41 ||
					n == 43 ||
					n == 47) {

					cout << n << "\t\t";

					m++;
				}

			}
		}
	}

	if (m == 0) {
		cout << "Простые числа, которые меньше пятидесяти не найдены!" << endl << endl;
		printf("========================================================================\n");
		return 0;
	}

	cout << endl << endl << endl << "Количество простых чисел, которые меньше пятидесяти: " << m << endl << endl;

	printf("========================================================================\n");



	cout << endl << endl << "AND" << endl << endl;



	cout << endl << ">>>   БИНАРНЫЙ ПОИСК   <<<" << endl;
	printf("========================================================================\n");

	cout << endl << "Простые числа, которые меньше пятидесяти: " << endl << endl;

	// Сортировка массива
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			for (int k = a - 1; k > j; k--)
				if (arr[i][k] < arr[i][k - 1]) {

					int tmp = arr[i][k];
					arr[i][k] = arr[i][k - 1];
					arr[i][k - 1] = tmp;

				}
		}
	}

	//Вывод массива
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}














	cout << endl << endl;

	int key;

	cout << "Введите key: " << endl;
	cin >> key;

	int left = 0; 
	int right = a;
	int search = -1; // найденный индекс элемента равен -1 (элемент не найден)

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
		
			while (left <= right) // пока левая граница не "перескочит" правую
			{

						int mid = (left + right) / 2; // ищем середину отрезка

						if (key == arr[i][mid]) {  // если ключевое поле равно искомому
							search = mid;     // мы нашли требуемый элемент,
							break;            // выходим из цикла
						}
						if (key < arr[i][mid])     // если искомое ключевое поле меньше найденной середины
							right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
						else                  // иначе
							left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
						arr[i+1][j];
						
			}
			
			if (search == -1) {     // если индекс элемента по-прежнему -1, элемент не найден
				printf("Элемент не найден!\n");
				arr[i+1][j];
			}
			else {         // иначе выводим элемент, его ключ и значение
				printf("%d. key= %d. r[%d]=%d", search, arr[i][search]);
				getchar(); getchar();
			}
			
		}
	}




















	
	printf("========================================================================\n");




	cout << endl;

	system("pause");
	return 0;
}