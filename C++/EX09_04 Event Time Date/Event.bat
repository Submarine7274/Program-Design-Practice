g++ --std=c++14 -c -o Time.o Time.cpp
g++ --std=c++14 -c -o Date.o Date.cpp
g++ --std=c++14 -c -o Event.o Event.cpp
g++ --std=c++14 -c -o EventTest.o EventTest.cpp
g++ --std=c++14 -o Event.exe Event.o Date.o Time.o EventTest.o 