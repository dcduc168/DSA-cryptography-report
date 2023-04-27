### Solution

This challenge is about the Franklin-Reiter related-message attack on RSA. Let us get 2 ciphertexts that correspond to the same plaintext encrypted with the same modulus, but padded differently.

Let's call the plaintext (in this case, the flag) $m$, the modulus $N$, the public exponent $e$, the ciphertext $c1$ and $c2$, and the padding variables $a1,a2,b1,b2$, and where $ci ≡ (aim + bi)^e (mod\ N)$.
Then $m$ is the common root of these 2 polynomials:

$$p1(x) = (a1x + b1)^e - c1 (mod\ N)$$

$$p2(x) = (a2x + b2)^e - c2 (mod\ N)$$

If both polynomials have the root $m$, then they are both divisible by $(x−m)$. This means we can compute the polynomial greatest common divisor of $p1$ and $p2$. The resulting polynomial's constant term is thus our message. This is easy using Sage.

![image](https://user-images.githubusercontent.com/126962960/233844910-d640d2cc-bf01-41ae-982e-da5b029827ba.png)
