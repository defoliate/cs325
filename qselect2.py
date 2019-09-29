# def qselect(num,array):
def qselect(num,array):
	if len(array)==num:
		print("finished")
		return array
	else:
		print(array[0])
		pivot=array[0]
		left=[x for x in array if x<pivot]
		# print(pivot)
		# print(len(array)/2)
		if len(left)>num:
			return qselect(num,left)+[pivot]
		if len(left)==num-1:
			return left[0]
		else:
			right=[x for x in array[1:] if x>=pivot]
			return qselect(num,right)
		# array=left+[pivot]+right
		# return[x for x in array if len([y for y in array if y<=x])==num]
		# return qselect(num,left)+[pivot]+qselect(num,right)
		#iterate
# def qselect(num,array):
# 	if num<0:
# 		return
# 	else:
# 		return(sort(array)[num-1])
# qselect(2, [3, 10, 4, 7, 19])
# qselect(4, [11, 2, 8, 3])
# qselect(2,[3,10,4,7,19])
print(qselect(2,[3,10,4,7,19]))
# print(qselect(4, [11, 2, 8, 3]))
