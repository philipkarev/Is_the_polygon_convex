//
// Created by phlilp on 14.12.22.
//
#include "Polygon.h"


Polygon::Polygon(Point* array, int length) {

    this->l = length;

    a = new Point[length];

    for (int i = 0; i < length; ++i)
        a[i] = array[i];
}


Polygon::~Polygon() {

    if (l > 0)
        delete [] a;
}

int Polygon::isConvex() {

    for (int i = 0; i < l - 1; ++i) {
        double A = a[i].createLineA(a[i + 1]);
        double B = a[i].createLineB(a[i + 1]);
        double C = a[i].createLineC(a[i + 1]);

        int s = -2;

        for (int j = 0; j < l; ++j) {
            if ((i != j) and (i + 1 != j)) {
                if (s == -2) {
                    if (a[j].sign(A, B, C) == 0) {
                        cout << "It's not a convex polygon.";
                        cout << " Point " << a[j] << " belongs to line: ";
                        cout << A << "x + " << B << "y + " << C;
                        cout << ". This line created by points: ";
                        cout << a[i] << " and " << a[i + 1] << "." << endl;

                        return 0;

                    } else {
                        s = a[j].sign(A, B, C);
                        continue;
                    }
                }

                if (s == a[j].sign(A, B, C))
                    continue;
                else if (a[j].sign(A, B, C) == 0) {
                    cout << "It's not a convex polygon.";
                    cout << " Point " << a[j] << " belongs to line: ";
                    cout << A << "x + " << B << "y + " << C;
                    cout << ". This line created by points: ";
                    cout << a[i] << " and " << a[i + 1] << "." << endl;

                    return 0;
                }
                else {
                    cout << "It's not a convex polygon.";
                    cout << " Point " << a[j] << " makes ";
                    cout << "polygon no convex." << endl;

                    return 0;
                }
            }
        }
    }

    double A = a[0].createLineA(a[l - 1]);
    double B = a[0].createLineB(a[l - 1]);
    double C = a[0].createLineC(a[l - 1]);

    int s = -2;

    for (int j = 1; j < l - 1; ++j) {
        if (s == -2) {
            if (a[j].sign(A, B, C) == 0) {
                cout << "It's not a convex polygon.";
                cout << " Point " << a[j] << " belongs to line: ";
                cout << A << "x + " << B << "y + " << C;
                cout << ". This line created by points: ";
                cout << a[0] << " and " << a[l - 1] << "." << endl;

                return 0;

            } else {
                s = a[j].sign(A, B, C);
                continue;
            }
        }

        if (s == a[j].sign(A, B, C))
            continue;
        else if (a[j].sign(A, B, C) == 0) {
            cout << "It's not a convex polygon.";
            cout << " Point " << a[j] << " belongs to line: ";
            cout << A << "x + " << B << "y + " << C;
            cout << ". This line created by points: ";
            cout << a[0] << " and " << a[l - 1] << "." << endl;

            return 0;
        }
        else {
            cout << "It's not a convex polygon.";
            cout << " Point " << a[j] << " makes ";
            cout << "polygon no convex." << endl;

            return 0;
        }
    }

    return 1;
}


ostream &operator<<(ostream &stream, const Polygon &s) {

    stream << "[";
    for (int i = 0; i < s.l; i++) {
        if (i != 0) {
            stream << ", ";
        }
        stream << s.a[i];
    }
    stream << "]" << endl;

    return stream;
}