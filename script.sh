# !/bin/bash

module load compilers/gnu-5.4.0
make

./tema2_neopt my_input
./compare out1 /export/asc/tema2/out1 0.001
./compare out2 /export/asc/tema2/out2 0.001
./compare out3 /export/asc/tema2/out3 0.001


valgrind --tool=memcheck --leak-check=full ./tema2_neopt /export/asc/tema2/input_valgrind &> neopt.memory
valgrind --tool=cachegrind --branch-sim=yes ./tema2_neopt /export/asc/tema2/input_valgrind &> neopt.cache





./tema2_blas my_input
./compare out1 /export/asc/tema2/out1 0.001
./compare out2 /export/asc/tema2/out2 0.001
./compare out3 /export/asc/tema2/out3 0.001

valgrind --tool=memcheck --leak-check=full ./tema2_blas /export/asc/tema2/input_valgrind &> blas.memory
valgrind --tool=cachegrind --branch-sim=yes ./tema2_blas /export/asc/tema2/input_valgrind &> blas.cache





./tema2_opt_m my_input
./compare out1 /export/asc/tema2/out1 0.001
./compare out2 /export/asc/tema2/out2 0.001
./compare out3 /export/asc/tema2/out3 0.001


valgrind --tool=memcheck --leak-check=full ./tema2_opt_m /export/asc/tema2/input_valgrind &> opt_m.memory
valgrind --tool=cachegrind --branch-sim=yes ./tema2_opt_m /export/asc/tema2/input_valgrind &> opt_m.cache

make clean