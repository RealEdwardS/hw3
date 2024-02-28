CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -o llrec

llrec-test1: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST1 -o llrec

llrec-test2: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST2 -o llrec

llrec-test3: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST3 -o llrec

llrec-test4: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST4 -o llrec

llrec-test5: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST5 -o llrec

llrec-test6: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST6 -o llrec

llrec-test7: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST7 -o llrec

llrec-test8: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST8 -o llrec

llrec-test9: llrec.h stack.h llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -DTEST9 -o llrec

stack: stack.h stack-test.cpp
	$(CXX) $(CXXFLAGS) stack-test.cpp -o stack

heap: heap.h heap-test.cpp
	$(CXX) $(CXXFLAGS) heap-test.cpp -o heap-test

heap-test10: heap.h heap-test.cpp
	$(CXX) $(CXXFLAGS) heap-test.cpp -DTEST10 -o heap-test

heap-test11: heap.h heap-test.cpp
	$(CXX) $(CXXFLAGS) heap-test.cpp -DTEST11 -o heap-test
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 