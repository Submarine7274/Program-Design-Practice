g++ --std=c++14 -c -o Account.o Account.cpp
g++ --std=c++14 -c -o AccountTest.o AccountTest.cpp
g++ --std=c++14  -o Account.exe Account.o AccountTest.o
Account.exe