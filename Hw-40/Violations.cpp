#include "Violations.h"

void FineDatabase::addViolation(const string& carNumber,
    const string& date,
    const string& description,
    double fine)
{
    Violation v;
    v.date = date;
    v.description = description;
    v.fine = fine;

    database[carNumber].push_back(v);
}

void FineDatabase::printAll() const
{
    if (database.empty())
    {
        cout << "База порожня.\n";
        return;
    }

    for (const auto& car : database)
    {
        cout << "\nНомер: " << car.first << endl;

        for (const auto& v : car.second)
        {
            cout << "Дата: " << v.date
                << ", Порушення: " << v.description
                << ", Штраф: " << v.fine << " грн\n";
        }
    }
}

void FineDatabase::printByCar(const string& carNumber) const
{
    auto it = database.find(carNumber);

    if (it == database.end())
    {
        cout << "Автомобіль не знайдено.\n";
        return;
    }

    cout << "\nНомер: " << carNumber << endl;

    for (const auto& v : it->second)
    {
        cout << "Дата: " << v.date
            << ", Порушення: " << v.description
            << ", Штраф: " << v.fine << " грн\n";
    }
}

double FineDatabase::getTotalFine(const string& carNumber) const
{
    auto it = database.find(carNumber);

    if (it == database.end())
        return 0;

    double total = 0;

    for (const auto& v : it->second)
        total += v.fine;

    return total;
}

void FineDatabase::payFine(const string& carNumber)
{
    auto it = database.find(carNumber);

    if (it == database.end())
    {
        cout << "Автомобіль не знайдено.\n";
        return;
    }

    database.erase(it);

    cout << "Усі штрафи за номером "
        << carNumber
        << " сплачені.\n";
}

void FineDatabase::searchByPeriod(const string& startDate,
    const string& endDate) const
{
    cout << "\nПравопорушення за період "
        << startDate << " - "
        << endDate << endl;

    bool found = false;

    for (const auto& car : database)
    {
        for (const auto& v : car.second)
        {
            if (v.date >= startDate &&
                v.date <= endDate)
            {
                found = true;

                cout << "Номер: " << car.first
                    << ", Дата: " << v.date
                    << ", Порушення: " << v.description
                    << ", Штраф: " << v.fine << " грн\n";
            }
        }
    }

    if (!found)
        cout << "Записів не знайдено.\n";
}