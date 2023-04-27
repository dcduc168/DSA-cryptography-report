### Solution

The main idea of this code is to demonstrate a variant of the Wiener's attack on RSA, which is used to break RSA when the private exponent "d" is small. The code constructs a plaintext "B", creates a polynomial equation, and solves it using the small_roots() method. The roots are converted into strings that match the format of the original plaintext message "B", and if any valid roots are found, they are printed out as potential solutions. The code attempts to recover the plaintext "B" by solving the polynomial equation, but this attack only works if the private exponent "d" is small, which is not necessarily the case in real-world RSA implementations.

![image](https://user-images.githubusercontent.com/126962960/233843067-6c94b0a0-8ec6-498b-9e5a-e49e2bb6e7d0.png)
