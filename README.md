<!-- # passgen-cpp
A CLI password generator written in C++

## Build

```
git clone https://github.com/hnccbits/passgen-cpp.git
cd passgen-cpp
cmake -B build/
cd build
make
```

[Read Design goals](DESIGN.md) -->
![license](https://img.shields.io/badge/license-MIT-brightgreen) 
![license](https://img.shields.io/badge/dependencies-cmake-yellowgreen)

 A CLI password generator, written in C++.

 It generates random passwords according to the configurations provided by the user, such as the length, which set of characters to include in the password, etc. 


# Installing Dependencies :-
 It uses cmake to build the programm so it needs to be installed on system.

to know more about cmake refer to this page :- [cmake](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

 cmake can be installed using the following commands



```cmake
# installing dependencies
sudo apt-get install cmake
```
# Build instructions

```build
# cloning this repository
$ git clone https://github.com/hnccbits/passgen-cpp.git

# going into the reposistory
$ cd passgen-cpp

# generating standard build files
$ cmake -B build/

$ cd build
$ make
```

# Installation

In the passgen-cpp

```
$ cmake -B build/ -DCMAKE_INSTALL_PREFIX="/usr"
$ sudo make install
```
# Features


# Usage
 Run the following command in  the build dir for information on usage
 ```
 ./passgen -H
 ```
 [![usage](blob:https://carbon.now.sh/b69893f8-2938-48cb-846b-a8fc19a3981d)](https://username.github.io/)


