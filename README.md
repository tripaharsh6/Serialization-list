# Serialization of Doubly Linked List with Random Pointer

This program reads a description of a doubly linked list from `inlet.in`, constructs the list in memory, and serializes it into a binary file `outlet.out`.

## Input Format

Each line of `inlet.in`:

```
<data>;<rand_index>
```

Example:

```
apple;2
banana;-1
carrot;1
```

## Meaning

* `data` → string stored in node
* `rand_index` → index of node pointed by random pointer
* `-1` → null pointer

## Build

Compile the program:

```
g++ main.cpp -o program
```

## Run

```
./program
```

Output will be written to `outlet.out`.
