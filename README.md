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

![banner](./image/banner.png)

# About the tool

 A CLI password generator, written in C++.

 It generates random passwords according to the configurations provided by the user, such as the length, which set of characters to include in the password, etc. 

# Features

- Here we are using /dev/urandom file which uses uses truly random data to generate seeds, and make them unpredictable because of the large entropy from the     entropy pool of the Linux kernel. The final password generated has highly randomized data, almost secure and untraceable.
- User can save the generated password in a specified text file.


# Installing Build Dependencies :-
 It uses cmake to build the program so it needs to be installed on system.

To know more about cmake refer to this page :- [https://cmake.org/cmake/help/latest/guide/tutorial/index.html](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

 Cmake can be installed using package managers like apt/dnf by the following ways:-

- For Ubuntu/Debian 


```cmake
sudo apt-get install cmake
```
- For fedora/CentOS
```
sudo dnf install cmake
```

# Build instructions


- Cloning this repository
```
$ git clone https://github.com/hnccbits/passgen-cpp.git
```
- Going into the reposistory
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

# Usage
 Run the following command for information on usage
 ```
 $ passgen -H
 ```
 ![usage](./image/usage.png)

 Run this command to generate a random password with default character set of specified length
 ```
 $ passgen -L <length>
```
Run this command to generate a random password with all character set of default length 8.
```
$ passgen -S
```
Run this command to generate a random password with all character set of specified length
```
$ passgen -S -L <length>
```
Run this command to generate a password of default length with special characters and saves it in the specified file.
- The file path can be absolute or relative.
```
$ passgen -F <file path> -S -L <length>
```
### example for  above commands:-
![example](./image/example.png)





## more about /dev/urandom
 It is a special file that serves as a pseudorandom number generator.
 - This file is present in Unix-like operating systems.
 - Providing access to the environmental noise collected from the device drivers, such as printers, graphic cards, helps us read random data, which is used as the seed for further generation of the password. 
 - to know more about this file refer to to this documentation :- [/dev/urandom](https://man7.org/linux/man-pages/man4/random.4.html) 
 
 ## other alternative for seeding values
 - It can also be achieved by the use of the srand(time(0)) function but the same password is generated if our code is run multiple times in the same second.

 
