#include <iostream>
using namespace std;
bool Pal(int a) {
	int c = 0, b;
	b = a;
	while (a > 0) {
		c = a % 10 + c * 10;
		a = a / 10;
	}
	return (b == c);
}
int main() {
	setlocale(LC_ALL, ".1251");
	int a, b;
	cout << "������� �����" << endl;
	cin >> a;
	if (Pal(a) && Pal(a * a))
		cout << "����� ������� ���������";
	else cout << "���";
	return 0;
}