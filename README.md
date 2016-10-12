# CaDiCaL

Radically Simplified Conflict Driven Clause Learning (CDCL) SAT Solver

The goal of CaDiCal is to have a minimalistic CDCL solver,
which is easy to understand and change, while at the same
time not too much slower than state of the art CDCL solvers
if pre-processing is disabled.

First go to the 'build' subdirectory and then run './configure.sh',
followed by 'make'.  This will build the library and the executable
  
  - ./build/libcadical.a

  - ./build/cadical

The default build process requires GNU make but simply issuing

  - cd src; g++ -O3 -DNDEBUG -o ../build/cadical \*.cpp

should also work.  Using the generated 'makefile' compiles seperate
object files, which can be cached, and can be parallelized (for instance
by setting the environment variables CORES, e.g., using 'CORES=4 make').

The header file of the library is in 'src/cadical.hpp'.

You might want to check out options of './configure.sh -h', such as

  - ./configure -p # to measure/profile time spent in functions

  - ./configure -l # to really see what the solver is doing

  - ./configure -a # both above and in addition '-g' for debugging.

The lastest version of CaDiCal can be found on 'github'

  - http://github.com/arminbiere/cadical

which also contains a test suite (use './run-regression.sh').

A plain stable source release can eventually be found at

  - http://fmv.jku.at/cadical

Armin Biere

Mit Okt 12 09:24:50 CEST 2016
