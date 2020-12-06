CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
FLAGS= -Wall -fPIC -g

all: myBankd myBanks mains maind	
mains: $(OBJECTS_MAIN) myBanks
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
maind: $(OBJECTS_MAIN) myBankd
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so
myBankd: $(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)
myBanks: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)	
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind