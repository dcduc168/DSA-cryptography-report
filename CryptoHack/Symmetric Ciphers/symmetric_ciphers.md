# SYMMETRIC CRYPTOGRAPHY

## Keyed Permutations

### Solution

**FLAG: crypto{bijection}**

## Resisting Bruteforce

### Solution

**FLAG: crypto{Biclique}**

## Structure of AES

### Solution

To turn the matrix back into bytes, converts a matrix into a array. Then, convert each integer to a single byte and concatenate the bytes into a single byte string.Finally, we find the flag.

```python
def bytes2matrix(text):
    """ Converts a 16-byte array into a 4x4 matrix.  """
    return [list(text[i:i+4]) for i in range(0, len(text), 4)]

def matrix2bytes(matrix):
    """ Converts a 4x4 matrix into a 16-byte array.  """
    # Flatten the matrix into a 1D list of integers
    flat_list = [item for sublist in matrix for item in sublist]

    # Convert each integer to a single byte
    bytes_list = [bytes([i]) for i in flat_list]

    # Concatenate the bytes into a single byte string
    byte_string = b''.join(bytes_list)

    return byte_string

matrix = [
    [99, 114, 121, 112],
    [116, 111, 123, 105],
    [110, 109, 97, 116],
    [114, 105, 120, 125],
]

print(matrix2bytes(matrix))
```

## Round Keys

### Solution

we are trying to recover plaintext which has been XOR'd with 11 different keys, and heavily jumbled between each XOR operation with a series of substitution and transposition ciphers. Therefore, complete the add_roung_key function.
First, turn each matrix (state, round_key) into 1D list of integers. Then, xor the correspoding intergers and add them to a list. Finally, turn the list of integer into byte to get the flag

```python
state = [
    [206, 243, 61, 34],
    [171, 11, 93, 31],
    [16, 200, 91, 108],
    [150, 3, 194, 51],
]

round_key = [
    [173, 129, 68, 82],
    [223, 100, 38, 109],
    [32, 189, 53, 8],
    [253, 48, 187, 78],
]

def list2bytes(list):

    # Convert each integer to a single byte
    bytes_list = [bytes([i]) for i in list]

    # Concatenate the bytes into a single byte string
    byte_string = b''.join(bytes_list)

    return byte_string

key = []
def add_round_key(s, k):
    s1 = [item for sublist in s for item in sublist]
    k1 = [item for sublist in k for item in sublist]
    for i in range(len(s1)):
        key.append(s1[i] ^ k1[i])
    return list2bytes(key)

print(add_round_key(state, round_key))
```

## Confusion through Substitution

### Solution

Implement sub_bytes function, send the state matrix through the inverse S-box and then convert it to bytes to get the flag.

```python
s_box = (
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16,
)

inv_s_box = (
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
    0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
    0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
    0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
    0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
    0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
    0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
    0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
    0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
    0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
    0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
    0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
    0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
    0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D,
)

state = [
    [251, 64, 182, 81],
    [146, 168, 33, 80],
    [199, 159, 195, 24],
    [64, 80, 182, 255],
]

def sub_bytes(s, sbox=s_box):
    s = [item for sublist in s for item in sublist]
    for i in range (len(s)):
        s[i] = sbox[s[i]]
    return bytes(s).decode()
print(sub_bytes(state, inv_s_box))
```

## Diffusion through Permutation

### Solution

The flag is encrypted by shift_row function and then mix_column function.
We've provided code to perform MixColumns and the forward ShiftRows operation. Open file diffusion.py. After implementing inv_shift_rows, take the state, run inv_mix_columns on it, then inv_shift_rows, convert to bytes and we get the flag.

```python
def shift_rows(s):
    s[0][1], s[1][1], s[2][1], s[3][1] = s[1][1], s[2][1], s[3][1], s[0][1]
    s[0][2], s[1][2], s[2][2], s[3][2] = s[2][2], s[3][2], s[0][2], s[1][2]
    s[0][3], s[1][3], s[2][3], s[3][3] = s[3][3], s[0][3], s[1][3], s[2][3]


def inv_shift_rows(s):
    s[1][1], s[2][1], s[3][1], s[0][1] = s[0][1], s[1][1], s[2][1], s[3][1]
    s[2][2], s[3][2], s[0][2], s[1][2] = s[0][2], s[1][2], s[2][2], s[3][2]
    s[3][3], s[0][3], s[1][3], s[2][3] = s[0][3], s[1][3], s[2][3], s[3][3]

# learned from http://cs.ucsb.edu/~koc/cs178/projects/JT/aes.c
xtime = lambda a: (((a << 1) ^ 0x1B) & 0xFF) if (a & 0x80) else (a << 1)


def mix_single_column(a):
    # see Sec 4.1.2 in The Design of Rijndael
    t = a[0] ^ a[1] ^ a[2] ^ a[3]
    u = a[0]
    a[0] ^= t ^ xtime(a[0] ^ a[1])
    a[1] ^= t ^ xtime(a[1] ^ a[2])
    a[2] ^= t ^ xtime(a[2] ^ a[3])
    a[3] ^= t ^ xtime(a[3] ^ u)


def mix_columns(s):
    for i in range(4):
        mix_single_column(s[i])


def inv_mix_columns(s):
    # see Sec 4.1.3 in The Design of Rijndael
    for i in range(4):
        u = xtime(xtime(s[i][0] ^ s[i][2]))
        v = xtime(xtime(s[i][1] ^ s[i][3]))
        s[i][0] ^= u
        s[i][1] ^= v
        s[i][2] ^= u
        s[i][3] ^= v

    mix_columns(s)

def matrix2byte(matrix):
    return bytes(sum(matrix,[]))

state = [
    [108, 106, 71, 86],
    [96, 62, 38, 72],
    [42, 184, 92, 209],
    [94, 79, 8, 54],
]

inv_mix_columns(state)
inv_shift_rows(state)

print(matrix2byte(state))
```

## Bringing It All Together

### Solution

This exercise is an implementation of AES decryption. It can be improved by adding documentation, input validation, constant variables, performance optimization, security improvements, and test cases.

```python
def decrypt(key, ciphertext):
    round_keys = expand_key(key)

    state = bytes2matrix(ciphertext)

    state = add_round_key(state, round_keys[-1])

    for i in range(N_ROUNDS - 1, 0, -1):
        inv_shift_rows(state)
        inv_sub_bytes(state)
        state = add_round_key(state, round_keys[i])
        inv_mix_columns(state)

    inv_shift_rows(state)
    inv_sub_bytes(state)
    state = add_round_key(state, round_keys[0])

    plaintext = matrix2bytes(state)

     return plaintext
```

## Modes of Operation Starter

### Solution

The solution for this problem is that use the requests module to communicate with a web service that encrypts and decrypts data using block cipher mode. It retrieves the ciphertext of an encoded flag, sends it to the web service to decode it, and then converts the resulting plaintext from hexadecimal format to ASCII to get the flag.

```python
import requests

BASE_URL = "http://aes.cryptohack.org/block_cipher_starter"

r = requests.get(f"{BASE_URL}/encrypt_flag")
data = r.json()
ciphertext = data["ciphertext"]
print("ciphertext", ciphertext)

r = requests.get(f"{BASE_URL}/decrypt/{ciphertext}")
data = r.json()
plaintext = data["plaintext"]
print("plaintext", plaintext)

print("flag", bytearray.fromhex(plaintext).decode())

```

## Passwords as Keys

### Solution

To try to decrypt a given ciphertext using a word list as the key source. It uses AES encryption algorithm and MD5 hash to generate the key. If the decrypted plaintext contains the word "crypto", it prints the plaintext and key in hexadecimal format.

```python
from Crypto.Cipher import AES
import hashlib

ciphertext = bytes.fromhex('c92b7734070205bdf6c0087a751466ec13ae15e6f1bcdd3f3a535ec0f4bbae66')

with open("words.txt") as f:
    words = [w.strip() for w in f.readlines()]

for w in words:
    key = hashlib.md5(w.encode()).digest()

    cipher = AES.new(key, AES.MODE_ECB)
    decrypted = cipher.decrypt(ciphertext)

    if b'crypto' in decrypted:
      print("plaintext", decrypted)
      print("password_hash", key.hex())
      exit
```

## ECB CBC WTF

### Solution

this problem uses AES encryption to encrypt and decrypt a message. It sends HTTP requests to endpoints to get ciphertext and plaintext, and performs XOR operations to get the original message. The plaintext is then concatenated and printed as a flag.

```pyhton
import json
import requests

URL_encrypt = "http://aes.cryptohack.org/ecbcbcwtf/encrypt_flag/"
URL_decrypt = "http://aes.cryptohack.org/ecbcbcwtf/decrypt/{ciphertext}/"

def get_ciphertext(plaintext):
    r = requests.get(URL_encrypt)
    json_ans = json.loads(r.text)
    return json_ans['ciphertext']

def get_plaintext(ciphertext):
    r = requests.get(URL_decrypt.format(ciphertext=ciphertext))
    json_ans = json.loads(r.text)
    return json_ans['plaintext']

def xor(itx, ity):
    return [x ^ y for x, y in zip(itx, ity)]

ciphertext = get_ciphertext('Dont care')
split_ciphertext = [ciphertext[i:i+32] for i in range(0, len(ciphertext), 32)]  # [0] is the IV, [1] and subsequent are the encryptions of the plaintext blocks.

plaintext = [0]*(len(split_ciphertext) - 1)
for i in range(len(plaintext)):
    pi = bytes.fromhex(get_plaintext(split_ciphertext[i+1]))
    ci = bytes.fromhex(split_ciphertext[i])
    plaintext[i] = ''.join(map(chr, xor(pi, ci)))

print(f"Flag: {''.join(plaintext)}")
```

## ECB Oracle

### Solution

The idea of this solution is to perform a cryptographic attack against an AES-ECB encryption oracle to recover a secret message. This code sends HTTP requests to the oracle with various messages, uses the resulting ciphertext blocks to recover each byte of the secret message, and outputs the recovered message.

```python
import requests

s = requests.session()
rcount = 0
def encrypt(data):
	global rcount
	rcount += 1
	r = s.get(f"http://aes.cryptohack.org/ecb_oracle/encrypt/{data.hex()}/")
	return(bytes.fromhex(r.json()["ciphertext"]))
def encrypt_big(data):
	MAX_SIZE = 0x10*56
	for i in range((len(data)-1)//MAX_SIZE+1):
		block = data[i*MAX_SIZE:(i+1)*MAX_SIZE]
		ct = encrypt(block)[:len(block)]
		for j in range(len(ct)//0x10):
			yield ct[j*0x10:(j+1)*0x10]
charset = list(b"etoanihsrdlucgwyfmpbkvjxqz{}_01234567890ETOANIHSRDLUCGWYFMPBKVJXQZ")
for i in range(0x100):
	if i not in charset:
		charset.append(i)
targets = [encrypt(b"A"*(0x10-i)) for i in range(0x10)]
lengths = list(map(len, targets))
flag_len = lengths[-1] - 0x11 + lengths.index(lengths[-1])

flag = b""
for _ in range(flag_len):
	b, i = divmod(len(flag) + 1, 0x10)
	target = targets[i][b*0x10:(b+1)*0x10]
	attempts = b""
	for c in charset:
		attempts += (b"A"*0x10+flag+bytes([c]))[-0x10:]
	for c, ct in zip(charset, encrypt_big(attempts)):
		if ct == target:
			flag += bytes([c])
			print(flag)
			break
	else:
		exit("oof")

print(f"solved in {rcount} HTTP requests!")
```

## Flipping Cookie

### Solution

By asking @Giappp I have an idea, this exercise can be solved as follows: get a cookie from a web service, modify it and use it to request a flag from another web service. The modification is done by XOR-ing the initialization vector and the first block of the original cookie with a new string, creating a new initialization vector and using it to encrypt the modified cookie. The flag is obtained by sending a request with the modified cookie to the second web service.

```python
import requests
import json
from Crypto.Util.strxor import strxor

def get_cookie():
	url='https://aes.cryptohack.org/flipping_cookie/get_cookie/'
	response=requests.get(url)

	return response.json()

def get_flag(cookie,iv):
	url='https://aes.cryptohack.org/flipping_cookie/check_admin/'
	response=requests.get(url+'/'+cookie+'/'+iv)

	return response.json()

data=get_cookie()['cookie']
iv=bytes.fromhex(data[:32])

text=b'admin=False;expi'  #taking only the initial block... since that's only required
forge_text=b'admin=True;expir'

xor_result=strxor(iv,text)
forge_iv=strxor(xor_result,forge_text).hex()

print(get_flag(data[32:],forge_iv)["flag"])
```

## Lazy CBC

### Solution

For this exercise, we can use a Python script to perform a simple attack on the AES encryption system with CBC mode of operation by sending HTTP GET requests and XORing server responses. The goal is to decrypt a message that has been encrypted using the encryption system.

```python
import requests
from Crypto.Util.Padding import pad, unpad
from Crypto.Util.number import long_to_bytes, bytes_to_long

def get_flag(key):
    url = "http://aes.cryptohack.org/lazy_cbc/get_flag/"
    url += key.hex()
    url += "/"
    r = requests.get(url)
    js = r.json()
    return bytes.fromhex(js["plaintext"])

def response(ciphertext):
    url = "http://aes.cryptohack.org/lazy_cbc/receive/"
    url += ciphertext.hex()
    url += "/"
    r = requests.get(url)
    js = r.json()
    return bytes.fromhex(js["error"][len("Invalid plaintext: "):])

def xor(a, b):
    return long_to_bytes(bytes_to_long(a) ^ bytes_to_long(b))

ciphertext = b"\x00" * 32

CD = response(ciphertext)
C = CD[:16]
D = CD[16:]
print(get_flag(xor(C, D)))
```

## Triple DES

### Solution

In my opinion, this code defines two functions that convert data between a 16 byte array and a 4x4 matrix, and print the output of the matrix2bytes function with a predefined 4x4 matrix as input.

```python
def bytes2matrix(text):
    """ Converts a 16-byte array into a 4x4 matrix.  """
    return [list(text[i:i+4]) for i in range(0, len(text), 4)]

def matrix2bytes(matrix):
    """ Converts a 4x4 matrix into a 16-byte array.  """
    text = ''
    for i in range(len(matrix)):
        for j in range(4):
            text += chr(matrix[i][j])
    return text

matrix = [
    [99, 114, 121, 112],
    [116, 111, 123, 105],
    [110, 109, 97, 116],
    [114, 105, 120, 125],
]

print(matrix2bytes(matrix))
```
