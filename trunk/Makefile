CFLAGS 	= `fltk2-config --cxxflags`
LDFLAGS = `fltk2-config --ldflags`

ced: ced.o control.o test.o
	g++ -o  ced.exe test.o ced.o control.o $(LDFLAGS)
	
control.o: control.cpp control.h
	g++ $(CFLAGS) -c control.cpp
	
ced.o: ced.cpp ced.h
	g++ $(CFLAGS) -c ced.cpp

test.o: test.cpp
	g++ $(CFLAGS) -c test.cpp

clean:
	rm *.o
