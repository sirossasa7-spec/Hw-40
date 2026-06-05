#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Violation
{
    string date;        
    string description;
    double fine;
};

class FineDatabase
{
private:
    map<string, vector<Violation>> database;

public:
    void addViolation(const string& carNumber,
        const string& date,
        const string& description,
        double fine);

    void printAll() const;

    void printByCar(const string& carNumber) const;

    double getTotalFine(const string& carNumber) const;

    void payFine(const string& carNumber);

    void searchByPeriod(const string& startDate,
        const string& endDate) const;
};
