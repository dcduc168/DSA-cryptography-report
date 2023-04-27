from Crypto.Util.number import long_to_bytes,bytes_to_long,inverse
from gmpy2 import root
from pwn import *

io  = remote('socket.cryptohack.org',13375)
e = 3

req_msg = b"\\00VOTE FOR PEDRO"

msg_bits = len(bin(bytes_to_long(req_msg)))

d = inverse(e,2**(msg_bits-1))

req_msg = b"VOTE FOR PEDRO"

payload = hex(pow(bytes_to_long(req_msg),d,2**(msg_bits)))[2:]

inp = """{"option":"vote","vote":\"""" + payload + "\"}"
io.recv()
io.sendline(inp)
print(io.recv())
