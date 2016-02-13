def is_palindrome(string):
	for i,char in enumerate(string):
		if char != string[-i-1]:
			return False
	return True

str_input = raw_input()
if len(str_input) <= 300:
	if is_palindrome(str_input)==True:
		print "Yes"
	else: 
		print "No"

