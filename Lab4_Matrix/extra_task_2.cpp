#include <iostream>
#include <ctime>
using namespace std;
int main() {
	int n, S;
	cin >> n;
	srand(0);
	setlocale(LC_ALL, ".1251");
//��������� ������
	int** A = new int*[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[n];
//������� �������
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = rand() % 100;
//����� �������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
//���� �������
	S = 0;
	for (int i = 0; i < n; i++)
		S = S + A[i][i];
	cout << "���� ������� " << S << endl;
	S = 0;
//���� �������� ������ ������������
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n-i; j++)
			S = S + A[i][j];
	cout << "����� �������� ������ ������������ = " << S << endl;
//�������� ������
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
	return 0;
}