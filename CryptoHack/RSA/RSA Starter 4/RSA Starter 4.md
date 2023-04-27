### Solution

Given the two primes: p, q

and the exponent: e

To find the secret key, find the totient of N: $\phi = (p - 1) * (q - 1)$. Then find the inverse of the exponent e modulo the totient of N. Finally, we find the key.

private key d = $e^{-1} \mod \phi$

![image](https://user-images.githubusercontent.com/126962960/233788400-bede1fa4-359a-4380-a631-efdadb8a4161.png)
