SRC 	= src/main.c src/triAlphabet.c
OJB 	= $(SRC:.c=.o)
OUT 	= build

CC 			= /usr/bin/gcc
CFLAGS 	= -ansi -pedantic -Wall -O2 -std=c99
CFDEBUG = -ansi -pedantic -Wall -g -std=c99 
RM 			= /bin/rm -f

%.o: %.c
	 $(CC) -c $(CFLAGS)

huffman: $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(OUT)/a.out
	
clean:
		$(RM) $(OBJ) a.out
debug: $(SRC)
		$(CC) $(SRC) $(CFLAGS) $(CFDEBUG) -o $(OUT)/a.out

debugRun: $(SRC)
		$(CC) $(SRC) $(CFLAGS) $(CFDEBUG) -o $(OUT)/a.out && goToRoot && gdb build/a.out

run: $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(OUT)/a.out && goToRoot && build/a.out
