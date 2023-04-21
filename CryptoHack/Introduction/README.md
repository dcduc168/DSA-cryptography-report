# Introduction

## Finding Flags

### Solution

Simply submit `crypto{y0ur_f1rst_fl4g}`

## Great Snakes

### Solution

Download `great_snakes.py` then run with Python 3.

```python
import sys
# import this

if sys.version_info.major == 2:
    print("You are running Python 2, which is no longer supported. Please update to Python 3.")

ords = [81, 64, 75, 66, 70, 93, 73, 72, 1, 92, 109, 2, 84, 109, 66, 75, 70, 90, 2, 92, 79]

print("Here is your flag:")
print("".join(chr(o ^ 0x32) for o in ords))
```

## Network Attacks

### Solution

We got the file name _telnetlib_example.py_. After I download and open it, I will put the code below

```python
#!/usr/bin/env python3

import telnetlib
import json

HOST = "socket.cryptohack.org"
PORT = 11112

tn = telnetlib.Telnet(HOST, PORT)


def readline():
    return tn.read_until(b"\n")

def json_recv():
    line = readline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    tn.write(request)


print(readline())
print(readline())
print(readline())
print(readline())


request = {
    "buy": "clothes"
}
json_send(request)

response = json_recv()

print(response)

```

The first line I see the Shebang so in terminal I run it like a bash scipting file.

```bash
./telnetlib_example.py
```

So it return this

```
b"Welcome to netcat's flag shop!\n"
b'What would you like to buy?\n'
b"I only speak JSON, I hope that's ok.\n"
b'\n'
{'error': 'Sorry! All we have to sell are flags.'}
```

After that I think we need to change **"buy": "clothes"** to **"buy": "flag"**. And then I run the script again so we got the flag.

```
b"Welcome to netcat's flag shop!\n"
b'What would you like to buy?\n'
b"I only speak JSON, I hope that's ok.\n"
b'\n'
{'flag': 'crypto{sh0pp1ng_f0r_fl4g5}'}
```
