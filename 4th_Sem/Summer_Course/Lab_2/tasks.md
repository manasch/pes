# Task 1 - Frequence Analysis

Create a random text file and run the following command to get the number of occurences of a letter.
Performing a frequence analysis.

```
grep -o h input.txt | uniq -ic
```

Using grep to find and highlight a text pattern in the file

```
grep he input.txt
```

To replace an occurence in a file or text, run the following command

```
tr 'H' 'Ti' < output.txt > output2.txt
```
The letters are mapped with what to replace, hence H here is mapped to T andhence all occurences of H will be replaced by T

Similary if this is used
```
tr 'Hello' 'Times' < output.txt > output2.txt
```

Here, H - T, e - i, l - e (latest l is mapped to the corresponding letter in the replace string), and so on

Generating a simple substitution key using python

```py
$ python3
>>> import random
>>> s = "abcdefghijklmnopqrstuvwxyz"
>>> list = random.sample(s, len(s))
>>> ’’.join(list)i
'qilykvfwpxdgaczjotburmshen' # Key generated for me
```

Using this key to create a random mapping of letters with the original alphabet order, cleaning up the input.txt file so that only alphabets remain.
```
tr -cd '[a-z] [\n] [:space:]' < lowercase_output.txt > plaintext.txt

tr 'abcdefghijklmnopqrstuvwxyz' 'qilykvfwpxdgaczjotburmshen' < plaintext.txt > ciphertxt.txt
```
----------

# Task 2 - Encryption using Different Ciphers and Modes

Encrypting the plaintext file using aes 128 encryption method

```bash
openssl enc -aes-128-cbc -e -in plaintext.txt -out cipher.bin -K 00112233445566778889aabbccddeeff -iv 0102030405060708
```
The binary encrypted file can be decrypted using the following command

```bash
openssl enc -aes-128-cbc -e -in cipher.bin -out decrypt.txt -K 00112233445566778889aabbccddeeff -iv 0102030405060708
```

----------


