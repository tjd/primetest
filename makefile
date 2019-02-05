####################################################################
#
# Makefile for CMPT 135 Spring 2019, SFU Surrey.
#
#####################################################################

# Set the C++ compiler options:
#   -std=c++14 compiles using the C++14 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -O3 -std=c++11 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

all: primetest

primetest: primetest.o prime.o
	g++ -o primetest primetest.o prime.o

prime.o: prime.cpp prime.h

# tool.o: tool.cc support.hh

# support.o: support.hh support.cc

clean:
	rm -f prime.o primetest.o primetest
