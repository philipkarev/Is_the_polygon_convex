#include "Point.h"
#include "Polygon.h"
#include <fstream>

using namespace std;

int main() {

    int n = 0;  // кол-во записанных в файле чисел
    double i;

    fstream F;

    F.open("1.txt");
    if (F) {
        while (!F.eof()) {  // пока не достигнут конец файл
            if (!(F >> i)) {
                cout << "Error: bad value." << endl;
                return -1;
            }
        }
    }
    F.close();

    F.open("1.txt");  // открываем файл в режиме чтения
    if (F) {  // если открытие файла прошло корректно, то
        while (!F.eof()) {  // пока не достигнут конец файл
            F >> i;
            ++n;
        }
    }
    else {
        cout << "Error: no such file in directory." << endl; // если не удалось открыть файл
        F.close();
        return -1;
    }
    F.close();

    if (n == 0) { // пустой файл
        cout << "Error: file is empty." << endl;
        return -1;
    }

    if (n % 2 != 0) { // нечётное кол-во чисел
        cout << "Error: an odd number of numbers in the file." << endl;
        return -1;
    }

    if (n == 2 or n == 4) { // кол-во вершин д.б. > 2
        cout << "Error: it's not a polygon." << endl;
        return -1;
    }

    Point* aP = new Point[n/2];

    F.open("1.txt");  // открываем файл в режиме чтения
    for (int i = 0; i < n / 2; ++i){
        double x, y;
        F >> x;
        F >> y;
        Point p(x, y);
        aP[i] = p;
    }
    F.close();  // закрытие потока

    Polygon p(aP, n / 2);

    if (p.isConvex())
        cout << "The polygon is convex." << endl;

    delete [] aP;

    return 1;
}