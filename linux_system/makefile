src = $(wildcard ./src/*.c)
obj = ${patsubst ./src/%.c,./src/%.o,$(src)}
myArgs = -Wall -g
ALL:main.out

main.out:$(obj) main.o
	gcc $^ -o $@ -I include $(myArgs)

$(obj):src/%.o:src/%.c
	gcc -c $< -o $@ $(myArgs)

main.o:main.c
	gcc -c main.c -o main.o -I include $(myArgs)

clean:
	-rm -rf src/*.o	
	-rm -rf main.out
	-rm -rf main.o

.PHONY:clean