all:
	cc main.c main.h
	mv a.out passgen

clean:
	rm *.gch *.ia passgen
