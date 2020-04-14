#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	// ������ �������
	int a;

	cout << "������� ������ �������: ";
	cin >> a;

	// ������� ��� �����
	if (cin.fail()) {
		cout << "��� ����� ��������� ������ �����!" << endl;
		return 0;
	}
	while (a > 15 || a < 2) {
		cout << "�������� ����� ���� � ��������� �� 2 �� 15. ������� ��� ��� ������ �������: ";
		cin >> a;
	}

	// ��������� ������ ��� ������
	int** arr;
	arr = new int*[a];
	for (int i = 0; i < a; i++)
	{
		arr[i] = new int[a];
	}

	// ������
	cout << endl << "������: " << endl << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			arr[i][j] = rand() % 79 + 1;
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}

	cout << endl;




	cout << endl << ">>>   ���������������� �����   <<<" << endl;
	printf("========================================================================\n");

	cout << endl << "������� �����, ������� ������ ����������: " << endl << endl;

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
		cout << "�����, ������� ������ ���������� �� �������!" << endl << endl;
		printf("========================================================================\n");
		return 0;
	}

	cout << endl << endl << endl << "���������� �����, ������� ������ ����������: " << m << endl << endl;

	printf("========================================================================\n");



	cout << endl << endl << "AND" << endl << endl;



	cout << endl << ">>>   �������� �����   <<<" << endl;
	printf("========================================================================\n");

	cout << endl << "������� �����, ������� ������ ����������: " << endl;

	int m1 = 0, n1;

	// ���������� �������
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

	//����� �������
	/*for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}*/

	cout << endl << endl << endl << "���������� �����, ������� ������ ����������: " << m1 << endl << endl;

	printf("========================================================================\n");




	system("pause");
	return 0;
}