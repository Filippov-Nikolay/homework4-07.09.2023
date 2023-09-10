#include "PhoneBook.h"
#include <iostream>
#include <typeinfo>

using namespace std;

// Конструкторы/Деструктор
PhoneBook::PhoneBook() {
    firstName = nullptr;
    lastName = nullptr;
    surName = nullptr;

    homePhone = nullptr;
    workPhone = nullptr;
}
PhoneBook::PhoneBook(const char* fn, const char* ln, const char* sn, const char* hp, const char* wp) {
	// fn - firstName, ln - lastName, sn - surName, hp - homePhone, wp - workPhone

	cout << "Constructor 5 params" << endl;

	firstName = new char[strlen(fn) + 1];
	strcpy_s(firstName, strlen(fn) + 1, fn);

	lastName = new char[strlen(ln) + 1];
	strcpy_s(lastName, strlen(ln) + 1, ln);

	surName = new char[strlen(sn) + 1];
	strcpy_s(surName, strlen(sn) + 1, sn);

	homePhone = new char[strlen(hp) + 1];
	strcpy_s(homePhone, strlen(hp) + 1, hp);

	workPhone = new char[strlen(wp) + 1];
	strcpy_s(workPhone, strlen(wp) + 1, wp);
}
PhoneBook::~PhoneBook() {
    cout << "Destructor\n";

    delete[] lastName;
    delete[] firstName;
    delete[] surName;

    delete[] homePhone;
    delete[] workPhone;
}


void PhoneBook::Input() {
    char buff[100];

    // Имя
    cout << "Введите имя: ";
    cin >> buff;

    if (firstName != nullptr) {
        cout << "Delate firstName -> " << firstName << endl << endl;
        delete[] firstName;
    }

    firstName = new char[strlen(buff) + 1];
    strcpy_s(firstName, strlen(buff) + 1, buff);


    // Фамилия
    cout << "Введите фамилию: ";
    cin >> buff;

    if (lastName != nullptr) {
        cout << "Delate lastName -> " << lastName << endl << endl;
        delete[] lastName;
    }

    lastName = new char[strlen(buff) + 1];
    strcpy_s(lastName, strlen(buff) + 1, buff);


    // Отчество
    cout << "Введите отчество: ";
    cin >> buff;

    if (surName != nullptr) {
        cout << "Delate surName -> " << surName << endl << endl;
        delete[] surName;
    }

    surName = new char[strlen(buff) + 1];
    strcpy_s(surName, strlen(buff) + 1, buff);


    // Домашний номер телефона
    cout << "Введите домашний номер телефона: ";
    cin >> buff;

    if (homePhone != nullptr) {
        cout << "Delate homePhone -> " << homePhone << endl << endl;
        delete[] homePhone;
    }

    homePhone = new char[strlen(buff) + 1];
    strcpy_s(homePhone, strlen(buff) + 1, buff);


    // Рабочий номер телефона
    cout << "Введите рабочий номер телефона: ";
    cin >> buff;

    if (workPhone != nullptr) {
        cout << "Delate workPhone -> " << workPhone << endl << endl;
        delete[] workPhone;
    }

    workPhone = new char[strlen(buff) + 1];
    strcpy_s(workPhone, strlen(buff) + 1, buff);
}
void PhoneBook::Print() {
    cout << "Фамилия: " << lastName << endl;
    cout << "Имя: " << firstName << endl;
    cout << "Отчество: " << surName << endl;

    cout << "Домашний номер тф.: " << homePhone << endl;
    cout << "Раб. номер тф.: " << workPhone << endl;
}
int PhoneBook::ResizeArray(PhoneBook*& array, int oldSize) {
    int newSize = oldSize + 1;
    PhoneBook* newArray = new PhoneBook[newSize];

    for (int i = 0; i < oldSize; i++)
        newArray[i] = array[i];

    array = newArray;

    return newSize;
}
int PhoneBook::DelateSubscriber(PhoneBook*& array, int oldSize, int numberDelate) {
    int newSize = oldSize - 1;
    PhoneBook* newArray = new PhoneBook[newSize];

    for (int i = 0, j = 0; i < oldSize; i++) {
        if (i != numberDelate) {
            newArray[j] = array[i];
            j++;
        }
    }

    array = newArray;
    oldSize = newSize;

    /*
    cout << "FN: " << endl;

    for (int i = 0; i < newSize; i++) {
        array[i].Print();
    }
    cout << endl << endl;
    */

    return newSize;
}
int PhoneBook::SearchByFullname(PhoneBook* array, int size, const char* fn, const char* ln, const char* sn) {
    cout << "Поиск по ФИО: " << endl;
    cout << "Фамилия: " << ln << endl;
    cout << "Имя: " << fn << endl;
    cout << "Отчество: " << sn << endl;

    for (int i = 0; i < size; i++) 
        /*
       cout << "LASTNAME type var: " << typeid(array[i].lastName).name() << ", " << typeid(ln).name() << endl;
       cout << "LASTNAME number symbol: " << strlen(array[i].lastName) << ", " << strlen(ln) << endl;
       cout << "LASTNAME: " << array[i].lastName << ", " << ln << endl;
       */
        if (strcmp(array[i].lastName, ln) == 0 && strcmp(array[i].firstName, fn) == 0 && strcmp(array[i].surName, sn) == 0)
            return i; // Ключ найден       

    return -1; // Ключ не найден
}
void PhoneBook::SaveToFile() {

}
void PhoneBook::LoadFromFile() {

}

// Геттеры
char* PhoneBook::GetFistName() {
	return this->firstName;
}
char* PhoneBook::GetLastName() {
	return this->lastName;
}
char* PhoneBook::GetSurName() {
	return this->surName;
}
char* PhoneBook::GetHomePhone() {
	return this->homePhone;
}
char* PhoneBook::GetWorkPhone() {
	return this->workPhone;
}


// Сеттеры
void PhoneBook::SetFistName(const char* fn) {
    if (firstName != nullptr) {
        cout << "Delate firstName -> " << this->firstName << endl;
    }

    firstName = new char[strlen(fn)+1];
    strcpy_s(firstName, strlen(fn)+1, fn);
}
void PhoneBook::SetLastName(const char* ln) {
    if (lastName != nullptr) {
        cout << "Delate lastName -> " << this->lastName << endl;
    }

    lastName = new char[strlen(ln) + 1];
    strcpy_s(lastName, strlen(ln) + 1, ln);
}
void PhoneBook::SetSurName(const char* sn) {
    if (surName != nullptr) {
        cout << "Delate surName -> " << this->surName << endl;
    }

    surName = new char[strlen(sn) + 1];
    strcpy_s(surName, strlen(sn) + 1, sn);
}
void PhoneBook::SetHomePhone(const char* hp) {
    if (homePhone != nullptr) {
        cout << "Delate homePhone -> " << this->homePhone << endl;
    }

    homePhone = new char[strlen(hp) + 1];
    strcpy_s(homePhone, strlen(hp) + 1, hp);
}
void PhoneBook::SetWorkPhone(const char* wp) {
    if (workPhone != nullptr) {
        cout << "Delate workPhone -> " << this->workPhone << endl;
    }

    workPhone = new char[strlen(wp) + 1];
    strcpy_s(workPhone, strlen(wp) + 1, wp);
}