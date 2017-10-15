#!/bin/bash

if [ \( "${1}" = "--help" \) -o \( "${1}" = "-h" \) ]; then
  echo "This script builds the example. Really it just calls gg or clang with appropriate options"
  echo "Call ./build [target]"
  echo "Where target is"
  echo "  basic-gcc          Makes usual app with gcc"
  echo "  basic-gcc-asan     Attempts to use AddressSanitizer with gcc"
  echo "  basic-clang-asan   Makes app with clang and AddressSanitizer"
  echo "  basic-clang-fuzz   Full: clang, AddressSanitizer and libfuzzer"  
  exit 0
fi


if [ "${1}" = "basic-gcc" ]; then
  echo "Making basic app with gcc"
  ODIR="./obj/basic/"
  mkdir -p ${ODIR}
  rm -f ${ODIR}"/*"
  gcc -g -Wall -I"./src" -c ./src/func2.c -o ${ODIR}"/func2.o"
  gcc -g -Wall -I"./src" -c ./src/main.c -o ${ODIR}"main.o"
  gcc ${ODIR}"/main.o" ${ODIR}"/func2.o" -o ./bin/basic-gcc
  exit 0
fi
  
if [ "${1}" = "basic-gcc-asan" ]; then
  echo "Making basic app with gcc and asan"
  ODIR="./obj/basic-asan/"
  mkdir -p ${ODIR}
  rm -f ${ODIR}"/*"
  gcc -g -Wall -I"./src" -fsanitize=address -c ./src/func2.c -o ${ODIR}"/func2.o"
  gcc -g -Wall -I"./src" -fsanitize=address -c ./src/main.c -o ${ODIR}"main.o"
  gcc ${ODIR}"/main.o" ${ODIR}"/func2.o" -fsanitize=address -o ./bin/basic-gcc-asan
  exit 0
fi

if [ "${1}" = "basic-clang-asan" ]; then
  echo "Making basic app with clang and asan"
  ODIR="./obj/basic-asan/"
  mkdir -p ${ODIR}
  rm -f ${ODIR}"/*"
  clang -g -Wall -I"./src" -fsanitize=address -c ./src/func2.c -o ${ODIR}"/func2.o"
  clang -g -Wall -I"./src" -fsanitize=address -c ./src/main.c -o ${ODIR}"main.o"
  clang ${ODIR}"/main.o" ${ODIR}"/func2.o" -fsanitize=address -o ./bin/basic-clang-asan
  exit 0
fi

if [ "${1}" = "basic-clang-fuzz" ]; then
  echo "Making basic app with clang and asan and fuzzer"
  ODIR="./obj/basic-clang-fuzz/"
  mkdir -p ${ODIR}
  rm -f ${ODIR}"/*"
  clang -g -Wall -I"./src" -fsanitize=address -c ./src/func2.c -o ${ODIR}"/func2.o"
  clang -g -Wall -I"./src" -fsanitize=address -fsanitize-coverage=trace-pc-guard -c ./src/fuzz2.c -o ${ODIR}"/fuzz2.o"
  clang -g -Wall -fsanitize=address,fuzzer ${ODIR}"/func2.o" ${ODIR}"/fuzz2.o" -o ./bin/basic-clang-fuzz  
  exit 0
fi

echo "Sorry, maybe you've requested incorrect target."

