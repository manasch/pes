# Software Engineering Lab 4

## Team 2
|Name|SRN|
|----|---|
|Manas Chebrolu|PES1UG20CS111|
|Chetan Gurram|PES1UG20CS112|
|Ayush Kumar|PES1UG20CS095
|Atharv Tiwari|PES1UG20CS087|
|Aryan Karn|PES1UG20CS080|

---

## Task 1

- A unit is the smallest block of code that functions individually. The first level of testing is Unit testing, and this problem statement is geared towards the same.
	- Discuss with your teammates and demarcate units in your code base
		- Note: discuss why the code snippet you have chosen can be classified as a unit
	- Develop test cases for both valid and invalid data
	- Ideate how you could further modularize larger blocks of code into compact units with your teammates

Ans
```
We performed unit testing on 3 methods of our class namely ‘verify_transaction_signature()’, 
‘submit_transaction()’, and ‘valid_proof()’
The codes for which are given in the screenshot below

Refer to the code..

In order to test the methods above we wrote a separate python program which consisted of 1 Valid and 2 
Invalid test cases

The python program that we used to test is given below
```

```py
import unittest
from blockchain import Blockchain
from collections import OrderedDict

test_class = Blockchain()

class BlockchainTest(unittest.TestCase):
	# Returns True or False.
	def test(self):
		self.assertTrue(True)
		self.assertFalse(False)

	def test_verify_transaction_signature(self):
		self.assertTrue(test_class.verify_transaction_signature("30819f300d06092a864886f70d010101050003818d0030818902818100ac277ae4b1912bb0ce0a9350474f07928e8b18f9b10fdf6524d81fedb50618dbfa7487ec0b19260c1d207b5b5fca4c005a1e26934d3e5c656ac4440143dc483854174f606dad8a3613de00c270e345e5b8aa58c34433f12cb47722feb6d67f15e921d6bf59c20b5f078e911f4111ea25d66c2ef05999c8a074a2c09621928d250203010001",
																"a6259a66813edeaaae8aa422aecf4536ea2d28cf2efecc0a2b9a2e112cc1657099ac6d464e25e7ca8ff1f439cf7c09e1b446eeed07002c3cfb5625e0be53a5aa7334b1815bcaaea9fd6d6267b84bd961d1952fe6a171fe4cf8ee54b51a0729efd5e7cf8722d16683237088e0c8567a0074617fa241b5eea6aa5a5558ff11c089",
																OrderedDict([('sender_address', '30819f300d06092a864886f70d010101050003818d0030818902818100ac277ae4b1912bb0ce0a9350474f07928e8b18f9b10fdf6524d81fedb50618dbfa7487ec0b19260c1d207b5b5fca4c005a1e26934d3e5c656ac4440143dc483854174f606dad8a3613de00c270e345e5b8aa58c34433f12cb47722feb6d67f15e921d6bf59c20b5f078e911f4111ea25d66c2ef05999c8a074a2c09621928d250203010001'), ('recipient_address', '30819f300d06092a864886f70d010101050003818d0030818902818100b3ba506f2561e77e6f3567cbb24cf15e9e21951c3d2693e753173f4e9a1ed37b139aa72e0648e841666ebb919c8fdea3f3372bfe3107377a5e38fb704d74bd94ffcd5db37be06341a848cc301444e14b724151140fe68cac67e99df2a84bc3747096c1294feef4cd28210aaadaaf3909be8871cded7d716552e8bb4fa85738150203010001'), ('value', '3082025c02010002818100b3ba506f2561e77e6f3567cbb24cf15e9e21951c3d2693e753173f4e9a1ed37b139aa72e0648e841666ebb919c8fdea3f3372bfe3107377a5e38fb704d74bd94ffcd5db37be06341a848cc301444e14b724151140fe68cac67e99df2a84bc3747096c1294feef4cd28210aaadaaf3909be8871cded7d716552e8bb4fa8573815020301000102818004a5a017c79928f1a171798e103da20e06bbaa8dd0dcf2fd0bae71b218150cf5c5337df8182c8168d37bb078dad9f3713cc423ec8e1af829bf4eecdd61fb4f3d8451eb87116f61fb752bd91ef8a2599235578ee71ceff1280ca7229abf39a4cf26ecfa9483146adf175fbc89da7ba64a09c7588aff5b4527687d887f63e0796f024100bc4b6f41afbe1ff9a1d05b4cca80e85d0f38e777002663dee64e1f7b9bcedd11db828da5efe22edf4e3875fc38df8b445c13a884e45b1ccc9cfead3d17fd4f03024100f45a4bf686314eb636777d87b269d2ed30fc70c388e7f43ab02fd0107e43f04fbcde30b83a5de8aced326527a43a5fa2c7174bea40029a4aa853822fd0f505070241009172b3be49c2d370414e71382034f348ef394592e6cac0daad8c2b4590557aef10610889e5831231ec7a30a96445498ec4916adb3c8a24f4e950d1012046cb81024024e87aaedae819b68615985d65c27c3c9d7893e3c50b1c25bd350b9d62250ae85063d3421076dccd39eab1c2c2189b17703101a37955ab4e798c5b8eb3663f0302406ef59f4373044fae2f550b674db2a5ec44ec35f84f628d827b7034115ed7a01c8e4db26caedba6c62bb9d58b2665003933172c1b954d3b2fe193f9323cada1e9')])))
		self.assertFalse(test_class.verify_transaction_signature("30819f300d06092a864886f70d010101050003818d0030818902818100ac277ae4b1912bb0ce0a9350474f07928e8b18f9b10fdf6524d81fedb50618dbfa7487ec0b19260c1d207b5b5fca4c005a1e26934d3e5c656ac4440143dc483854174f606dad8a3613de00c270e345e5b8aa58c34433f12cb47722feb6d67f15e921d6bf59c20b5f078e911f4111ea25d66c2ef05999c8a074a2c09621928d250203010001",
																 "1",
																 OrderedDict([])))
		self.assertFalse(test_class.verify_transaction_signature("30819f300d06092a864886f70d010101050003818d0030818902818100ac277ae4b1912bb0ce0a9350474f07928e8b18f9b10fdf6524d81fedb50618dbfa7487ec0b19260c1d207b5b5fca4c005a1e26934d3e5c656ac4440143dc483854174f606dad8a3613de00c270e345e5b8aa58c34433f12cb47722feb6d67f15e921d6bf59c20b5f078e911f4111ea25d66c2ef05999c8a074a2c09621928d250203010001",
																 "a6259a66813edeaaae8aa422aecf4536ea2d28cf2efecc0a2b9a2e112cc1657099ac6d464e25e7ca8ff1f439cf7c09e1b446eeed07002c3cfb5625e0be53a5aa7334b1815bcaaea9fd6d6267b84bd961d1952fe6a171fe4cf8ee54b51a0729efd5e7cf8722d16683237088e0c8567a0074617fa241b5eea6aa5a5558ff11c089",
																 []))

	def test_submit_transaction(self):
		self.assertEqual(test_class.submit_transaction(
			"THE BLOCKCHAIN", "8a923b792e8544fd9efd96f2c50be4ac", "1", []), 2)
		self.assertNotEqual(test_class.submit_transaction(
			"THE BLOCKCHAIN", "8a923b792e8544fd9efd96f2c50be4ac", "1", []), 3)
		self.assertNotEqual(test_class.submit_transaction(
			"THE BLOCKCHAIN", "b1", "1", []), 3)

	def test_valid_proof(self):
		self.assertTrue(test_class.valid_proof(
			[], "fbcc3c6974806a25de04d4fbb8a32d645529e4e2220e1ec4430f9d293400ca58", 0))
		self.assertFalse(test_class.valid_proof(
			[], "fbcc3c6974806a25de04d4fbb8a32d645529e4e2220e1ec4430f9d293400ca58", 284))
		self.assertFalse(test_class.valid_proof(
			[], "fbcc3c6974806a25de04d4fbb8a32d645529e4e2220e1ec4430f9d293400ca58", 74))

if __name__ == '__main__':
	unittest.main()
```

```
The arbitrary values given above are Public and Primary Keys that we generated using RSA from the Crypto Module.
The results can be viewed by running the test script
```

```py
python test.py
```

## Task 3

- Static testing involves validating your code without any execution. Under this problem statement, you will be expected to analyse and calculate the cyclomatic complexity of your code.
	- Using the unit, you selected in the first problem statement as an example, develop the control flow graph of your problem statement.
	- Using the Control flow graph, calculate the cyclomatic complexity of your code.
	- Using the cyclomatic complexity as an indicator, Ideate and code your unit again to reduce complexity

Ans
```
We shall perform cyclomatic complexity analysis on the code given below
On numbering each line of code, we get the following result
```

```py
1	transaction = OrderedDict({"sender_address": sender_add, "recipient_address": receptient_add, "value": value})
2	if sender_add == MINING_SENDER:
3		self.transactions.append(transaction)
4		return len(self.chain) + 1
5	else:
6		transaction_verification = self.verify_transaction_signature(sender_add, signature, transaction)
7		if transaction_verification:
8			self.transactions.append(transaction)
9			return len(self.chain) + 1
10		else:
11			return False
```

```
From the above graph, the cyclometric complexity (E – N + 2P) is calculated as follows:

E = Number of edges
N = Number of nodes
P = Number of nodes with exit points

E = 8, N = 9, P = 3
Therefore

E – N + 2 P = 8 – 9 + (2 * 3) = 5

The relative complexity of the code is therefore not too high.

However there might be some possibility to reduce the complexity value by merging nodes 4 and 9, 
which are exit nodes returning the same value.

If we modify the code to the one given below
```

```py
1	transaction = OrderedDict({'sender_address': sender_address, 'recipient_address': recipient_address, 'value': value})
2	if sender_address == MINING_SENDER:
3		self.transactions.append(transaction)
4	else:
5		transaction_verification = self.verify_transaction_signature(sender_address, signature, transaction)
6		if transaction_verification:
7			self.transactions.append(transaction)
8		else:
9			return False
10	return len(self.chain) + 1
```

```
E = 10, N = 10, P = 2

Therefore

E – N + 2P = 10 – 10 + (2*2) = 4

Thus, from the test it does seem like we have simplified the code further, however it will be advisable for 
us to test it and ensure that it works as intended.
```
The control flow graphs can be found [here](./cyclomatic_complexity.drawio)
