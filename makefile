all:
	g++ collatz.cpp bigNum.cpp bigNum.h -o collatz -O3
ofast:
	g++ collatz.cpp bigNum.cpp bigNum.h -o collatz -Ofast
