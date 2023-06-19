#pragma once
#include <iostream>
#include <set>
#include <vector>
struct Money {
    int rub;
    int kopeks;

    Money(int rub = 0, int kopeks = 0) : rub(rub), kopeks(kopeks) {}

    bool operator<(const Money& other) const {
        if (rub != other.rub) {
            return rub < other.rub;
        }
        return kopeks < other.kopeks;
    }

    friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << money.rub << " rub. " << money.kopeks << " kop.";
        return os;
    }
};