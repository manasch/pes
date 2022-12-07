# Software Engineering Lab 3

## Team 2
|Name|SRN|
|----|---|
|Manas Chebrolu|PES1UG20CS111|
|Chetan Gurram|PES1UG20CS112|
|Ayush Kumar|PES1UG20CS095
|Atharv Tiwari|PES1UG20CS087|
|Aryan Karn|PES1UG20CS080|

---

## Task 1A

1) Do you think Defensive Programming is applicable to your project? 
	- Follow Up: is redundancy not applicable in this case where a single system is executing the program?

Ans
```
While there is no constraint on the user input in our project. Given that blockchain are 
supposed to be highly secure and to maintain this security we must follow defensive 
programming as it is necessary to maintain the trust of the user base on the security and fault 
tolerance of our project.
```

2) As a developer, should we rely entirely on the user providing correct input?
	- In your project, include statements to ensure that the program only continues with data that is of the expected type

Ans
```
Only to a given extent, yes. However, one must understand that often there can be cases where 
the user inputs incorrect data due to human error, which as we all know is quite unavoidable. 
Thus, building programs with the assumption that users always provide correct input could result 
is instability and vulnerabilities in the program.

In our program there is no strict restriction on the input that is provided by the user. However,
because of how blockchains are designed and are expected to work any erroneous data that is 
once submitted cannot not be deleted and unfortunately for us we cannot detect if the input 
provided by the user is correct or not.
```

3) While working on your project, the go to approach to debug is using print statements. Include these statements to highlight the location and values at the current point in the project?

Ans
```
Using print statements is often utilized by developers who lack experience of using debugging 
tools such as pdb, gdb and jdb. Print statements can help a developer monitor the dataflow and 
help isolate any logical error in the code. However, print statements become grossly 
inadequate as the complexity of the project rises.

In our project, the print statements can be utilized to a certain degree to monitor if the 
blockchains are linking properly. However, due to how blockchains function may require better 
debugging tools to ensure fault tolerance and security.
```

4) Build two valid and invalid test cases for any two functions in your project?

Ans
```
(Invalid Case) When the 'hash' of a node and the 'previous hash' of the next node do not 
match it can result in all nodes after these two nodes to become invalid and is generally a sign 
of tampering with blockchain or error in logic of code.

(Valid Case) When the 'hash' of a node and the 'previous hash' of the next node are 
matching for every node.
```

## Task 3

- Git branching and merging stuff.
