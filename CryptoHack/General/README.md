# GENERAL

## ENCODING

### ASCII

#### Solution

Use the chr() function to convert an ASCII ordinal number to a character

```python
nums = [99, 114, 121, 112, 116, 111, 123, 65, 83, 67, 73, 73, 95, 112, 114, 49, 110, 116, 52, 98, 108, 51, 125]
for _ in nums:
    print(chr(_), end='')
```

### HEX

#### Solution

Use the bytes.fromhex() function to convert hex to bytes

```python
hexa = bytes.fromhex("63727970746f7b596f755f77696c6c5f62655f776f726b696e675f776974685f6865785f737472696e67735f615f6c6f747d")
print(hexa)
```

### Base64

#### Solution

Use the bytes.fromhex() function to convert hex to bytes. After after importing the base64 module with import base64, you can use the base64.b64encode() function to encode bytes and base64_bytes.decode() function to decode bytes to ascii

```python
byte = bytes.fromhex("72bca9b68fc16ac7beeb8f849dca1d8a783e8acf9679bf9269f7bf")
import base64
base64_bytes = base64.b64encode(byte)
base64_mess = base64_bytes.decode('ascii')
print(base64_mess)
```

### Bytes and Big Integers

#### Solution

```python
from Crypto.Util.number import long_to_bytes
long_to_bytes(11515195063862318899931685488813747395775516287289682636499965282714637259206269).decode()
```

## XOR

### Xor Starter

#### Solution

Given the string label, XOR each character with the integer 13. Convert these integers back to a string

```python
data = "label"
flag = ''

for c in data:
    flag += chr(ord(c) ^ 13)

print('crypto{{{}}}'.format(flag))
```

### Xor Properties

#### Solution

Decode key from hex to bytes. Then, use xor() funtionc to xor k1, k2^k3, flag

```python
from pwn import xor
k1=bytes.fromhex('a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313')
k2_3=bytes.fromhex('c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1')
flag=bytes.fromhex('04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf')
print(xor(k1,k2_3,flag))
```

### Favourite byte

#### Solution

Decode the data, then xor with single byte in range (0,256), find the string with "crypto"

```python
from pwn import xor

given ="73626960647f6b206821204f21254f7d694f7624662065622127234f726927756d".decode("hex")

for i in range(0,256):
	flag =xor(given,i)
	substring = "crypto"
	if substring in flag:
		print("The flag is "+flag)
```

### You either know, XOR you don't

#### Solution

```python
encrypted_msg = "0e0b213f26041e480b26217f27342e175d0e070a3c5b103e2526217f27342e175d0e077e263451150104"
encrypted_msg = bytes.fromhex(encrypted_msg)

flag_format = b"crypto{"
key = [o1 ^ o2
       for (o1, o2) in zip(encrypted_msg, flag_format)] + [ord("y")]

flag = []
key_len = len(key)
for i in range(len(encrypted_msg)):
    flag.append(
        encrypted_msg[i] ^ key[i % key_len]
    )
flag = "".join(chr(o) for o in flag)

print("Flag:")
print(flag)
```

### Lemur XOR

#### Solution

We have 2 image named _lumur.png_ and _flag.png_. So we need to use a python library to extract the pixel values of each image into numpy arrays. Next we XOR the pixel values together. And finally, convert the XORed pixels to PIL image and export to a PNG file. Remember to change the directory of the terminal to the folder contain 2 above pictures before run.

```python
import numpy as np
from PIL import Image

img1 = Image.open('lemur.png')
img2 = Image.open('flag.png')

n1 = np.array(img1)*255
n2 = np.array(img2)*255

# Our images have a mode of RGB which is assumed to be an 8-bit int
n_image = np.bitwise_xor(n1, n2).astype(np.uint8)
# Convert to PIL image and save
Image.fromarray(n_image).save('n.png')
```

After run code we got this picture: https://ibb.co/SJNGwdp

## MATHEMATICS

### Greatest Common Divisor

#### Solution

Create gcd() function to calculate the greatest common divisor between a, b

```python
def gcd(a,b):
     if a<b:
          a,b = b,a
     while b!=0:
          a,b = b,a%b
     return a
print(gcd(66528,52920))
```

### Extended GCD

#### Solution

Create egcd() function to calculate the extended GCD between a, b

```python
def egcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q, r = b//a, b%a
        m, n = x-u*q, y-v*q
        b,a, x,y, u,v = a,r, u,v, m,n
    gcd = b
    return gcd, x, y

print egcd(26513,32321)
```

### Modular Arithmetic 1

#### Solution

The smaller of the two integers: $11 ≡ x \mod 6$ and $8146798528947 ≡ y \mod 17$

```python
print(min(11 % 6, 8146798528947 % 17))
```

### Modular Arithmetic 2

#### Solution

$$x^{p} \mod p = p $$

$$x^{p-1} \mod p = 1$$

$x = 273246787654$
$p = 65537$
Calculate $273246787654^{65536} \mod 65537 = x^{p-1} \mod p = 1$

```python
print(pow(273246787654,65536,65537))
```

### Modular Inverting

#### Solution

$a^{p-1} = 1 \mod p$
$a^{p-1} * a^{-1} = a^{-1} \mod p$
$a^{p-2} = a^{-1} \mod p$
The inverse element = $a^{-1} = a^{p-2}$ % p

```python
a = 3
p = 13
print(pow(a,p-2) % p)
```
