### Solution

Use the [Wiener's attack](https://en.wikipedia.org/wiki/Wiener's_attack) to solve.

The **wiener_variant() function** implements the Wiener's attack by finding the continued fraction expansion of "e/n", extracting the denominators, and checking each denominator for potential private exponents.

The **continued_fraction_periodic() function** from the sympy.ntheory module is used to find the continued fraction expansion of "e/n", and continued_fraction_convergents() is used to extract the denominators from the continued fraction. The **long_to_bytes() function** from the Crypto.Util.number module is used to convert the decrypted plaintext from an integer to bytes.

If a private exponent is found that yields a plaintext with the given prefix, the corresponding plaintext and private exponent are returned.

Finally, we found the private exponent and recovered flag.

![image](https://user-images.githubusercontent.com/126962960/233797870-e9d888b8-a0fa-465f-9670-4045fa0dff50.png)
