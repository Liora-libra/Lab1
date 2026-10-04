/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return 1 << 31;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
	return ~(x & y) & ~(~x & ~y);
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  int mask = x >> 31;
return mask & (~x + 1);
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  int s = src << 3;
int d = dst << 3;
int b = (x >> s) & 0xFF;
return (x & ~(0xFF << d)) | (b << d);
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  int mask = ~(((1 << 31) >> n) << 1);
return (x >> n) & mask;
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
  int m = 0x0F;
m = m | (m << 8);
m = m | (m << 16);
return ((x & m) << 4) | ((x >> 4) & m);
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
  int z = ~x;
int first = z & (~z + 1);
int z2 = z ^ first;
return z2 & (~z2 + 1);
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
  x ^= x >> 16;
x ^= x >> 8;
x ^= x >> 4;
x ^= x >> 2;
x ^= x >> 1;
return !(x & 1);
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
 int nm = n & 31;
int r = x >> nm;
int mask = ~(((1 << 31) >> nm) << 1);
r = r & mask;
int l = x << ((32 + (~nm + 1)) & 31);
return r | l;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
 int m = 1 << n;
int half = m >> 1;
int bias = half + (~0) + ((x >> n) & 1);
return (x + bias) & ~(m + (~0));
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  int sx = x >> 31;
int sy = y >> 31;
int sign_diff = sx ^ sy;
int same_sub = x + (~y + 1);
int same_gt = !((same_sub >> 31) | !same_sub);
int diff_gt = !sx;
int x_gt = (sign_diff & diff_gt) | (~sign_diff & same_gt);
int avg = (x & y) + ((x ^ y) >> 1);
int odd = (x ^ y) & 1;
return avg + (x_gt & odd);
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
  int sx = x >> 31;
int sa = a >> 31;
int sb = b >> 31;
int sd_xa = sx ^ sa;
int sub_xa = x + (~a + 1);
int sn_xa = sub_xa >> 31;
int x_ge_a = !((sd_xa & sx) | (~sd_xa & sn_xa));
int sd_bx = sb ^ sx;
int sub_bx = b + (~x + 1);
int sn_bx = sub_bx >> 31;
int b_ge_x = !((sd_bx & sb) | (~sd_bx & sn_bx));
int in_ab = x_ge_a & b_ge_x;
int sd_xb = sx ^ sb;
int sub_xb = x + (~b + 1);
int sn_xb = sub_xb >> 31;
int x_ge_b = !((sd_xb & sx) | (~sd_xb & sn_xb));
int sd_ax = sa ^ sx;
int sub_ax = a + (~x + 1);
int sn_ax = sub_ax >> 31;
int a_ge_x = !((sd_ax & sa) | (~sd_ax & sn_ax));
int in_ba = x_ge_b & a_ge_x;
return in_ab | in_ba;
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
int t = x << 2;
int res = t + x;
int shift_diff = (t >> 2) ^ x;
int shift_ov = !shift_diff + (~0);
int add_ov = ((x ^ res) & (t ^ res)) >> 31;
int overflow = shift_ov | add_ov;
int sign = x >> 31;
int int_min = 1 << 31;
int int_max = ~int_min;
int sat = (sign & int_min) | (~sign & int_max);
return (overflow & sat) | (~overflow & res);
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
  int s2 = x + y;
int ov2_all = (~(x ^ y) & (x ^ s2)) >> 31;
int sign2 = x >> 31;
int ov2_pos = ov2_all & ~sign2;
int ov2_neg = ov2_all & sign2;
int ov2 = (ov2_pos & 1) + (ov2_neg & (~0));

int s3 = s2 + z;
int ov3_all = (~(s2 ^ z) & (s2 ^ s3)) >> 31;
int sign3 = s2 >> 31;
int ov3_pos = ov3_all & ~sign3;
int ov3_neg = ov3_all & sign3;
int ov3 = (ov3_pos & 1) + (ov3_neg & (~0));

int delta = ov2 + ov3;
int pos = (!(delta >> 31)) & !!delta;
int neg = (delta >> 31) & 1;
return pos + (~neg + 1);
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
    unsigned s = uf >> 31;
    unsigned e = (uf >> 23) & 0xFF;
    unsigned f = uf & 0x7FFFFF;
    unsigned m;
    unsigned new_e;
    unsigned round_bit;
    if (e == 255) return uf;
    if (e == 0) {
        m = f;
    } else {
        m = f | (1u << 23);
    }
    m *= 3;
    round_bit = m & 1u;
    m >>= 1;
    if (round_bit && (m & 1u)) {
        m++;
    }
    if (e == 0) {
        if (m >= (1u << 23)) {
            new_e = 1;
            f = m & 0x7FFFFF;
        } else {
            new_e = 0;
            f = m;
        }
    } else {
        if (m >= (1u << 24)) {
            unsigned drop = m & 1u;
            m >>= 1;
            if (drop && (m & 1u)) {
                m++;
            }
            new_e = e + 1;
            f = m & 0x7FFFFF;
        } else {
            new_e = e;
            f = m & 0x7FFFFF;
        }
    }
    if (new_e >= 255) {
        return (s << 31) | (255u << 23);
    }

    return (s << 31) | (new_e << 23) | f;
}

// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
    unsigned s = uf >> 31;
    int e_field = (uf >> 23) & 0xFF;
    unsigned f = uf & 0x7FFFFF;
    unsigned m, int_part, frac, half;
    int exp, lead, new_exp;
    unsigned tmp, new_f;
    if (e_field == 255) return uf;
    exp = e_field - 127;
    if (exp >= 23) return uf;
    if (exp < -1) {
        return s << 31;
    }
    m = f | (1u << 23);
    if (exp >= 0) {
        int shift = 23 - exp;
        int_part = m >> shift;
        frac = m & ((1u << shift) - 1);
        half = 1u << (shift - 1);
    } else {
        int_part = 0;
        frac = m;
        half = 1u << 23;
    }
    if (frac > half) {
        int_part++;
    } else if (frac == half) {
        if (int_part & 1) {
            int_part++;
        }
    }
    if (int_part == 0) {
        return s << 31;
    }
    lead = 0;
    tmp = int_part;
    while (tmp >>= 1) lead++;
    new_exp = lead;
    new_f = (int_part << (23 - new_exp)) & 0x7FFFFF;
    if (new_exp >= 128) {
        return (s << 31) | (255u << 23);
    }
    return (s << 31) | ((new_exp + 127) << 23) | new_f;
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  if (x == 0) return 0;
unsigned s = 0;
unsigned val = x;
if (x < 0) {
    s = 1;
    val = ~x + 1;
}
int e = 31;
while (e >= 0 && !(val & (1u << e))) {
    e--;
}
int shift = e - 23;
unsigned f;
if (shift > 0) {
    unsigned mask = (1u << shift) - 1;
    unsigned frac = val & mask;
    f = (val >> shift) & 0x7FFFFF;
    unsigned half = 1u << (shift - 1);
    if (frac > half) {
        f++;
    } else if (frac == half) {
        if (f & 1) f++;
    }
    if (f & (1u << 23)) {
        f = 0;
        e++;
    }
} else {
    f = (val << (-shift)) & 0x7FFFFF;
}
return (s << 31) | ((e + 127) << 23) | f;
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
  int m1 = 0x55;
m1 = m1 | (m1 << 8);
m1 = m1 | (m1 << 16);
int m2 = 0x33;
m2 = m2 | (m2 << 8);
m2 = m2 | (m2 << 16);
int m4 = 0x0F;
m4 = m4 | (m4 << 8);
m4 = m4 | (m4 << 16);
int m8 = 0xFF;
m8 = m8 | (m8 << 16);
int m16 = 0xFF;
m16 = m16 | (m16 << 8);
x = (x & m1) + ((x >> 1) & m1);
x = (x & m2) + ((x >> 2) & m2);
x = (x & m4) + ((x >> 4) & m4);
x = (x & m8) + ((x >> 8) & m8);
x = (x & m16) + ((x >> 16) & m16);
return x;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x)
{
int m8 = 0xFF;
m8 = m8 | (m8 << 16);
int m4 = m8 ^ (m8 << 4);
int m2 = m4 ^ (m4 << 2);
int m1 = m2 ^ (m2 << 1);
int m16 = 0xff;
m16 = m16 | (m16 << 8);

x = ((x >> 16) & m16) | (x << 16);
x = ((x >> 8) & m8) | ((x & m8) << 8);
x = ((x >> 4) & m4) | ((x & m4) << 4);
x = ((x >> 2) & m2) | ((x & m2) << 2);
x = ((x >> 1) & m1) | ((x & m1) << 1);
return x;
}
