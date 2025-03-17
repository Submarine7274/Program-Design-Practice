#!/bin/zsh

echo "開始編譯..."
g++ --std=c++14 -c -o ImprovedStudent.o ImprovedStudent.cpp
g++ --std=c++14 -c -o ImprovedStudentTest.o ImprovedStudentTest.cpp
g++ --std=c++14 -o Student ImprovedStudent.o ImprovedStudentTest.o

echo "執行程式..."
./Student

echo "批次處理完成！"

