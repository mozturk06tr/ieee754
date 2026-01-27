#include <stdio.h>
#include <stdint.h>
#include <string.h>

static void print_bits_u32(uint32_t x) {
    for (int i = 31; i >= 0; --i) {
        putchar((x >> i) & 1 ? '1' : '0');
        if (i == 31 || i == 23) putchar(' ');
    }
}

static void print_bits_u64(uint64_t x) {
    for (int i = 63; i >= 0; --i) {
        putchar((x >> i) & 1 ? '1' : '0');
        if (i == 63 || i == 52) putchar(' ');
    }
}

static uint32_t float_to_u32(float f) {
    uint32_t u;
    memcpy(&u, &f, sizeof u);
    return u;
}

static uint64_t double_to_u64(double d) {
    uint64_t u;
    memcpy(&u, &d, sizeof u);
    return u;
}

static void decode_float(float f) {
    uint32_t u = float_to_u32(f);
    uint32_t sign = (u >> 31) & 1u;
    uint32_t exp  = (u >> 23) & 0xFFu;      
    uint32_t frac = u & 0x7FFFFFu;
    
    printf("float = %.9g\n", f);
    printf("bits  = ");
    print_bits_u32(u);
    putchar('\n');
    printf("sign  = %u\n", sign);
    printf("exp   = 0x%02X (%u)\n", exp, exp);
    printf("frac  = 0x%06X (%u)\n", frac, frac);
}

static void decode_double(double d) {
    uint64_t u = double_to_u64(d);
    uint64_t sign = (u >> 63) & 1ull;
    uint64_t exp  = (u >> 52) & 0x7FFull;
    uint64_t frac = u & 0xFFFFFFFFFFFFFull;
    
    printf("double = %.17g\n", d);
    printf("bits   = ");
    print_bits_u64(u);
    putchar('\n');
    printf("sign   = %llu\n", (unsigned long long)sign);
    printf("exp    = 0x%03llX (%llu)\n", (unsigned long long)exp, (unsigned long long)exp);
    printf("frac   = 0x%013llX\n", (unsigned long long)frac);
}

int main(void) {
    decode_float(5.0f);
    puts("----");
    decode_float(0.1f);
    puts("----");
    decode_double(0.1);
    puts("----");
    decode_float(-0.0f);
    return 0;

}
