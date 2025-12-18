#!/bin/fish
set -l CFLAGS -Wall -Wextra -fsanitize=address -fsanitize=undefined -O2
set -l INCDIRS -Ivendor/raylib/build/raylib/include
set -l LIBDIRS -Lvendor/raylib/build/raylib
set -l LDFLAGS -lm -lGL -lraylib

gcc src/*.c $CFLAGS $INCDIRS $LIBDIRS $LDFLAGS -o BudgetingApp
