### Solution

- The bit length of the message is calculated and used to determine the RSA modulus.
- The private key d is calculated using the RSA encryption exponent and the modulus.
- The message is padded with null bytes to match the length of the modulus.
- The message is encrypted using the private key and the modulus, and converted to a hexadecimal string.
- A JSON payload is created containing the encrypted message as a string.
- The payload is sent to the remote server as a vote.
- The server likely performs some computation on the encrypted vote and returns the result.

![image](https://user-images.githubusercontent.com/126962960/233843461-910a164e-eb26-4cda-bcc5-f357127bf622.png)
