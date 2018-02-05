CXX = g++
CXXFLAGS = -O2 -std=c++11
TESTCASE = 27

all: directory solution in out problem

directory:
	-mkdir bin

solution: sol
sol: sol.cpp
	$(CXX) $(CXXFLAGS) -o bin/sol sol.cpp

in: gen_in
gen_in: gen_in.cpp
	$(CXX) $(CXXFLAGS) -o bin/gen_in gen_in.cpp
	-mkdir data
	./bin/gen_in

out: solution gen_out.py
	python gen_out.py $(TESTCASE)

problem: problem.pdf
problem.pdf: problem.md
	pandoc -o problem.pdf problem.md --latex-engine=xelatex --wrap=preserve

.PHONY: clean
clean:
		-rm -rf data/
		-rm -rf bin
		-rm problem.pdf
