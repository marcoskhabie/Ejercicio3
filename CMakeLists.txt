cmake_minimum_required(VERSION 3.6)
project(Ejercicio2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES Library.c Library.h Material.c Material.h Person.c Person.h Loan.c Loan.h)
add_executable(Ejercicio2 ${SOURCE_FILES})