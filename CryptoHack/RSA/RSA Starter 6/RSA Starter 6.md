### Solution

I got file [private.key](https://cryptohack.org/static/challenges/private_0a1880d1fffce9403686130a1f932b10.key) include $N$ and $d$ (private key)

The message is defined as a string and its SHA-256 hash is calculated using the sha256 function.

The bytes_to_long() function is used to convert the hashed message sh from bytes to an integer, which can then be used as the base in the modular exponentiation operation.

Finally, I decrypted message.

![image](https://user-images.githubusercontent.com/126962960/233789801-c1a67b87-bdda-47dd-bb44-4ef61796da7b.png)
