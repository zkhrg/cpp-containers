CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c++17 
MAIN_PROJECT=$(wildcard **/*.cc **/**/*.cc) # list of all the C source files in the project
SOURCES=$(filter-out , $(MAIN_PROJECT))
TEST_SOURCES=$(filter-out , $(MAIN_PROJECT))
MAIN=check
TEST_RESULT=test
OBJECTS=$(SOURCES:.cc=.o)
TEST_OBJECTS=$(TEST_SOURCES:.cc=.o)
RESULT=s21_matrix_oop.a
CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)


OS := $(shell uname)
ifeq ($(OS),Linux)
	OPEN= xdg-open report/index.html
	CHECK_LIB = -lgtest -lsubunit -lm -lrt -lpthread -lstdc++
endif

ifeq ($(OS),Darwin)
	OPEN= open report/index.html
	CHECK_LIB = -lgtest -lstdc++
endif

all: $(RESULT)

test: $(TEST_OBJECTS)
	# clear
	$(CC) $(CFLAGS) $^ -o $(TEST_RESULT) $(CHECK_LIB)
	./$(TEST_RESULT)

$(RESULT): $(OBJECTS)
	ar rc $(RESULT) $(OBJECTS)

.cc.o:
	$(CC) -c $(CFLAGS) $< -o $@

gcov_report: $(TEST_SOURCES)
	$(CC) $(CFLAGS) --coverage $^ $(CHECK_LIB) -o $@
	chmod +x *
	./$@ 
	lcov -t  "$@" --ignore-errors mismatch --ignore-errors inconsistent -o $@.info --no-external -c -d .
	genhtml -o report/ $@.info
	$(OPEN)

clang:
	clang-format -style=Google -n $(MAIN_PROJECT)

git:
	git add .
	git commit
	git push origin $(CURRENT_BRANCH)

clean:
	rm -rf $(RESULT) $(OBJECTS) $(TEST_OBJECTS) $(TEST_RESULT) gcov_report* *.gc* report/ *.o $(MAIN)