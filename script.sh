#!/bin/bash

module load compilers/gnu-5.4.0
make

./tema2_neopt /export/asc/tema2/input
./compare out1 /export/asc/tema2/out1 0.001
./compare out2 /export/asc/tema2/out2 0.001
./compare out3 /export/asc/tema2/out3 0.001
# ./compare out4 /export/asc/tema2/out4 0.001
# ./compare out5 /export/asc/tema2/out5 0.001
# ./compare out6 /export/asc/tema2/out6 0.001
# ./compare out7 /export/asc/tema2/out7 0.001
# ./compare out8 /export/asc/tema2/out8 0.001
# ./compare out9 /export/asc/tema2/out9 0.001
# ./compare out10 /export/asc/tema2/out10 0.001
# ./compare out11 /export/asc/tema2/out11 0.001
# ./compare out12 /export/asc/tema2/out12 0.001
# ./compare out13 /export/asc/tema2/out13 0.001
# ./compare out14 /export/asc/tema2/out14 0.001
# ./compare out15 /export/asc/tema2/out15 0.001

valgrind --tool=memcheck --leak-check=full ./tema2_neopt /export/asc/tema2/input_valgrind &> neopt.memory
valgrind --tool=cachegrind --branch-sim=yes ./tema2_neopt /export/asc/tema2/input_valgrind &> neopt.cache

./tema2_blas /export/asc/tema2/input
./compare out1 /export/asc/tema2/out1 0.001
./compare out2 /export/asc/tema2/out2 0.001
./compare out3 /export/asc/tema2/out3 0.001
# ./compare out4 /export/asc/tema2/out4 0.001
# ./compare out5 /export/asc/tema2/out5 0.001
# ./compare out6 /export/asc/tema2/out6 0.001
# ./compare out7 /export/asc/tema2/out7 0.001
# ./compare out8 /export/asc/tema2/out8 0.001
# ./compare out9 /export/asc/tema2/out9 0.001
# ./compare out10 /export/asc/tema2/out10 0.001
# ./compare out11 /export/asc/tema2/out11 0.001
# ./compare out12 /export/asc/tema2/out12 0.001
# ./compare out13 /export/asc/tema2/out13 0.001
# ./compare out14 /export/asc/tema2/out14 0.001
# ./compare out15 /export/asc/tema2/out15 0.001

valgrind --tool=memcheck --leak-check=full ./tema2_blas /export/asc/tema2/input_valgrind &> blas.memory
valgrind --tool=cachegrind --branch-sim=yes ./tema2_blas /export/asc/tema2/input_valgrind &> blas.cache

./tema2_opt_m /export/asc/tema2/input
./compare out1 /export/asc/tema2/out1 0.001
./compare out2 /export/asc/tema2/out2 0.001
./compare out3 /export/asc/tema2/out3 0.001
# ./compare out4 /export/asc/tema2/out4 0.001
# ./compare out5 /export/asc/tema2/out5 0.001
# ./compare out6 /export/asc/tema2/out6 0.001
# ./compare out7 /export/asc/tema2/out7 0.001
# ./compare out8 /export/asc/tema2/out8 0.001
# ./compare out9 /export/asc/tema2/out9 0.001
# ./compare out10 /export/asc/tema2/out10 0.001
# ./compare out11 /export/asc/tema2/out11 0.001
# ./compare out12 /export/asc/tema2/out12 0.001
# ./compare out13 /export/asc/tema2/out13 0.001
# ./compare out14 /export/asc/tema2/out14 0.001
# ./compare out15 /export/asc/tema2/out15 0.001

valgrind --tool=memcheck --leak-check=full ./tema2_opt_m /export/asc/tema2/input_valgrind &> opt_m.memory
valgrind --tool=cachegrind --branch-sim=yes ./tema2_opt_m /export/asc/tema2/input_valgrind &> opt_m.cache

make clean