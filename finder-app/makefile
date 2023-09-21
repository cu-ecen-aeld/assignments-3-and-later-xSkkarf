
CC=gcc
ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	CC=aarch64-none-linux-gnu-gcc
endif

writer : writer.o
	$(CC) $< -o $@

%.o : %.c
	$(CC) -c $< -o $@

.PHONY : clean

clean :
	rm -f *.o writer