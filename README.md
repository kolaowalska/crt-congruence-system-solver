This short program implements a solver for modular arithmetic problems with the use of the Chinese Remainder Theorem and the Extended Euclidean Algorithm to compute the smallest non-negative solution to a congruence system. The program takes two sets of numbers - remainders from the system of congruences and moduli for each congruence - and computes the smallest non-negative integer $x$ that satisfies all congruences modulo the product of the moduli. It also ensures that the modular inverse exists (i.e., $a$ and $n$ are coprime) before performing computations.

This is done with the help of the following functions:
- `extendedGCD(a, b)`: computes the extended Euclidean algorithm and returns a structure with the GCD of $a$ and $b$, as well as coefficients that satisfy Bézout's identity $ax + by = \text{GCD}(a, b)$
- `inverse(a, n)`: computes the modular inverse of $a$ modulo $n$ using the extended GCD algorithm
- `crt(a<>, n<>, k)`: solves a system of congruences using the CRT by calculating the smallest non-negative solution to the system of equations given in vectors `a` and `n` for $k$ equations

Example input:
```
5
17 15 7 5 45
13111 225 13 19 9999991
```
Expected output:
```
result: 1707491663256165
```

All arithmetic has been simplified to assume values within the range of standard C++ `long long` but can be easily modified to handle larger integers using the GMP Arithmetic Library.
