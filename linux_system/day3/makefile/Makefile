src=${wildcard ./src/*.c}
obj=${patsubst ./src/%.c, ./obj/%.o, ${src}}

myArgs= -Wall -g
inc_path=./include

ALL:main.out

main.out:main.c ${obj}
	gcc $^ -o $@ -I include ${myArgs}

${obj}:obj/%.o:src/%.c
	gcc -c $< -o $@ ${myArgs} -I ${inc_path}

clean:
	-rm -rf ${obj} main.out
	
.PHONY:clean
