#include "Violations.h"

int main()
{
    FineDatabase db;

    db.addViolation(
        "AA1234BB",
        "2024-03-10",
        "Перевищення швидкості",
        850);

    db.addViolation(
        "AA1234BB",
        "2024-04-15",
        "Проїзд на червоне світло",
        510);

    db.addViolation(
        "BC5678KK",
        "2024-05-20",
        "Неправильне паркування",
        340);

    cout << "\n===== Повна база =====\n";
    db.printAll();

    cout << "\n===== Дані за номером =====\n";
    db.printByCar("AA1234BB");

    cout << "\n===== Сума штрафів =====\n";
    cout << "AA1234BB: "
        << db.getTotalFine("AA1234BB")
        << " грн\n";

    cout << "\n===== Пошук за період =====\n";
    db.searchByPeriod(
        "2024-03-01",
        "2024-04-30");

    cout << "\n===== Оплата штрафів =====\n";
    db.payFine("AA1234BB");

    cout << "\n===== База після оплати =====\n";
    db.printAll();

    return 0;
}