#include <iostream>
#include <ctime>
using namespace std;
void massiv(int rows, int columns, int** array) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
}
void Perestanovka(int rows, int columns, int** array) {
	int x;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns-j; j++) {
			x = array[i][j];
			array[i][j] = array[i][columns-j-1];
			array[i][columns-j-1] = x;
		}
	}
	cout << "������������� ������:" << endl;
	massiv(rows, columns, array);
}
void Sum(int rows, int columns, int** array) {
	int sum = 0;
	int k = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (array[i][j] != 0)
				sum = sum + array[i][j];
			else {
				sum = 0;
				j = columns;
			}
		}
		if (sum != 0) {
			cout << "C���� ��������� ������ " << i+1 << " �� ���������� ����� = " << sum << endl;
			sum = 0;
			k++;
		}
	}
	if (k == 0)
			cout << "��� ������ �������� 0" << endl;
}
void Menu(int rows, int columns, int** array) {
	int otv, min, max;
	cout << "1. ���� � ����������" << endl <<
		"2. ���� �������� �������" << endl;
	cin >> otv;
	if (otv == 1){
		system("cls");
		cout << "������� ������ �������" << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++)
				cin >> array[i][j];
		}
	system("cls");
	}
	else if (otv == 2) {
		srand(time(0));
		cout << "������� �������� ����� � �������" << endl;
		cin >> min >> max;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++)
				array[i][j] = min + rand() % max;
		}
		system("cls");
	}
	else {
		cout << "������ �����" << endl;
		system("pause");
		system("cls");
		Menu(rows, columns, array);
	}
}
int main() {
	setlocale(LC_ALL, ".1251");
	const int maxRows = 8;
	const int maxColumns = 10;
	int rows, columns;
	int** array{ new int *[maxRows] {} };
	cout << "������� ����������� �������:" << endl << 
		"���������� ����� ������ �� ��������� 8 � ���� �� ������ 1" << endl <<
		"���������� �������� ������ �� ��������� 10 � ���� �� ������ 1" << endl;
	cin >> rows >> columns;
	while (rows<1 || rows>maxRows) {
		cout << "������ ��� ����� ����� �����" << endl;
		cin >> rows;
	}
	while (columns<1 || columns>maxColumns) {
		cout << "������ ��� ����� ����� ��������" << endl;
		cin >> columns;
	}
	for (int i = 0; i < rows; i++)
		array[i] = new int[maxColumns] {};
	Menu(rows, columns, array);
	cout << "�������� ������:" << endl;
	massiv(rows, columns, array);
	Sum(rows, columns, array);
	Perestanovka(rows, columns, array);
	for (int i = 0; i < rows; i++)
		delete[] array[i];
	delete[] array;
	return 0;
}