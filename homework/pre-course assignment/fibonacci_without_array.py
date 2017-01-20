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

def fibonacci(n):
    fib = ((1+math.sqrt(5))**n-(1-math.sqrt(5))**n)/(2**n*math.sqrt(5)) #fibonacci formula
    print(round(fib), end=" ")


#### Runner Code
start_num, seq_size = '', ''

while not start_num.isdigit() or not 1 <= int(start_num) <= 10:
	start_num = version_response("Pick a number between 1 and 10: ")
while not seq_size.isdigit() or not 1 <= int(seq_size) <= 20:
	seq_size = version_response("Pick a number between 1 and 20: ")

for index in range(0, int(seq_size)):
	fibonacci(int(start_num) + index)

print() #final break