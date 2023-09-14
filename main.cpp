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

	//Конструкторы
	Bus() : routeNumber(0), yearOfStart(0), mileage(0) {} 
	Bus(const string& _driverName, const string& _busNumber, int _routeNumber, string& _brand, int _yearOfStart, 
		int _mileage) : driverName(_driverName), busNumber(_busNumber), routeNumber(_routeNumber), brand(_brand),
		yearOfStart(_yearOfStart), mileage(_mileage) {}
	Bus(const Bus& other) 
		: driverName(other.driverName), busNumber(other.busNumber),
		routeNumber(other.routeNumber), brand(other.brand),
		yearOfStart(other.yearOfStart), mileage(other.mileage) {}


	void inputBusData() { //Ручной ввод
		cout << "Введите Фамилию и инициалы водителя: ";
		cin >> driverName;
		cout << "Введите Номер автобуса: ";
		cin >> busNumber;
		cout << "Введите Номер маршрута: ";
		cin >> routeNumber;
		cout << "Введите Марку автобуса: ";
		cin >> brand;
		cout << "Введите Год начала эксплуатации: ";
		cin >> yearOfStart;
		cout << "Введите Пробег: ";
		cin >> mileage;
	}


	void displayBusData() const { //Обычный вывод
		std::cout << "Фамилия и инициалы водителя: " << driverName << std::endl;
		std::cout << "Номер автобуса: " << busNumber << std::endl;
		std::cout << "Номер маршрута: " << routeNumber << std::endl;
		std::cout << "Марка автобуса: " << brand << std::endl;
		std::cout << "Год начала эксплуатации: " << yearOfStart << std::endl;
		std::cout << "Пробег: " << mileage << std::endl;
	}


	//Методы get
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


	//Методы set
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

	//Выборки
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


	//Перегрузки для потоков
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
		os << "Фамилия и инициалы водителя: " << bus.driverName << endl;
		os << "Номер автобуса: " << bus.busNumber << endl;
		os << "Номер маршрута: " << bus.routeNumber << endl;
		os << "Марка автобуса: " << bus.brand << endl;
		os << "Год начала эксплуатации: " << bus.yearOfStart << endl;
		os << "Пробег: " << bus.mileage << endl;
		return os;
	}

	//Перегрузка оператора сравнения
	bool operator<(const Bus& other) const {
		return (yearOfStart < other.yearOfStart);
	}
};

//Ввод данных в массив из файла
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


//Вывод данных с массива в файл
void writeArrayToFile(vector<Bus>& buses, ostream& fileStream) {
	int numberOfBuses = size(buses);
	fileStream << numberOfBuses << endl;

	for (const Bus& bus : buses) {
		fileStream << bus;
	}
}

//Главное меню
void startMenu() {
	cout << "========== Главное меню ==========" << endl;
	cout << "1. Заполнить массив вручную." << endl;
	cout << "2. Заполнить массив из файла." << endl;
	cout << "3. Получить информацию об автобусе." << endl;
	cout << "4. Получить информацию о параметре автобуса." << endl;
	cout << "5. Установить информацию в параметр автобуса." << endl;
	cout << "6. Вывести массив в консоль." << endl;
	cout << "7. Вывести массив в файл." << endl;
	cout << "8. Сделать выборки." << endl;
	cout << "9. Сделать сортировку." << endl;
	cout << "0. Закончить работу с программой." << endl;
	cout << "===================================" << endl;
}

//Меню для проверки параметров
void checkMenu() {
	cout << "========== Меню проверки параметров ==========" << endl;
	cout << "1. Фамилия и инициалы водителя." << endl;
	cout << "2. Номер автобуса." << endl;
	cout << "3. Номер маршрута." << endl;
	cout << "4. Марка." << endl;
	cout << "5. Год начала эксплуатации." << endl;
	cout << "6. Пробег." << endl;
	cout << "==============================================" << endl;
}

//Меню для получения параметров с помощью get
void casesForGet(int checkNum, vector<Bus>& buses) {
	cout << "Всего автобусов: " << buses.size() << endl;
	cout << "Введите номер автобуса: ";
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

//Меню для изменения параметров с помощью set
void casesForSet(int checkNum, vector<Bus>& buses) {
	cout << "Всего автобусов: " << buses.size() << endl;
	cout << "Введите номер автобуса: ";
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
			cout << "Введите количество автобусов: ";
			cin >> numberOfBuses;
			for (int i = 0; i < numberOfBuses; i++) {
				Bus bus;
				cout << "=== Введите данные для автобуса #" << (i + 1) << " ===" << endl;
				bus.inputBusData();
				buses.push_back(bus);
			}
			break;
		}
		case 2: {
			string filename;
			cout << "Введите название файла: ";
			cin >> filename;
			ifstream input(filename);
			if (!input.is_open()) {
				cerr << "Не удалось открыть файл для чтения." << endl;
				return 1;
			}
			fillArrayFromFile(buses, input);
			input.close();
			break;
		}
		case 3: {
			cout << "Всего автобусов: " << buses.size() << endl;
			cout << "Введите номер автобуса: ";
			int number;
			cin >> number;
			if (number >= 1 && number <= buses.size()) {
				Bus bus = buses[number - 1];
				bus.displayBusData();
			}
			else {
				cout << "Автобус с таким номером не существует." << endl;
			}
			break;
		}
		case 4: {
			cout << "Какой параметр вы хотите проверить?" << endl;
			checkMenu();
			int checkNum;
			cin >> checkNum;
			casesForGet(checkNum, buses);
			break;
		}
		case 5: {
			cout << "Какой параметр вы хотите изменить?" << endl;
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
				cout << "===== Информация о автобусе #" << count << " =====" << endl;
				bus.displayBusData();
				cout << "===================================" << endl;
				count++;
			}
			break;
		}
		case 7: {
			string outputFilename;
			cout << "Введите название файла: ";
			cin >> outputFilename;
			ofstream output(outputFilename);
			if (!output.is_open()) {
				cerr << "Не удалось открыть файл для записи." << endl;
				return 1;
			}
			writeArrayToFile(buses, output);
			output.close();
			break;
		}
		case 8: {
			system("cls");
			Bus bus;
			cout << "///// Выборка про пробегу начата /////" << endl;
			vector<Bus> filteredByMileage = bus.filterBusesByMileage(buses, 10000);
			int count1 = 1;
			int count2 = 1;
			int count3 = 1;
			for (const Bus& bus : filteredByMileage) {
				cout << "===== Информация о автобусе #" << count1 << " =====" << endl;
				bus.displayBusData();
				count1++;
				cout << "===================================" << endl;
			}
			cout << "///// Выборка по пробегу окончена /////\n" << endl;
			cout << "///// Выборка про номеру маршрута начата /////" << endl;
			vector<Bus> filteredByRoute = bus.filterBusesByRoute(buses, 2);
			for (const Bus& bus : filteredByRoute) {
				cout << "===== Информация о автобусе #" << count2 << " =====" << endl;
				bus.displayBusData();
				count2++;
				cout << "===================================" << endl;
			}
			cout << "///// Выборка по номеру маршрута окончена /////\n" << endl;
			cout << "///// Выборка по году начала эксплуатации начата /////" << endl;
			vector<Bus> filteredByYears = bus.filterBusesByYears(buses, 10);
			for (const Bus& bus : filteredByYears) {
				cout << "===== Информация о автобусе #" << count3 << " =====" << endl;
				bus.displayBusData();
				count3++;
				cout << "===================================" << endl;
			}
			cout << "///// Выборка про году начала эксплуатации окончена /////\n" << endl;
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