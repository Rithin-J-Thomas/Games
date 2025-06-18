#!/bin/bash

g++ main.cpp player.cpp other.cpp  -o run_game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11  &&  ./run_game