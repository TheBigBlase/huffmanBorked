SRC 	= src/*.c
OJB 	= $(SRC:.c=.o)
OUT 	= build

CC 			= /usr/bin/gcc
CFLAGS 	= -ansi -Wall -std=c99
CFDEBUG = -ansi -Wall -g -std=c99 
RM 			= /bin/rm -f

%.o: %.c
	 $(CC) -c $(CFLAGS)

huffman: $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(OUT)/a.out
	
clean:
		$(RM) $(OBJ) a.out
debug: $(SRC)
		$(CC) $(SRC) $(CFDEBUG) -o $(OUT)/a.out

debugRun: $(SRC)
		$(CC) $(SRC) $(CFDEBUG) -o $(OUT)/a.out && goToRoot && gdb build/a.out tests/test.txt

run: $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(OUT)/a.out  && build/a.out tests/test.txt
