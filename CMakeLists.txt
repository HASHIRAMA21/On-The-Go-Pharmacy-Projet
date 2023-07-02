cmake_minimum_required(VERSION 3.22)
project(baune_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(baune_project main.cpp src/classes/User.cpp src/headers/User.h src/classes/Admin.cpp src/headers/Admin.h src/classes/Product.cpp src/headers/Product.h src/classes/Category.cpp src/headers/Category.h src/classes/Prescription.cpp src/headers/Prescription.h src/classes/Shopping_cart.cpp src/headers/Shopping_cart.h src/classes/Stock.cpp src/headers/Stock.h src/classes/1.cpp src/classes/2.cpp)
