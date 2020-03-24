objects = main.o fact.o
edit: $(objects)
	g++ -o edit $(objects)
main.o: factMain.cc chapter06.h
	g++ -c factMain.cc
fact.o: fact.cc chapter06.h
	g++ -c fact.cc