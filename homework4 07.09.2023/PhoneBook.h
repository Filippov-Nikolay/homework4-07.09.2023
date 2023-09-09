#pragma once
class PhoneBook {
    char* firstName;
    char* lastName;
    char* surName;

    char* homePhone;
    char* workPhone;

public:
    PhoneBook();
    PhoneBook(const char* fn, const char* ln, const char* sn, const char* hp, const char* wp);
    ~PhoneBook();

    void Input();
    void Print();
    int ResizeArray(PhoneBook*&, int);
    void DelateSubscriber();
    void SearchByFullname();
    void SaveToFile();
    void LoadFromFile();

    // Инпекторы (геттеры)
    char* GetFistName();
    char* GetLastName();
    char* GetSurName();

    char* GetHomePhone();
    char* GetWorkPhone();

    // Модификаторы (сеттеры)
    void SetFistName(const char*);
    void SetLastName(const char*);
    void SetSurName(const char*);

    void SetHomePhone(const char*);
    void SetWorkPhone(const char*);
};