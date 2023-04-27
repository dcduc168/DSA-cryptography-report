### Solution

In file Output.txt, we have n, e, ct. In there, e = 3 is pretty small whereas n is big, so it is possible that pow(m,e) is inferior to n

so c, which is pow(m,e,n) would probably simply be pow(m,e)=pow(m,3) 

and so m = pow(c,1/3) is cube root of c

We used BinarySearch to find the cube root of c and used long_to_bytes to convert it. Finally, we got the flag.

![image](https://user-images.githubusercontent.com/126962960/233794559-7ddf23cc-e462-4ed6-b112-bcc5aa9c567e.png)
