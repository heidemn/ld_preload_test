.PHONY: all clean run

all: inspect_open.so run

clean:
	rm -f inspect_open.so

run:
	LD_PRELOAD=./inspect_open.so head -1 inspect_open.c

inspect_open.so: inspect_open.c
	gcc -shared -fPIC inspect_open.c -o inspect_open.so -ldl
