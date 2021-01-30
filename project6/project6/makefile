./a.out: student.o main.o
	gcc main.o student.o
main.o: main.c student.h
	gcc -c -Wall -std=c99 main.c
student.o: student.c student.h
	gcc -c -Wall -std=c99 student.c
clean:
	rm a.out *.o
test:
	./a.out
