# Exercices
## Compilation
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Execution
once compiled, binaries are found in `./build/codility/` and `./build/travelling-salesman`. Simply launch each binary individually and follow instructions when given. 
Certain binaries allow you to write in your own inputs such as:
```bash
$ ./exercice-1 1 5 1025
1 -> 0
5 -> 1
1025 -> 9

$ ./exercise-2 1 2 3 4 5 -K 3
[ 1 2 3 4 5 ] -> [ 3 4 5 1 2 ]
```
