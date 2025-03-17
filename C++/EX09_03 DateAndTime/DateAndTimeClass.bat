g++ --std=c++14 -c -o DateAndTimeClass.o DateAndTimeClass.cpp
g++ --std=c++14 -c -o DateAndTimeClassTest.o DateAndTimeClassTest.cpp
g++ --std=c++14 -o DateAndTimeClassTest.exe DateAndTimeClassTest.o DateAndTimeClass.o
DateAndTimeClassTest.exe