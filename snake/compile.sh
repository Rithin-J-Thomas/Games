#!/bin/bash

g++ main.cpp snake.cpp food.cpp other.cpp -o run_game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11  &&  ./run_game
