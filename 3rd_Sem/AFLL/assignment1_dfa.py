# DFA, L = {a^nb^m | n mod 2 = 0, m >= 1}

def start(ch):
	if ch == 'a':
		return 1
	elif ch == 'b':
		return 3
	else:
		return -1

def state1(ch):
	if ch == 'a':
		return 2
	elif ch == 'b':
		return 4
	else:
		return -1
	
def state2(ch):
	if ch == 'a':
		return 1
	elif ch == 'b':
		return 3
	else:
		return -1

def state3(ch):
	if ch == 'a':
		return 4
	elif ch == 'b':
		return 3
	else:
		return -1

def state4(ch):
	return 4

def dfa(ch, state):
	if state == 0:
		return start(ch)
	elif state == 1:
		return state1(ch)
	elif state == 2:
		return state2(ch)
	elif state == 3:
		return state3(ch)
	elif state == 4:
		return state4(ch)
	elif state == 5:
		return state5(ch)
	else:
		return -1

def main():
	
	string_no = int(input("Number of inputs: "))

	i = 0
	while (i < string_no):
		string = input(f"Enter string {i + 1}: ")
		
		result = 0
		for char in string:
			result = dfa(char, result)

		if result == 3:
			print("String Accepted\n")
		elif result == -1:
			print("Invalid\n")
		else:
			print("String Rejected\n")
		i += 1


if __name__ == "__main__":
	main()