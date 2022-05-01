BUILDID=$(shell date +%m/%d/%Y-%H:%M:%S)

RECIPES=~/cs/recipes.txt

INCLUDE=-Isrc

TESTS=tests
MYTEST=$(TESTS)/mytest.cpp
SHARED_TEST=$(TESTS)/SharedPtr_test.cpp

all: clean mytest SharedPtr_test

mytest: $(MYTEST) 
	@printf "\n\n-----------------------------------$(BUILDID)\n\n\n"
	g++ -std=c++11  -g -Wall -Wextra -pedantic $(INCLUDE) -o mytest \
													 $(MYTEST)

SharedPtr_test: $(SHARED_TEST) 
	@printf "\n\n-----------------------------------$(BUILDID)\n\n\n"
	g++ -std=c++11  -g -Wall -Wextra -pedantic $(INCLUDE) -o SharedPtr_test \
												$(SHARED_TEST) -pthread

gdb1: mytest
	gdb mytest

gdb2: SharedPtr_test
	gdb SharedPtr_test

val1: mytest
	valgrind -v --leak-check=full --show-leak-kinds=all ./mytest

val2: SharedPtr_test
	valgrind -v --leak-check=full --show-leak-kinds=all ./SharedPtr_test -t 30

test1: mytest
	./mytest

test2:
	./SharedPtr_test -t 30 # > debug.txt 2> err.txt 


recipes: $(RECIPES)
	gedit $(RECIPES) &




ig: .gitignore
	vi .gitignore

git: clean
	git add -A .
	git commit -m "commit on $(BUILDID)"
	git push

git-%: clean 
	git add -A
	git commit -m "$(@:git-%=%)  $(BUILDID)"
	git push origin master

clean:
	rm -f *.o mytest SharedPtr_test *.txt

