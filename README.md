# Hash table with open addressing
> Implementation of hash table with open addressing and linear probing for resolving collisions.

## Table of Contents
- [Installation](#installation)
- [Features](#features)
- [License](#license)

## Installation
> Warning: This class developed with using C++11 make sure your compiler supports this standard.

To work with the Hash table class just add the file `hash_table.h` to your project.

## Features
For calculating hash value using <a href="https://www.cs.auckland.ac.nz/software/AlgAnim/hash_func.html">multiplication method</a>:

<a href="https://www.codecogs.com/eqnedit.php?latex=h(k)&space;=&space;[m(kAmod1)],&space;A&space;\approx&space;(\sqrt5-1)/2" target="_blank"><img src="https://latex.codecogs.com/gif.latex?h(k)&space;=&space;[m(kAmod1)],&space;A&space;\approx&space;(\sqrt5-1)/2" title="h(k) = [m(kAmod1)], A \approx (\sqrt5-1)/2" /></a>

For resolving collisions using <a href="https://en.wikipedia.org/wiki/Linear_probing">linear probing</a>.

Class Hash table developed as template class with three parameters:
```cpp
template <size_t S, typename K, typename T> class HashTable;
/*
S - size of the table
K - type of key 
T - type of data
*/
```
Hash table can work with custom types. For this you need overloaded <a href="https://en.cppreference.com/w/cpp/utility/hash" target="_blank">std::hash</a> to your types. You can find example of overloading in `struct_profile.h` and `stuct_account.h` as well.

## License
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2019 © <a href="https://github.com/sphinx414" target="_blank">Smolyakov Alexander</a>
