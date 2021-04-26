# The design of the tool

__Version: 1.0__

The current design goal is to complete a tool with basic usable functions and adpot a method to test it.

## Character Set

The character set that we are going to use to create passwords is imporant. There are the sets we will use
in the tool.

| Character Set               | Members                    |
|-----------------------------|----------------------------|
| UPPERCASE ENGLISH ALPHABETS | ABCDEFGHIJKLMNOPQRSTUVWXYZ |
| LOWERCASE ENGLISH ALPHABETS | abcdefghijklmnopqrstuvwxyz |
| NUMBERS                     | 0123456789                 |
| SPECIAL SYMBOLS             | !@#$%^&*-_                 |

## Default behaviour

The tool with no options will print a random password of lenght _8_ to `stdout`.

Example:- 

```
$ passgen
WedaoR4n
```

In this use case, the tool will use UPPERCASE, LOWERCASE and NUMBERS character sets.

## Command line options

| OPTIONS | DESCRIPTION                                                                                                                                                                                                                                                                    |
|---------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -L      | Sets the length of the password<br><br>Usage: `passgen -L 20`<br>       Generates a random password with default character set of length 20                                                                                                                                    |
| -S      | Use special symbol character set as well<br><br>Usage: `passgen -S` <br><br>       Generates a random password with all character set of default length 8 <br>      <br>       `passgen -S -L 20`<br>        Generates a random password with all characters set of length 20  |
| -H      | Print the instructions on how to use this tool                                                                                                                                                                                                                                 |
| -V      | Prints the version of this tool                                                                                                                                                                                                                                                |

## Components

The project code will be divided up in components.

### Command line option parser

This component has the duty to read and parse the options that we will use to construct our generator.
Ideally, this could be a class that we can write, or simply implemented in `main.cpp`. We will decide later.

### Random Engine

This is the core component responsible for generating high quality pseudo-random numbers and thus we will use it to generate random strings.

To achive the maximum pseudo-randomness for the purpose of the tool, we will use `random` from C++ STL.
For reference see this, [https://www.cplusplus.com/reference/random/](https://www.cplusplus.com/reference/random/)

We will write classes that will encapsulate the use of `std::random`. This is common design used in projects.

These classes will have to be configurable by design. This means that the components of this class are modular. If in future we plan to extend the functionality of the tool, we can extend these classes without changing the old code as much as possible. We just add the new functionality to these classes.

#### Class RandomEngine
##### Constructors

- `RandomEngine()` - default constructor. 
- `RandomEngine(uint8)` - To set the generator for the specific length
- `RandomEngine(bool)` - To turn on symbol character set. Length remains default.
- `RandomEngine(uint8, bool)` - To set length and symbol character set.

#### Public functions

- `setLength(uint8)` - Set the length
- `setSymbolSet(bool)` - Turn on symbols
- `getString()` - Returns a random string with configured options
- `getLength()` - Return length of the generator
- `getSymbolSetStatus()` - Returns true if symbols are on

This design is subject to change and will change in future as the tool gets more sophisticated.