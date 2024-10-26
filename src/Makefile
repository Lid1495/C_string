compiler=gcc
flags=-Wall -Wextra -Werror -std=c11
comp_files=./tests/testing.c ./tests/test_*.c ./str_func/s21_*.c ./io_func/s21_*.c ./sharp_func/s21_*.c
libcheck = $(shell pkg-config --cflags --libs check) -lm
obj_file=obj_files/
str_funcs=str_func/
io_funcs=io_func/
sharp_funcs=sharp_func/
OS = $(shell uname)
ifeq ($(OS), Darwin)
	costyl_flag=--filter range
else 
	costyl_flag=
endif

all: s21_string.a test gcov_report

s21_string.a: comp_funcs
	ar rc s21_string.a $(obj_file)*.o
	rm $(obj_file)*.o

build: s21_string.c comp_funcs
	$(compiler) $(flags) $< $(obj_file)*.o -o s21_string

comp_funcs: s21_to_upper.o s21_to_lower.o s21_insert.o s21_trim.o s21_sprintf.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memset.o s21_strchr.o s21_strcspn.o s21_strerror.o s21_strlen.o s21_strncat.o s21_strncmp.o s21_strncpy.o s21_strpbrk.o s21_strrchr.o s21_strstr.o s21_strtok.o

s21_to_upper.o: $(sharp_funcs)s21_to_upper.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_to_lower.o: $(sharp_funcs)s21_to_lower.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_insert.o: $(sharp_funcs)s21_insert.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_trim.o: $(sharp_funcs)s21_trim.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_sprintf.o: $(io_funcs)s21_sprintf.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_memchr.o: $(str_funcs)s21_memchr.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_memcmp.o: $(str_funcs)s21_memcmp.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_memcpy.o: $(str_funcs)s21_memcpy.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_memset.o: $(str_funcs)s21_memset.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strchr.o: $(str_funcs)s21_strchr.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strcspn.o: $(str_funcs)s21_strcspn.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strerror.o: $(str_funcs)s21_strerror.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strlen.o: $(str_funcs)s21_strlen.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strncat.o: $(str_funcs)s21_strncat.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strncmp.o: $(str_funcs)s21_strncmp.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strncpy.o: $(str_funcs)s21_strncpy.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strpbrk.o: $(str_funcs)s21_strpbrk.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strrchr.o: $(str_funcs)s21_strrchr.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strstr.o: $(str_funcs)s21_strstr.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

s21_strtok.o: $(str_funcs)s21_strtok.c
	$(compiler) $(flags) -c $^ -o $(obj_file)$@

#temp:
#$(compiler) $(flags) s21_string.c ./str_func/s21_*.c ./io_func/s21_*.c ./sharp_func/s21_*.c
#./a.out

clean:
	rm -rf s21_string *.out *.o test *.gcda html_output_directory *gcno s21_report s21_report.info val.txt
	rm -rf $(obj_file)*.o
	rm -rf s21_string.a

test: 
	$(compiler) $(flags) -lcheck $(comp_files) $(libcheck) -o test 
	./test

valgrind: clean
	$(compiler) $(flags) -g -lcheck $(comp_files) $(libcheck) -o test 
	leaks -atExit -- ./test	

gcov_report: clean
	$(compiler) $(flags) -lcheck $(comp_files) $(libcheck) --coverage -o s21_report
	./s21_report
	lcov $(costyl_flag) -o s21_report.info -c -d .
	genhtml -o html_output_directory s21_report.info
	open ./html_output_directory/index.html

clang:
	clang-format -style=Google -i *.c
	clang-format -style=Google -i io_func/*.c
	clang-format -style=Google -i tests/*.c
	clang-format -style=Google -i sharp_func/*.c
	clang-format -style=Google -i str_func/*.c

rebuild: clean build
