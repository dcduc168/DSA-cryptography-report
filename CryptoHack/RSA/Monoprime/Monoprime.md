### Solution

RSA works by using the fact that $e ⋅ d ≡ 1 (\mod \phi{(n)}) $.

So that, $(m^e)^d ≡ m\mod n$

If n is a prime, we have that $\phi(n) = n - 1$; so we can easily compute d and find the flag like RSA Starter 5.

![image](https://user-images.githubusercontent.com/126962960/233791768-701c37d7-72b5-4fb0-a5e9-0b26947f14ad.png)
