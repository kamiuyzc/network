src=${wildcard ./*.c}
obj=${patsubst %.c, %.out, ${src}}

ALL:${obj}

./%.out:./%.c
	gcc $< -o $@ -g -Wall

clean:
	-rm -rf ${obj} 3_test 4_test
