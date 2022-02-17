import random
import sys
min_nb = -1000
max_nb = 1000
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
