CC = g++
CFLAGS = -std=c++20

all: program

program:	main.o book_info_cpp_copy.o	reader_info_copy.o	menu_1.o	menu_2.o
	$(CC) $(CFLAGS) -o program_main main.o book_info_cpp_copy.o reader_info_copy.o	menu_1.o	menu_2.o

main.o: main.cpp book_info_copy.h reader_info_copy.h	menu_1.h	menu_2.h
	$(CC) $(CFLAGS) -c main.cpp

book_info.o: book_info_cpp.cpp book_info_copy.h	
	$(CC) $(CFLAGS) -c book_info_cpp_copy.cpp

reader_info.o: reader_info_copy.cpp reader_info_copy.h
	$(CC) $(CFLAGS) -c reader_info_copy.cpp

menu_1.o: menu_1.cpp menu_1.h
	$(CC) $(CFLAGS) -c menu_1.cpp

menu_2.o: menu_2.cpp menu_2.h
	$(CC) $(CFLAGS) -c menu_2.cpp

clean:
	rm -rf *.o program

