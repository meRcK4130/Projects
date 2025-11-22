#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>

using namespace std;

// Обчислює значення функції для заданого x. №156
long double f(long double x) {
    long double res = cos(20.0 / 54.0)
        - (9.0 * numbers::pi / (58.0 * numbers::e)) * (4.0 / ((x + 5.0) * (x - 12.0)))
        + 15.0 * atan(x - 13.0)
        + log(x - 7.0) / log(8.0);
    cout << "done\n";
    return res;
}

//Перевіряє ОДЗ функції.
bool isInDomain(double x) {
    return (x > 7.0 && x != 12.0);
}

int main() {
    cout << "The author of this program is Mykhailo Lutsiv.\n";
    cout << "This program computes expression by entering x. Variant 156.\n";

    double x;
    cout << "Enter x (x > 7, x != 12): ";
    cin >> x;

    bool inputFail = false;
    if (cin.fail()) {
        cout << "\nwrong input" << endl;
        inputFail = true;
    }
    
    if (!inputFail) {
        cout << "\n***** do calculations ... ";

        if (!isInDomain(x)) {
            cout << "done\n";
            cout << "for x = " << x << "\n";
            cout << "result = undefined" << endl;
        } else {
            long double result = f(x);

            cout << fixed << setprecision(7);
            cout << "for x = " << x << "\n";
            cout << fixed << setprecision(8);
            cout << "result = " << result << endl;
        }
    }

    return 0;
}