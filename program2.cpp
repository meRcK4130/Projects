

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double a = -0.2;
const double b = 0.2;

/*
  Computes S(x) using recurrence:
  t0 = x^4 / 4
  t_{n+1} = t_n * ((2n+4)(2n+5))/((n+1)(n+5)) * x
*/
double s(double x, double eps) {
    double term = (x * x * x * x) / 4.0;
    double sum = term;
    int n = 0;

    while (abs(term) >= eps) {
        n = n + 1;
        double factor = ((2.0*n + 4.0)*(2.0*n + 5.0)) / ((n + 1.0)*(n + 5.0));
        term = term * factor * x;
        sum += term;
    }
    return sum;
}

int main() {
    bool ok = true;
    double x = 0.0;
    double eps = 0.0;

    cout << "executor: student\n";
    cout << "program: variant 156, compute S(x)\n";

    cout << "enter x:\n";
    cin >> x;

    if (cin.fail()) {
        ok = false;
        cout << "***** error\n";
        cout << "failed to read x\n";
    }

    if (ok && (x < a || x > b)) {
        ok = false;
        cout << "***** error\n";
        cout << "x outside domain [-0.2, 0.2]\n";
    }

    if (ok) {
        cout << "enter eps:\n";
        cin >> eps;

        if (cin.fail()) {
            ok = false;
            cout << "***** error\n";
            cout << "failed to read eps\n";
        } else if (eps <= 0.0) {
            ok = false;
            cout << "***** error\n";
            cout << "eps must be positive\n";
        }
    }

    double result = 0.0;
    cout << "***** do calculations ... \n";

    if (ok) {
        result = s(x, eps);
        cout << "done\n";

        cout << scientific << setprecision(5);
        cout << "for x = " << x << endl;

        cout << scientific << setprecision(8);
        cout << "for eps = " << eps << endl;

        cout << fixed << setprecision(9);
        cout << "result = " << result << endl;
    }

    return 0;
}