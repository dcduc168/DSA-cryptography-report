### Solution

Alice generates a random secret a and sends $A = g^a \mod p$ to Bob, while Bob generates a random secret $b$ and sends $B = g^b \mod p$ to Alice.

Using this information, both parties can calculate a shared secret key $s$ as $s = A^b \mod p = B^a \mod p$.

In the given code, the values of $p, g, A,$ and $B$ are fixed, and the secret key is calculated using **shared_secret** = $A \oplus b$, where $b$ is computed as $B \oplus g$. The shared secret key is then used to decrypt the ciphertext using AES CBC mode with the given iv value.

``^`` symbol is $XOR$ not exponent in Python

The decrypted plaintext is the flag.

![image](https://user-images.githubusercontent.com/126962960/233817775-1619e21d-fb4b-4642-b719-b238912a4bc3.png)
