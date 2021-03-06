CXXFLAGS := -Wall -Werror -g -std=c++11 -stdlib=libc++

all: tally tally.s

tally: tally.o
	$(CXX) $(CXXFLAGS) -o $@ $<

tally.s: tally.cc
	$(CXX) $(CXXFLAGS) -S $<

clean:
	rm -f tally tally.s *.o *~
