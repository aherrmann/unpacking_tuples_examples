# Unpacking Tuples - Examples

Example codes for my blog-post [Unpacking Tuples in
C++14](http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14).

## Usage

Build using CMake as follows.

``` sh
src="$PWD"
mkdir ../build && cd ../build
cmake "$src"
# Or, to specifiy the compiler (e.g. Clang)
# cmake -DCMAKE_CXX_COMPILE=clang++
make -j && make test
```

## Requirements

* CMake >= 3.1
* C++ 14 compiler and standard library

 Tested with the following compilers:

 - GCC 5.3.0
 - Clang 3.6.2
 - Clang 3.7.1

## LICENSE

The code is licensed under the MIT license.
