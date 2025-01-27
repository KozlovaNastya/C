#include <iostream>
#include <ctime>
#include <cctype>
using namespace std;
int getValue1(const int nmax) {
	while (true) {
		int n;
		cin >> n;
		if (cin.fail() || n > 10 || n < 1) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������� �������, ��������� ������" << endl;
		}
		else{
			cin.ignore(32767, '\n');
			return n;
		}
	}
}
int getValue2() {
	while (true) {
		int otv;
		cin >> otv;
		if (cin.fail() || (otv != 1 && otv != 0)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������� ������ �����, ��������� ������" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			return otv;
		}
	}
}
int getValue3() {
	while (true) {
		int ch;
		cin >> ch;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������� ������ ��������, ��������� ������" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			return ch;
		}
	}
}
int znak(int array[], int n) {
	int kol = 0;
	for (int i = 0; i < n - 1; i++)
		if (array[i] >= 0 && array[i + 1] < 0 || array[i] < 0 && array[i + 1] >= 0)
			kol++;
	return kol;
}
void proiz(int array[], int n) {
	int proiz, kol1, kol2, i;
	proiz = 1;
	kol1 = 0;
	kol2 = 0;
	for (i = 0; i < n; i++)
		if (array[i] == 0) {
			kol1 = i;
			break;
		}
	for (i = kol1 + 1; i < n; i++)
		if (array[i] == 0) {
			kol2 = i;
			break;
		}
	if (kol2 == 0)
		cout << "H�� ���� ������� ���������" << endl;
	else {
		for (i = kol1 + 1; i < kol2; i++)
			proiz *= array[i];
		cout << "������������  ��������� �������, ������������� ����� ������ � ������ �������� ���������� = " << proiz << endl;
	}
}
void uborka(int array[], int n, int P) {
	int chet = 0;
	for (int i = 0; i < n; i++)
		if (array[i] == P)
			chet++;
	if (chet == 0)
		cout << "����� ��������� � ������� ���";
	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - 1 - i; j++)
				if (array[j] == P) {
					array[j] = array[j + 1];
					array[j + 1] = P;
				}
		for (int i = 0; i < n; i++)
			if (array[i] == P)
				array[i] = 0;
		cout << "����� ������:" << endl;
		for (int i = 0; i < n; i++)
			cout << array[i] << " ";
	}
}
int main() {
	setlocale(LC_ALL, ".1251");
	const int nmax = 10;
	int P, array[nmax];
	cout << "������� ������ 1 <= ���-�� ��������� ������� >= " << nmax << endl;
	int n = getValue1(nmax);
	cout << "�� ������ ��������� ������ ����? (����� �� = 1; ��� = 0)" << endl;
	int otv = getValue2();
	if (otv == 1) {
		cout << "������� �������� �������:" << endl;
		for (int i = 0; i < n; i++)
			cin >> array[i];
	}
	else {
		srand(time(0));
		cout << "������� ������ ������� ���������" << endl;
		int niz = getValue3();
		cout << "������� ������� ������� ���������" << endl;
		int verh = getValue3();
		if (niz < verh) {
			for (int i = 0; i < n; i++)
				array[i] = niz + rand() % verh;
		}
	}
	cout << "�������� ������:" << endl;
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl << "���������� ������� ����� = " << znak(array, n) << endl;
	proiz(array, n);
	cout << "������� �������, ������� ������ ������" << endl;
	cin >> P;
	uborka(array, n, P);
	return 0;
}