# Monty Project

This is the Monty project, an interpreter for the Monty programming language. The Monty language is a stack-based language similar to Python bytecode. This project aims to provide an interpreter that can execute Monty programs and perform various operations on a stack data structure.

## Getting Started

To get started with the Monty project, follow these steps:

1. Clone the repository: `git clone https://github.com/abdallahfarag72/monty`
2. Compile the Monty interpreter: `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`
3. Run a Monty program: `./monty <program_file>`

## Monty Language

The Monty language uses a stack data structure and consists of a set of instructions that operate on the stack. Instructions include pushing an element onto the stack, popping an element from the stack, performing arithmetic operations, manipulating the stack itself, and more. Refer to the Monty language specification for a detailed list of instructions.

## Usage

To execute a Monty program, use the following command:

```
./monty <program_file>
```

Replace `<program_file>` with the path to your Monty program file. The interpreter will read the program file, parse the instructions, and execute them accordingly.

## Examples

Here's an example of a Monty program that adds two numbers:

```
push 1
push 2
add
pall
```

Running the above program with the Monty interpreter will produce the following output:

```
3
```

