cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp Cafe.cpp Cafe.h CafeList.cpp CafeList.h Product.cpp Product.h Coffee.cpp Coffee.h Cake.cpp Cake.h Beverage.cpp Beverage.h Order.cpp Order.h ProductDatabase.cpp ProductDatabase.h CitiesList.cpp CitiesList.h CafeLib.h OrderList.cpp OrderList.h)