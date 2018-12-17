#!/bin/bash
 gcc -I$HOME/local1/gsl-2.5/include test1.c -o test  -lgsl -lm  -lgslcblas -L$HOME/local1/gsl-2.5/lib

