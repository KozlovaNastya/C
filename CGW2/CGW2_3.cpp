#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
class Train {
private:
	int numberOfTrain;
	string pynkt;
	string type;
	string timeOtprav;
	int timePuti;
public:
	Train(int numberOfTrain = 0, string pynkt = "none", string type = "none", string timeOtprav = "none", int timePuti = 0) :
		numberOfTrain(numberOfTrain), pynkt(pynkt), type(type), timeOtprav(timeOtprav), timePuti(timePuti) {}
	void setNumberOfTrain(int n) { numberOfTrain = n; }
	void setPynkt(string p) { pynkt = p; }
	void setType(string t) { type = t; }
	void setTimeOtprav(string t) { timeOtprav = t; }
	void setTimePuti(int tp) { timePuti = tp; }
	int getNumerOfTrain() const { return numberOfTrain; }
	string getPynkt() const { return pynkt; }
	string getType() const { return type; }
	string getTimeOtprav() const { return timeOtprav; }
	int getTimePuti() const { return timePuti; }
	void print() const {
		cout << numberOfTrain << ';' << pynkt << ';' << type << ';' << timeOtprav << ';' << timePuti << endl;
	}
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream inputFile("trains.txt");
	if (!inputFile) {
		cerr << "���������� ������� ���� trains.txt" << endl;
		return 1;
	}
	if (inputFile.peek() == EOF) {
		cerr << "���� trains.txt ����" << endl;
		return 1;
	}
	vector<Train> trains;
	string line;
	while (getline(inputFile, line)) {
		stringstream ss(line);
		string temp;
		Train train;
		getline(ss, temp, ';');
		train.setNumberOfTrain(stoi(temp));
		getline(ss, temp, ';');
		train.setPynkt(temp);
		getline(ss, temp, ';');
		train.setType(temp);
		getline(ss, temp, ';');
		train.setTimeOtprav(temp);
		getline(ss, temp, ';');
		train.setTimePuti(stoi(temp));
		trains.push_back(train);
	}
	inputFile.close();
	sort(trains.begin(), trains.end(), [](const Train& a, const Train& b) {
		return a.getTimeOtprav() < b.getTimeOtprav();
		});
	for (const auto& train : trains) {
		train.print();
	}
	string startTime, endTime;
	cout << "\n������� ��������� ����� (��:��): ";
	cin >> startTime;
	cout << "������� �������� ����� (��:��): ";
	cin >> endTime;
	for (const auto& train : trains) {
		if (train.getTimeOtprav() >= startTime && train.getTimeOtprav() <= endTime) {
			train.print();
		}
	}
	string pynktNazhach;
	cout << "������� ����� ����������: ";
	cin >> pynktNazhach;
	for (const auto& train : trains) {
		if (train.getPynkt() == pynktNazhach) {
			train.print();
		}
	}
	cout << "������ ������ � ����� ���������� " << pynktNazhach << endl;
	for (const auto& train : trains) {
		if (train.getPynkt() == pynktNazhach && train.getType() == "High-speed") {
			train.print();
		}
	}
	Train* fastestTrain = nullptr;
	for (auto& train : trains) {
		if (train.getPynkt() == pynktNazhach) {
			if (fastestTrain == nullptr || train.getTimePuti() < fastestTrain->getTimePuti()) {
				fastestTrain = &train;
			}
		}
	}
	if (fastestTrain) {
		cout << "����� ������� ����� � ����� ���������� " << pynktNazhach << endl;
		fastestTrain->print();
	}
	else {
		cout << "������� � ����� ���������� " << pynktNazhach << " �� �������" << endl;
	}
	return 0;
}