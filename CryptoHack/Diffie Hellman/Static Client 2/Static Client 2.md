### Solution

Bob has to establish a shared secret with Alice using Diffie-Hellman key exchange. However, Bob is still insisting on using the **p and g** values provided by his partner.

To solve this problem, we need to modify the provided **p value** in such a way that it becomes smooth, i.e., it has only **small prime factors**.

To find **a smooth p value**, we can use the [Pohlig-Hellman](https://en.wikipedia.org/wiki/Pohlig%E2%80%93Hellman_algorithm) algorithm, which factorizes the original **p value** and then replaces the factors that are **not small enough with smaller primes**.

Once we have the smooth **p value**, we can send it to Bob along with the original **g and A values**. Bob will then send us his **public key B**, which we can use to calculate the discrete logarithm **b**. Finally, we can calculate the shared secret and use it to decrypt the flag.

![image](https://user-images.githubusercontent.com/126962960/233817302-291592c3-1c8e-4a10-b483-4e8f94c560fc.png)
