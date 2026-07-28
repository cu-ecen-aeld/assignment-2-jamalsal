CROSS_COMPILE ?=
CC = ~/Documents/lsp/assignment1b/arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-linux-gnu/bin/$(CROSS_COMPILE)gcc

writer: writer.c
	$(CC) writer.c -o writer

clean:
	rm -f writer *.o
