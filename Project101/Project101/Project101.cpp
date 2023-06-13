2.	#include <vector>
#include <iostream>
#include "inout.h" // подключаем заголовочный файл, 
// где объявлена функция print()

project(myproject)
add_library(inoutlib read.cpp print.cpp)
add_executable(myexecutable main.cpp)
target_link_libraries(myexecutable inoutlib)

void print(std::vector<int>& vec) // реализация функции print()
{
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
