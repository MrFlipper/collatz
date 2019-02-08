all:
	g++ -w collatz.cpp bigNum.cpp bigNum.h -o collatz -O3
ofast:
	g++ -w collatz.cpp bigNum.cpp bigNum.h -o collatz -Ofast
