### Libraries
import sys
import math


### Function Definition
def version_response(str):
	if sys.version_info[0] > 2: #check python version
		response = input(str)
	else:
		response = raw_input(str)
	return(response)

def get_user_input():
	start_num, seq_size = '', ''

	while not a.isdigit() or not 1 <= int(a) <= 10:
		a = version_response("Pick a number between 1 and 10: ")
	while not b.isdigit() or not 1 <= int(b) <= 20:
		b = version_response("Pick a number between 1 and 20: ")

	return [int(a), int(b)]

def fibonacci(n):
    fib = ((1+math.sqrt(5))**n-(1-math.sqrt(5))**n)/(2**n*math.sqrt(5)) #fibonacci formula
    return(round(fib))


# Runner Code
sequence = []
user_input = get_user_input()
start_num, seq_size = user_input[0], user_input[1]

for index in range(0, seq_size):
	next_num = fibonacci(start_num + index)
	sequence.append(next_num)

print(*sequence, sep=' ') #pretty print