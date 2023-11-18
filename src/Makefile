CC = g++
ccFLAGS = -lgtest -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
ifeq ($(shell uname), Linux)
LDFLAGS +=-lpthread -lrt -lm -lsubunit
endif
.PHONY: all  clean  test s21_matrix_oop.a rebuild gcov_report

all:  clean s21_matrix_oop.a test

rebuild: clean all

test: clean all_check
	@./all_check

all_check: test_matrix_oop.o s21_matrix_oop.o
	@$(CC) $^ ${CHECKFLAGS} ${ccFLAGS} -o $@
	

%.o: %.cc
	@$(CC) -std=c++17 ${CHECKFLAGS} -c $< -o $@

s21_matrix_oop.a: s21_matrix_oop.o
	@ar rcs $@ $^
	@ranlib $@

clean:
	@rm -rf *.o *.a test *.gcno *.gcda report *.info test.out *.filtered main all_check out

clang_build:
	clang-format -i *.cc *.h

clang:
	clang-format -n *.cc *.h

gcov_report: test
	@$(CC) --coverage test_matrix_oop.cc s21_matrix_oop.cc ${ccFLAGS} ${CHECKFLAGS} ${LIBS} -o test_matrix_oop
	@./test_matrix_oop
	@lcov -c -d . -o coverage.info --rc lcov_branch_coverage=1 --ignore-errors mismatch -t "all_check"
	@lcov --rc lcov_branch_coverage=1 -e coverage.info '*/test_matrix_oop.cc' '*/s21_matrix_oop.cc' -o coverage.info.filtered
	@genhtml coverage.info.filtered --output-directory out

ifeq ($(shell uname), Linux)
	@xdg-open out/index.html
else ifeq ($(shell uname), Darwin)
	@open out/index.html
endif
valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./all_check