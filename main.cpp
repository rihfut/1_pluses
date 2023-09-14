#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>

const int YEAR = 2023;
using namespace std;

class Bus {
private:
	string driverName;
	string busNumber;
	int routeNumber;
	string brand;
	int yearOfStart;
	int mileage;
public:

	//������������
	Bus() : routeNumber(0), yearOfStart(0), mileage(0) {} 
	Bus(const string& _driverName, const string& _busNumber, int _routeNumber, string& _brand, int _yearOfStart, 
		int _mileage) : driverName(_driverName), busNumber(_busNumber), routeNumber(_routeNumber), brand(_brand),
		yearOfStart(_yearOfStart), mileage(_mileage) {}
	Bus(const Bus& other) 
		: driverName(other.driverName), busNumber(other.busNumber),
		routeNumber(other.routeNumber), brand(other.brand),
		yearOfStart(other.yearOfStart), mileage(other.mileage) {}


	void inputBusData() { //������ ����
		cout << "������� ������� � �������� ��������: ";
		cin >> driverName;
		cout << "������� ����� ��������: ";
		cin >> busNumber;
		cout << "������� ����� ��������: ";
		cin >> routeNumber;
		cout << "������� ����� ��������: ";
		cin >> brand;
		cout << "������� ��� ������ ������������: ";
		cin >> yearOfStart;
		cout << "������� ������: ";
		cin >> mileage;
	}


	void displayBusData() const { //������� �����
		std::cout << "������� � �������� ��������: " << driverName << std::endl;
		std::cout << "����� ��������: " << busNumber << std::endl;
		std::cout << "����� ��������: " << routeNumber << std::endl;
		std::cout << "����� ��������: " << brand << std::endl;
		std::cout << "��� ������ ������������: " << yearOfStart << std::endl;
		std::cout << "������: " << mileage << std::endl;
	}


	//������ get
	const string& getDriverName() const {
		return driverName;
	}

	const string& getBusNumber() const {
		return busNumber;
	}

	int getRouteNumber() const {
		return routeNumber;
	}

	const string& getBrand() const {
		return brand;
	}

	int getYearOfStart() const {
		return yearOfStart;
	}

	int getMileage() const {
		return mileage;
	}


	//������ set
	void setDriverName() {
		cin.ignore();
		getline(cin, driverName);
	}

	void setBusNumber() {
		cin.ignore();
		getline(cin, busNumber);
	}

	void setRouteNumber() {
		cin >> routeNumber;
	}
	void setBrand() {
		cin.ignore();
		getline(cin, brand);
	}

	void setYearOfStart() {
		cin >> yearOfStart;
	}

	void setMileage() {
		cin >> mileage;
	}

	//�������
	vector<Bus> filterBusesByRoute(const vector<Bus>& buses, int routeNumber) {
		vector<Bus> filteredBuses;
		for (const Bus& bus : buses) {
			if (bus.routeNumber == routeNumber)
				filteredBuses.push_back(bus);
		}
		return filteredBuses;
	}

	vector<Bus> filterBusesByYears(const vector<Bus>& buses, int years) {
		vector<Bus> filteredBuses;
		for (const Bus& bus : buses) {
			if (YEAR - bus.yearOfStart > 10)
				filteredBuses.push_back(bus);
		}
		return filteredBuses;
	}

	vector<Bus> filterBusesByMileage(const vector<Bus>& buses, int mileage) {
		vector<Bus> filteredBuses;
		for (const Bus& bus : buses) {
			if (bus.mileage > mileage)
				filteredBuses.push_back(bus);
		}
		return filteredBuses;
	}


	//���������� ��� �������
	friend istream& operator>>(istream& is, Bus& bus) {
		getline(is, bus.driverName);
		getline(is, bus.busNumber);
		is >> bus.routeNumber;
		is.ignore();
		getline(is, bus.brand);
		is >> bus.yearOfStart;
		is.ignore();
		is >> bus.mileage;
		is.ignore();
		return is;
	}

	friend ostream& operator<<(ostream& os, const Bus& bus) {
		os << "������� � �������� ��������: " << bus.driverName << endl;
		os << "����� ��������: " << bus.busNumber << endl;
		os << "����� ��������: " << bus.routeNumber << endl;
		os << "����� ��������: " << bus.brand << endl;
		os << "��� ������ ������������: " << bus.yearOfStart << endl;
		os << "������: " << bus.mileage << endl;
		return os;
	}

	//���������� ��������� ���������
	bool operator<(const Bus& other) const {
		return (yearOfStart < other.yearOfStart);
	}
};

//���� ������ � ������ �� �����
void fillArrayFromFile(vector<Bus>& buses, istream& fileStream) {
	int numberOfBuses;
	fileStream >> numberOfBuses;
	fileStream.ignore();

	buses.clear();

	for (int i = 0; i < numberOfBuses; i++) {
		Bus bus;
		fileStream >> bus;
		buses.push_back(bus);
	}
}


//����� ������ � ������� � ����
void writeArrayToFile(vector<Bus>& buses, ostream& fileStream) {
	int numberOfBuses = size(buses);
	fileStream << numberOfBuses << endl;

	for (const Bus& bus : buses) {
		fileStream << bus;
	}
}

//������� ����
void startMenu() {
	cout << "========== ������� ���� ==========" << endl;
	cout << "1. ��������� ������ �������." << endl;
	cout << "2. ��������� ������ �� �����." << endl;
	cout << "3. �������� ���������� �� ��������." << endl;
	cout << "4. �������� ���������� � ��������� ��������." << endl;
	cout << "5. ���������� ���������� � �������� ��������." << endl;
	cout << "6. ������� ������ � �������." << endl;
	cout << "7. ������� ������ � ����." << endl;
	cout << "8. ������� �������." << endl;
	cout << "9. ������� ����������." << endl;
	cout << "0. ��������� ������ � ����������." << endl;
	cout << "===================================" << endl;
}

//���� ��� �������� ����������
void checkMenu() {
	cout << "========== ���� �������� ���������� ==========" << endl;
	cout << "1. ������� � �������� ��������." << endl;
	cout << "2. ����� ��������." << endl;
	cout << "3. ����� ��������." << endl;
	cout << "4. �����." << endl;
	cout << "5. ��� ������ ������������." << endl;
	cout << "6. ������." << endl;
	cout << "==============================================" << endl;
}

//���� ��� ��������� ���������� � ������� get
void casesForGet(int checkNum, vector<Bus>& buses) {
	cout << "����� ���������: " << buses.size() << endl;
	cout << "������� ����� ��������: ";
	int number;
	cin >> number;
	Bus& bus = buses[number - 1];
	switch (checkNum) {
	case 1: { cout << bus.getDriverName() << endl; break; }
	case 2: { cout << bus.getBusNumber() << endl; break; }
	case 3: { cout << bus.getRouteNumber() << endl; break; }
	case 4: { cout << bus.getBrand() << endl;; break; }
	case 5: { cout << bus.getYearOfStart() << endl; break; }
	case 6: { cout << bus.getMileage() << endl; break; }
	}
}

//���� ��� ��������� ���������� � ������� set
void casesForSet(int checkNum, vector<Bus>& buses) {
	cout << "����� ���������: " << buses.size() << endl;
	cout << "������� ����� ��������: ";
	int number;
	cin >> number;
	Bus& bus = buses[number - 1];
	switch (checkNum) {
	case 1: { bus.setDriverName(); break; }
	case 2: { bus.setBusNumber(); break; }
	case 3: { bus.setRouteNumber(); break; }
	case 4: { bus.setBrand(); break; }
	case 5: { bus.setYearOfStart(); break; }
	case 6: { bus.setMileage(); break; }
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Bus> buses;
	int menu;
	while (true) {
		startMenu();
		cin >> menu;
		switch (menu) {
		case 1: {
			int numberOfBuses;
			cout << "������� ���������� ���������: ";
			cin >> numberOfBuses;
			for (int i = 0; i < numberOfBuses; i++) {
				Bus bus;
				cout << "=== ������� ������ ��� �������� #" << (i + 1) << " ===" << endl;
				bus.inputBusData();
				buses.push_back(bus);
			}
			break;
		}
		case 2: {
			string filename;
			cout << "������� �������� �����: ";
			cin >> filename;
			ifstream input(filename);
			if (!input.is_open()) {
				cerr << "�� ������� ������� ���� ��� ������." << endl;
				return 1;
			}
			fillArrayFromFile(buses, input);
			input.close();
			break;
		}
		case 3: {
			cout << "����� ���������: " << buses.size() << endl;
			cout << "������� ����� ��������: ";
			int number;
			cin >> number;
			if (number >= 1 && number <= buses.size()) {
				Bus bus = buses[number - 1];
				bus.displayBusData();
			}
			else {
				cout << "������� � ����� ������� �� ����������." << endl;
			}
			break;
		}
		case 4: {
			cout << "����� �������� �� ������ ���������?" << endl;
			checkMenu();
			int checkNum;
			cin >> checkNum;
			casesForGet(checkNum, buses);
			break;
		}
		case 5: {
			cout << "����� �������� �� ������ ��������?" << endl;
			checkMenu();
			int checkNum;
			cin >> checkNum;
			casesForSet(checkNum, buses);
			break;
		}
		case 6: {
			system("cls");
			int count = 1;
			for (const Bus& bus : buses) {
				cout << "===== ���������� � �������� #" << count << " =====" << endl;
				bus.displayBusData();
				cout << "===================================" << endl;
				count++;
			}
			break;
		}
		case 7: {
			string outputFilename;
			cout << "������� �������� �����: ";
			cin >> outputFilename;
			ofstream output(outputFilename);
			if (!output.is_open()) {
				cerr << "�� ������� ������� ���� ��� ������." << endl;
				return 1;
			}
			writeArrayToFile(buses, output);
			output.close();
			break;
		}
		case 8: {
			system("cls");
			Bus bus;
			cout << "///// ������� ��� ������� ������ /////" << endl;
			vector<Bus> filteredByMileage = bus.filterBusesByMileage(buses, 10000);
			int count1 = 1;
			int count2 = 1;
			int count3 = 1;
			for (const Bus& bus : filteredByMileage) {
				cout << "===== ���������� � �������� #" << count1 << " =====" << endl;
				bus.displayBusData();
				count1++;
				cout << "===================================" << endl;
			}
			cout << "///// ������� �� ������� �������� /////\n" << endl;
			cout << "///// ������� ��� ������ �������� ������ /////" << endl;
			vector<Bus> filteredByRoute = bus.filterBusesByRoute(buses, 2);
			for (const Bus& bus : filteredByRoute) {
				cout << "===== ���������� � �������� #" << count2 << " =====" << endl;
				bus.displayBusData();
				count2++;
				cout << "===================================" << endl;
			}
			cout << "///// ������� �� ������ �������� �������� /////\n" << endl;
			cout << "///// ������� �� ���� ������ ������������ ������ /////" << endl;
			vector<Bus> filteredByYears = bus.filterBusesByYears(buses, 10);
			for (const Bus& bus : filteredByYears) {
				cout << "===== ���������� � �������� #" << count3 << " =====" << endl;
				bus.displayBusData();
				count3++;
				cout << "===================================" << endl;
			}
			cout << "///// ������� ��� ���� ������ ������������ �������� /////\n" << endl;
			break;
		}
		case 9: {
			std::sort(buses.begin(), buses.end());
			break;
		}
		case 0: return 0;
		}
	}
}