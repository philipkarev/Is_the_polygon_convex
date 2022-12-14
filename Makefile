a: Point.o Polygon.o main.o
	wg++ -fno-elide-constructors -std=c++11 Point.o Polygon.o main.o

main.o: main.cpp Point.h Polygon.h
	wg++ -fno-elide-constructors -std=c++11 main.cpp -c

Point.o: Point.cpp Point.h
	wg++ -fno-elide-constructors -std=c++11 Point.cpp -c

Polygon.o: Polygon.cpp Polygon.h
	wg++ -fno-elide-constructors -std=c++11 Polygon.cpp -c


