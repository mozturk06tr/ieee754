```
ieee754

Minimal IEEE-754 binary32 / binary64 decoder.
Single file. No dependencies. Exact bit exposure.

Layout

binary32:

31        23        0
[s][ exponent ][ fraction ]
 1      8 bits      23 bits


binary64:

63        52        0
[s][  exponent  ][ fraction ]
 1      11 bits      52 bits

Value

Normalized:

x = (-1)^s * 2^(e - bias) * (1 + f)


Subnormal:

x = (-1)^s * 2^(1 - bias) * f


bias = 127 (float)
bias = 1023 (double)

f = fraction / 2^p
p = 23 (float), 52 (double)

Precision

float:

epsilon = 2^-23
|delta| <= 2^-24


double:

epsilon = 2^-52
|delta| <= 2^-53


Floating-point model:

fl(a op b) = (a op b) * (1 + delta)
|delta| <= epsilon


Associativity and distributivity do not hold.

Special Values
e = 0,   f = 0   -> +/-0
e = max, f = 0   -> +/-inf
e = max, f != 0  -> NaN
e = 0,   f != 0  -> subnormal
```
