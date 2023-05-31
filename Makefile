exec = xc
flag = -g -O3

sources = $(wildcard src/*.c)


# Objects are assigned value of sources by replacing .c with .o
objFiles = $(sources:.c=.o)

$(exec): $(objFiles)
	gcc $(flag) $(objFiles) -o $(exec)

# Rule for creating .o with .c and .h as dependencies
%o: %.c include/%.h
	gcc -c $(flag) $< -o $@
# $@ is the filename of the target of the rule i.e %.o and $< is the name of first prerequisite


#Targets
install:
	make
clean:
	rm -rf *.out
	rm -rf *.o
	rm -rf src/*o
	rm -rf src/*out
	rm -rf xc

