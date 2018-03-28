CC		= gcc
KEY	= -Wall -c

1.e:	1.o
	$(CC) 1.o -o 1.e
1.o:	1.c
	$(CC) 1.c $(KEY)
	
2.e:	2.o
	$(CC) 2.o -o 2.e
2.o:	2.c
	$(CC) 2.c $(KEY)
	
3.e:	3.o
	$(CC) 3.o -o 3.e
3.o:	3.c
	$(CC) 3.c $(KEY)
	
4.e:	4.o
	$(CC) 4.o -o 4.e
4.o:	4.c
	$(CC) 4.c -c
	
5.e:	5.o
	$(CC) 5.o -o 5.e
5.o:	5.c
	$(CC) 5.c -c
	
6.e:	6.o
	$(CC) 6.o -o 6.e
6.o:	6.c
	$(CC) 6.c -c
	
7.e:	7.o
	$(CC) 7.o -o 7.e
7.o:	7.c
	$(CC) 7.c -c
	
clean:
	del 1.o 1.e 1.e
	
all: 1.e
	delete