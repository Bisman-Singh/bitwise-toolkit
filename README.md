# Bitwise Toolkit

An interactive command-line tool for exploring and performing bitwise operations, written in C. Useful for learning about binary representations and bit manipulation techniques.

## Features

- Set, clear, toggle, and check individual bits
- Count the number of set bits (popcount)
- Display numbers in binary with configurable bit width
- Circular bit rotation (left and right)
- XOR cipher for encrypting and decrypting strings
- Parity checking (even/odd)
- Power-of-two detection using bit tricks
- Bit reversal
- Next power of two calculation
- Before/after display in both decimal and binary for every operation

## Build

```
make
```

## Run

```
./bitwise-toolkit
```

## Usage Example

```
=== Bitwise Toolkit ===
1. Set/Clear/Toggle/Check bit
2. Count set bits
3. Display binary representation
4. Rotate bits
5. XOR cipher (encrypt/decrypt)
6. Parity check
7. Power of two check
8. Reverse bits
9. Exit
Choice: 1

Bit operations:
  1. Set bit
  2. Clear bit
  3. Toggle bit
  4. Check bit
Choice: 1
Enter number: 10
Enter bit position (0-31): 0

Before: 10 = 0000 0000 0000 1010
After set_bit(10, 0): 11 = 0000 0000 0000 1011

Choice: 7

Enter number: 16
Number: 16 = 0000 0000 0001 0000
16 IS a power of two.

Choice: 5

Enter string to encrypt: Hello World
Enter XOR key (0-255): 42

Original:  "Hello World"
Encrypted: 62 4F 46 46 45 0A 7D 45 58 46 4E
Decrypted: "Hello World"
```

## Clean

```
make clean
```
