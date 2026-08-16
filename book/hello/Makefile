CFLAGS = -Wall -Wextra -save-temps

all: hello

hello: hello.c
	 $(CC) $(CFLAGS) $< -o $@
watch: 
	@ls *.c | entr make run

run: hello
	@./hello

clean:
	rm -f hello *o *i

.PHONY: all run clean
