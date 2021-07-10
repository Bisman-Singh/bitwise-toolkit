#include <stdio.h>
#include "bitops.h"

uint32_t set_bit(uint32_t num, int pos)
{
    return num | ((uint32_t)1 << pos);
}

uint32_t clear_bit(uint32_t num, int pos)
{
    return num & ~((uint32_t)1 << pos);
}

uint32_t toggle_bit(uint32_t num, int pos)
{
    return num ^ ((uint32_t)1 << pos);
}

int check_bit(uint32_t num, int pos)
{
    return (num >> pos) & 1;
}

int count_set_bits(uint32_t num)
{
    int count = 0;
    while (num) {
        count += (int)(num & 1);
        num >>= 1;
    }
    return count;
}

void print_binary(uint32_t num, int bits)
{
    for (int i = bits - 1; i >= 0; i--) {
        putchar((num >> i) & 1 ? '1' : '0');
        if (i > 0 && i % 4 == 0) {
            putchar(' ');
        }
    }
}

uint32_t rotate_left(uint32_t num, int positions, int bits)
{
    uint32_t mask = ((uint32_t)1 << bits) - 1;
    num &= mask;
    positions %= bits;
    return ((num << positions) | (num >> (bits - positions))) & mask;
}

uint32_t rotate_right(uint32_t num, int positions, int bits)
{
    uint32_t mask = ((uint32_t)1 << bits) - 1;
    num &= mask;
    positions %= bits;
    return ((num >> positions) | (num << (bits - positions))) & mask;
}

void xor_cipher(const uint8_t *input, uint8_t key, uint8_t *output, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }
}

int check_parity(uint32_t num)
{
    /* Returns 0 for even parity (even number of 1-bits), 1 for odd */
    int parity = 0;
    while (num) {
        parity ^= 1;
        num &= (num - 1);
    }
    return parity;
}

int is_power_of_two(uint32_t num)
{
    return num != 0 && (num & (num - 1)) == 0;
}

void swap_without_temp(uint32_t *a, uint32_t *b)
{
    if (a == b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

uint32_t reverse_bits(uint32_t num, int bits)
{
    uint32_t result = 0;
    for (int i = 0; i < bits; i++) {
        result <<= 1;
        result |= (num & 1);
        num >>= 1;
    }
    return result;
}

uint32_t next_power_of_two(uint32_t num)
{
    if (num == 0) return 1;
    if (is_power_of_two(num)) return num;

    num--;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    num++;

    return num;
}
