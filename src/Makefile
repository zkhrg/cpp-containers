CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c++17 
MAIN_PROJECT=$(wildcard **/*.cc **/**/*.cc **/*.tpp) # list of all the C source files in the project
SOURCES=$(filter-out %.tpp, $(MAIN_PROJECT))
TEST_SOURCES=$(filter-out %.tpp, $(MAIN_PROJECT))
MAIN=check
TEST_RESULT=test
OBJECTS=$(SOURCES:.cc=.o)
TEST_OBJECTS=$(TEST_SOURCES:.cc=.o)
CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)



OS := $(shell uname)
ifeq ($(OS),Linux)
	OPEN= xdg-open report/index.html
	CHECK_LIB = -lgtest -lm -lrt -lpthread -lstdc++
endif

ifeq ($(OS),Darwin)
	OPEN= open report/index.html
	CHECK_LIB = -lgtest -lstdc++
endif


test: $(TEST_OBJECTS)
	# clear
	$(CC) $(CFLAGS) $^ -o $(TEST_RESULT) $(CHECK_LIB)
	./$(TEST_RESULT)


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

git: clean
	git add .
	git commit
	git push origin $(CURRENT_BRANCH)

containers_tests/map_tests/s21_map_test.o: s21_map/*.h s21_map/*.tpp

clean:
	rm -rf $(RESULT) $(OBJECTS) $(TEST_OBJECTS) $(TEST_RESULT) gcov_report* *.gc* report/ *.o $(MAIN)