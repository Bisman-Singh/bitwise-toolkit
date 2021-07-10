#ifndef BITOPS_H
#define BITOPS_H

#include <stdint.h>
#include <stddef.h>

uint32_t set_bit(uint32_t num, int pos);
uint32_t clear_bit(uint32_t num, int pos);
uint32_t toggle_bit(uint32_t num, int pos);
int check_bit(uint32_t num, int pos);
int count_set_bits(uint32_t num);
void print_binary(uint32_t num, int bits);
uint32_t rotate_left(uint32_t num, int positions, int bits);
uint32_t rotate_right(uint32_t num, int positions, int bits);
void xor_cipher(const uint8_t *input, uint8_t key, uint8_t *output, size_t len);
int check_parity(uint32_t num);
int is_power_of_two(uint32_t num);
void swap_without_temp(uint32_t *a, uint32_t *b);
uint32_t reverse_bits(uint32_t num, int bits);
uint32_t next_power_of_two(uint32_t num);

#endif /* BITOPS_H */
