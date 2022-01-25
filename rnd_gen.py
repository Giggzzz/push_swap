import random
import sys
#min_nb = -2147483648
#max_nb = 2147483647
min_nb = 1
max_nb = 501
try:
	count = int(sys.argv[1])
except:
	count = 100
list = random.sample(range(min_nb, max_nb), count)
text = ""
for i in list:
	text += str(i)
	text += " "
print(text)
