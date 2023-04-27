### Solution

We have public key (N, e) and ciphertext c.

First, I used [factordb](http://factordb.com/) to find the factors of $N$. I got $q$ and $p$.

Then, find $\phi = (p - 1) * (q - 1)$ and the private key (d) = $inverse(e, \phi)$

Finally, decrypt the ciphertext c by solving $c^{d} \mod N$

![image](https://user-images.githubusercontent.com/126962960/233789198-0b254faf-596a-47a4-9a12-297b4704d98d.png)
