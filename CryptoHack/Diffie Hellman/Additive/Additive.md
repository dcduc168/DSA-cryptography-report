### Solution

Here are the steps of Alice and Bob in performing the Diffie-Hellman Key Exchange (DHKE) in a multiplicative group:

  1.  Alice and Bob agree on a large prime number p and a generator g of the multiplicative group.

  2.  Alice chooses a secret integer a and computes $A = g^a \mod p$. She sends A to Bob.

  3.  Bob chooses a secret integer b and computes $B = g^b \mod p$. He sends B to Alice.

  4.  Alice computes the shared secret $S = B^a \mod p = (g^b)^a \mod p$.

  5.  Bob computes the shared secret $S = A^b \mod p = (g^a)^b \mod p$.

  6.  Alice and Bob now share the secret S, which they can use as the key for a symmetric encryption algorithm to communicate securely over an insecure channel.

In an additive group, the steps are the same, but the group operation is addition rather than multiplication, and the secret exponents a and b are added rather than multiplied. However, as explained earlier, this would break the security of the protocol, as the discrete logarithm problem is easy in an additive group.

![image](https://user-images.githubusercontent.com/126962960/233817030-4c9b62df-a0c6-4b28-aa2f-ec08013e9f6d.png)
