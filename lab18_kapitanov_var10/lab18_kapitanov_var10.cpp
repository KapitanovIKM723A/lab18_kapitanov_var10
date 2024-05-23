#include <iostream>
#include <cmath>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int value = 0) : value(value) {}
    bool isPrime() const {
        if (value <= 1) return false;
        for (int i = 2; i <= sqrt(value); i++) {
            if (value % i == 0) return false;
        }
        return true;
    }
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }
    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }
    Number operator*(const Number& other) const {
        return Number(value * other.value);
    }
    Number operator/(const Number& other) const {
        if (other.value == 0) {
            throw invalid_argument("Division by zero");
        }
        return Number(value / other.value);
    }
    bool operator==(const Number& other) const {
        return value == other.value;
    }
    friend ostream& operator<<(ostream& os, const Number& number) {
        os << number.value;
        return os;
    }
};
int main() {
    setlocale(LC_ALL, "ukr");
    Number num1(17);
    Number num2(4);
    cout << "Число 1: " << num1 << (num1.isPrime() ? " Є простим" : " Не є простим") << endl;
    cout << "Число 2: " << num2 << (num2.isPrime() ? " Є простим" : " Не є простим") << endl;
    Number sum = num1 + num2;
    cout << "Сума: " << sum << endl;
    Number diff = num1 - num2;
    cout << "Рiзниця: " << diff << endl;
    Number product = num1 * num2;
    cout << "Добуток: " << product << endl;
    try {
        Number quotient = num1 / num2;
        cout << "Частка: " << quotient << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    bool isEqual = (num1 == num2);
    cout << "Числа " << (isEqual ? "однакові" : "різнi") << endl;
    return 0;
}