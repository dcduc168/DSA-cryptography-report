### Solution

In file Output.txt: my private key, friend's public keys, encrypt flag.

Call $k1,k2,k3,k4,k5$ is the keys of the friends. If we encode the flag as the integer m, we have that the ciphertext is $m^{k1 * k2 * k3 * k4 * k5}(mod\ N)$.

Inverse to find the key, pow to find the ciphertext and long_to_bytes to get the flag.

![image](https://user-images.githubusercontent.com/126962960/233797109-30a2f348-e981-4e3c-97aa-f0bbb9e95989.png)
