### Solution

Imports the RSA key from the file, extracts the modulus, and uses it to connect to the FactorDB to obtain the prime factors.

Once the factors are obtained, the code computes the private exponent using the inverse() method and constructs a new RSA key object. It then uses this key object to decrypt the ciphertext using the PKCS#1 OAEP padding scheme and prints the decrypted message to the console. The RSA encryption algorithm is based on the mathematical problem of factoring large integers, and RSA encryption involves the generation of a public-private key pair.

![image](https://user-images.githubusercontent.com/126962960/233799838-c5dc290f-c367-4ee8-ad60-82226899f8b0.png)
