# decode
Write a program that implements a bit stream cipher decoder. An elementary level bit
stream cipher is an encryption algorithm that encrypts 1 byte of plain text at a time. This
cipher uses a given 4-bit bit pattern as the key. The size of the encrypted message that
we want to be able to send has a maximum length of 200 characters. The 4-bit
pattern must be duplicated to an 8-bit value for this to work. (e.g., if we have the 4-bit
pattern 0110, then the 8-bit key would be 0110 0110.)
Here is an example:
If we have the ASCII value for the letter ‘t’, then that equates to the hex value 0x74,
which represents the binary value 0111 0100. If we bitwise XOR that value with a key,
say 0101 0101, then
0111 0100 -> ‘t’
0101 0101 -> XOR with key encryption
0010 0001 -> encrypted value 0x21
If we XOR the encrypted value with the key, we get our ASCII value back.
0010 0001 -> encrypted value 0x21
0101 0101 -> XOR with key decryption
0111 0100 -> ‘t’
The bit stream encryption cipher that your program must decode does a little more than
this. After encrypting the value, the program adds an alternating bit rotation twist to the
algorithm. The alternating bit rotation algorithm is such that once you have the
encrypted value (0x21, in the example above), if it is the 1st character of the encrypted
message , it must be rotated one bit to the left (in our example above that would mean
0b 0010 0001 would become 0b 0100 0010 or 0x42). The encrypted value for the 2ndcharacter of the message would be rotated one bit to the right, 3rd char rotated left, 4throtated right and so forth. As a further example, if ‘t’ is rotated to the right one 
position, that would mean 0b 0010 0001 would become 0b 1001 0000 or 0x90. 
