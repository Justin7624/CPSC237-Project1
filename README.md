# CPSC237-Project1
# Word Processing Program

## Overview
This project implements a **word occurrence processor** that reads words from a file, tracks their occurrences, and provides multiple methods for displaying and analyzing word data. The program supports both **batch** and **interactive** modes, allowing users to process files efficiently.

## Features
- Reads words from a text file and counts occurrences.
- Provides **multiple processing methods**, including:
  - Parallel iterative
  - Parallel recursive
  - Object array iterative
  - Object array recursive
  - Object array pointer
  - STL vector with a for loop
  - STL vector with an iterator
- Supports both **batch mode** (processing files via command-line arguments) and **interactive mode** (user input).

## Usage
### Compilation
To compile the project, use the provided **Makefile**:
```bash
make
```
This will generate an executable named `wordprocessor`.

### Running the Program
Run the program with the following command-line arguments:
```bash
./wordprocessor <filename>
```
#### Example:
```bash
./wordprocessor test1.txt
```
This processes the words in `test1.txt` and provides occurrence counts.

If no filename is provided, the program will enter **interactive mode**, prompting the user for input.

### Cleaning Up
To remove compiled files:
```bash
make clean
```

## Implementation Details
### Steps Performed:
1. **Read words from a file** into a vector of `WordData` objects.
2. **Process words** using different methods:
   - Parallel and recursive processing.
   - Object-based and STL-based approaches.
3. **Display results** based on user selection.
4. **Handle input errors** gracefully.

### Command-line Arguments:
- `<filename>`: Specify the file containing words to process.
- If no file is specified, the program will enter interactive mode.

## Code Structure
- `main.cpp` - Main program handling input, processing, and output.
- `cmdArgs.cpp` - Handles command-line argument parsing.
- `WordData.cpp` - Implementation of the `WordData` class for tracking word occurrences.
- `WordData.h` - Header file for the `WordData` class.
- `Makefile` - Compilation and cleanup rules.
- `MenuChoices.txt` - Lists available processing methods.

## Error Handling
- Ensures **valid command-line arguments**.
- Handles **file opening errors**.
- Detects **invalid user choices in interactive mode**.

## Author
- **Justin Allen**
