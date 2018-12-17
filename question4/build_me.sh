 #!/bin/bash
  gcc -I$HOME/local1/gsl-2.5/include test4.c  -lgsl -lm  -lgslcblas -L$HOME/local1/gsl-2.5/lib

