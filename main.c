#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitops.h"

#define DISPLAY_BITS 16

static void flush_input(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { /* skip */ }
}

static void menu_bit_ops(void)
{
    uint32_t num;
    int pos;
    int op;

    printf("\nBit operations:\n");
    printf("  1. Set bit\n");
    printf("  2. Clear bit\n");
    printf("  3. Toggle bit\n");
    printf("  4. Check bit\n");
    printf("Choice: ");
    if (scanf("%d", &op) != 1) { flush_input(); return; }

    printf("Enter number: ");
    if (scanf("%u", &num) != 1) { flush_input(); return; }

    printf("Enter bit position (0-31): ");
    if (scanf("%d", &pos) != 1 || pos < 0 || pos > 31) {
        printf("Invalid position.\n");
        flush_input();
        return;
    }

    printf("\nBefore: %u = ", num);
    print_binary(num, DISPLAY_BITS);
    printf("\n");

    uint32_t result;
    switch (op) {
    case 1:
        result = set_bit(num, pos);
        printf("After set_bit(%u, %d): %u = ", num, pos, result);
        break;
    case 2:
        result = clear_bit(num, pos);
        printf("After clear_bit(%u, %d): %u = ", num, pos, result);
        break;
    case 3:
        result = toggle_bit(num, pos);
        printf("After toggle_bit(%u, %d): %u = ", num, pos, result);
        break;
    case 4:
        printf("Bit %d is %s\n", pos, check_bit(num, pos) ? "SET" : "NOT SET");
        return;
    default:
        printf("Invalid choice.\n");
        return;
    }
    print_binary(result, DISPLAY_BITS);
    printf("\n");
}

static void menu_count_bits(void)
{
    uint32_t num;
    printf("\nEnter number: ");
    if (scanf("%u", &num) != 1) { flush_input(); return; }

    printf("Number: %u = ", num);
    print_binary(num, DISPLAY_BITS);
    printf("\n");
    printf("Set bits: %d\n", count_set_bits(num));
}

static void menu_display_binary(void)
{
    uint32_t num;
    int bits;
    printf("\nEnter number: ");
    if (scanf("%u", &num) != 1) { flush_input(); return; }

    printf("Enter number of bits to display (1-32): ");
    if (scanf("%d", &bits) != 1 || bits < 1 || bits > 32) {
        printf("Invalid bit count.\n");
        flush_input();
        return;
    }

    printf("%u in %d-bit binary: ", num, bits);
    print_binary(num, bits);
    printf("\n");
}

static void menu_rotate(void)
{
    uint32_t num;
    int positions, bits, dir;

    printf("\nEnter number: ");
    if (scanf("%u", &num) != 1) { flush_input(); return; }

    printf("Bit width (e.g. 8, 16, 32): ");
    if (scanf("%d", &bits) != 1 || bits < 1 || bits > 32) {
        printf("Invalid bit width.\n");
        flush_input();
        return;
    }

    printf("Rotate positions: ");
    if (scanf("%d", &positions) != 1) { flush_input(); return; }

    printf("Direction (1=left, 2=right): ");
    if (scanf("%d", &dir) != 1) { flush_input(); return; }

    printf("\nBefore: %u = ", num);
    print_binary(num, bits);
    printf("\n");

    uint32_t result;
    if (dir == 1) {
        result = rotate_left(num, positions, bits);
        printf("Rotate left %d: %u = ", positions, result);
    } else {
        result = rotate_right(num, positions, bits);
        printf("Rotate right %d: %u = ", positions, result);
    }
    print_binary(result, bits);
    printf("\n");
}

static void menu_xor_cipher(void)
{
    char input[256];
    uint8_t encrypted[256];
    uint8_t decrypted[256];
    unsigned int key;

    flush_input();
    printf("\nEnter string to encrypt: ");
    if (!fgets(input, (int)sizeof(input), stdin)) return;

    /* Remove trailing newline */
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[--len] = '\0';
    }

    printf("Enter XOR key (0-255): ");
    if (scanf("%u", &key) != 1 || key > 255) {
        printf("Invalid key.\n");
        flush_input();
        return;
    }

    xor_cipher((const uint8_t *)input, (uint8_t)key, encrypted, len);

    printf("\nOriginal:  \"%s\"\n", input);
    printf("Encrypted: ");
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", encrypted[i]);
    }
    printf("\n");

    /* Decrypt to verify */
    xor_cipher(encrypted, (uint8_t)key, decrypted, len);
    decrypted[len] = '\0';
    printf("Decrypted: \"%s\"\n", (char *)decrypted);
}

static void menu_parity(void)
{
    uint32_t num;
    printf("\nEnter number: ");
    if (scanf("%u", &num) != 1) { flush_input(); return; }

    printf("Number: %u = ", num);
    print_binary(num, DISPLAY_BITS);
    printf("\n");
    printf("Set bits: %d\n", count_set_bits(num));
    printf("Parity: %s\n", check_parity(num) ? "ODD" : "EVEN");
}

static void menu_power_of_two(void)
{
    uint32_t num;
    printf("\nEnter number: ");
    if (scanf("%u", &num) != 1) { flush_input(); return; }

    printf("Number: %u = ", num);
    print_binary(num, DISPLAY_BITS);
    printf("\n");

    if (is_power_of_two(num)) {
        printf("%u IS a power of two.\n", num);
    } else {
        printf("%u is NOT a power of two.\n", num);
        printf("Next power of two: %u\n", next_power_of_two(num));
    }
}

static void menu_reverse_bits(void)
{
    uint32_t num;
    int bits;
    printf("\nEnter number: ");
    if (scanf("%u", &num) != 1) { flush_input(); return; }

    printf("Bit width (e.g. 8, 16, 32): ");
    if (scanf("%d", &bits) != 1 || bits < 1 || bits > 32) {
        printf("Invalid bit width.\n");
        flush_input();
        return;
    }

    printf("\nBefore: %u = ", num);
    print_binary(num, bits);
    printf("\n");

    uint32_t result = reverse_bits(num, bits);
    printf("After:  %u = ", result);
    print_binary(result, bits);
    printf("\n");
}

static void print_menu(void)
{
    printf("\n=== Bitwise Toolkit ===\n");
    printf("1. Set/Clear/Toggle/Check bit\n");
    printf("2. Count set bits\n");
    printf("3. Display binary representation\n");
    printf("4. Rotate bits\n");
    printf("5. XOR cipher (encrypt/decrypt)\n");
    printf("6. Parity check\n");
    printf("7. Power of two check\n");
    printf("8. Reverse bits\n");
    printf("9. Exit\n");
    printf("Choice: ");
}

int main(void)
{
    int choice;

    printf("Bitwise Toolkit\n");
    printf("A collection of bitwise operation utilities.\n");

    for (;;) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            flush_input();
            printf("Invalid input. Enter a number 1-9.\n");
            continue;
        }

        switch (choice) {
        case 1: menu_bit_ops();       break;
        case 2: menu_count_bits();    break;
        case 3: menu_display_binary(); break;
        case 4: menu_rotate();        break;
        case 5: menu_xor_cipher();    break;
        case 6: menu_parity();        break;
        case 7: menu_power_of_two();  break;
        case 8: menu_reverse_bits();  break;
        case 9:
            printf("Goodbye.\n");
            return 0;
        default:
            printf("Invalid choice. Enter 1-9.\n");
            break;
        }
    }
}
