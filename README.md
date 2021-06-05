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
![license](https://img.shields.io/badge/forks-13-blue)

![banner](https://github.com/kumarharsh2396/passgen-cpp/blob/main/_%F0%9F%94%90_%E2%89%AA_passgen-cpp_%E2%89%AB_%F0%9F%85%92%F0%9F%85%9B%F0%9F%85%98_tool.png?raw=true)

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


- cloning this repository
```
$ git clone https://github.com/hnccbits/passgen-cpp.git
```
- going into the reposistory
```
$ cd passgen-cpp
```
- generating standard build files
```
$ cmake -B build/
```
```
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

- 


# Usage
 Run the following command in  the ``` build ``` directorry for information on usage
 ```
 $ passgen -H
 ```
 ![usage](https://github.com/kumarharsh2396/passgen-cpp/blob/main/carbon.png?raw=true)


