### Solution

Preprocessing and preparation.
 
Express 'admin=True' as a long yields $m=459922107199558918501733$.
Plugging this into a factorizer yields two prime factors:
   $p1=211578328037$ and $p2=2173767566209$, $m = p1 * p2$

Asking the server to sign each of these messages individually will yield
pow(p1, D, N) and pow(p2, D, N), and it will respond since neither of these individual messages is 'admin=True' when decoded.

Now, you can compute the digital signature of 'admin=True' by multiplying the two signatures you got! Since $p1^D * p2^D = (p1 * p2) ^ D \mod N$.

![image](https://user-images.githubusercontent.com/126962960/233801111-461920e5-5f18-44be-b369-5e9975021649.png)
