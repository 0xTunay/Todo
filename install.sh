#!/bin/bash
cd build || mkdir -p build && cd build
cmake ..
make
./Todo
cd ..