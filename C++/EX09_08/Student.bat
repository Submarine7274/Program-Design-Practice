g++ --std=c++14 -c -o Student.o Student.cpp
g++ --std=c++14 -c -o StudentTest.o StudentTest.cpp
g++ --std=c++14 -o Student.exe Student.o StudentTest.o
Student.exe