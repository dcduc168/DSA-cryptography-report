### Solution

Use [Factordb](http://factordb.com/), I saw that $N = p^2$

So from Euler's totient function we know when p is prime and k ≥ 1, then:

$\phi(p^k) = p^{k - 1} * (p - 1) = p^k * (1 - \frac{1}{p})$

In our case, $k = 2$, so $\phi(p^2) = p * (p - 1)$

Then, find d and decrypt the ciphertext like RSA Starter 5 to get the flag.

![image](https://user-images.githubusercontent.com/126962960/233792542-5577f1c3-a810-4f23-9cb0-2db9f7c606c5.png)
