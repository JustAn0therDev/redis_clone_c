#!/bin/bash

g++ -pthread -std=c++11 ../black_marlin.hpp ../black_marlin.cpp ../util.hpp ../util.cpp catch2.hpp black_marlin_tests.cpp util_tests.cpp -o unittests
./unittests
