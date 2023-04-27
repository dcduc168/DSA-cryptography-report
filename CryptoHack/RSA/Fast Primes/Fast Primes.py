from Crypto.Util.number import inverse, long_to_bytes
from factordb.factordb import FactorDB
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
f = open("key.pem", "r")
mail = f.read()
key = RSA.importKey(mail)
n = key.n
f.close()

c = "249d72cd1d287b1a15a3881f2bff5788bc4bf62c789f2df44d88aae805b54c9a94b8944c0ba798f70062b66160fee312b98879f1dd5d17b33095feb3c5830d28"

fdb = FactorDB(n)
fdb.connect()
arr = fdb.get_factor_from_api()
p = int(arr[0][0])
q = int(arr[1][0])
phi = (p - 1) * (q - 1)
e = 0x10001

d = inverse(e, phi)
key = RSA.construct((n, e, d))
cipher = PKCS1_OAEP.new(key)

m = cipher.decrypt(long_to_bytes(int(c, 16)))
print(m)