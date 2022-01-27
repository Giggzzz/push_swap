import random
import sys
#min_nb = -2147483648
#max_nb = 2147483647
try:
	count = int(sys.argv[1])
except:
	count = 100
list = random.sample(range(0, 500), count)
text = ""
for i in list:
	text += str(i)
	text += " "
print(text)
