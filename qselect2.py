import random
def qselect(num,array):
	if array==[]:
		return
	pivot=array[random.randint(0,len(array)-1)]
	array.remove(pivot)
	left=[ x for x in array if x<=pivot]
	if(num<=len(left)):
		return qselect(num,left)
	if(num==len(left)+1):
		return pivot
	else:
		right=[x for x in array if x>pivot]
		return qselect(num-len(left)-1,right)

print(qselect(2,[3,10,4,7,19]))
print(qselect(2, [1, 2, 7, 3, 1, 1, 1, 11, 2, 8, 3]))
print(qselect(2, [3, 10, 4, 7, 19]))
print(qselect(2, [2, 2, 8, 3]))