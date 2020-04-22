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
	cout << "Разрешены только данные числа - 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47" << endl;


	cin >> key;

	/*
	while (key != 1 &&
		key != 2 &&
		key != 3 &&
		key != 5 &&
		key != 7 &&
		key != 11 &&
		key != 13 &&
		key != 17 &&
		key != 19 &&
		key != 23 &&
		key != 29 &&
		key != 31 &&
		key != 37 &&
		key != 41 &&
		key != 43 &&
		key != 47) {
		cout << "ЕЩЕ РАЗ !!!!!!!!!" << endl;
		cin >> key;

	}*/

	int left = 0; 
	int right = a;
	int search = -1;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
		
		
			
				while (left <= right) 
				{

					int mid = (left + right) / 2; 

					if (key == arr[i][mid]) {  
						search = mid;     
						break;           
					}
					if (key < arr[i][mid])     
						right = mid - 1;  
					else                  
						left = mid + 1;   
				}
				
			if (search == -1) {
				printf("Элемент не найден!\n");
				getchar(); getchar();
			}
			else {
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