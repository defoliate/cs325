# def qselect(num,array):
def qselect(num,array):
	if array==[]:
		# print("finished")
		return []
	else:
		pivot=array[0]
		left=[x for x in array if x<pivot]
		right=[x for x in array[1:] if x>=pivot]
		array=left+[pivot]+right
		list1= [x for x in array if len([y for y in array if y<=x])==num]
		for i in list1:
			return i
		# print(result)
		return qselect(num,left)+[pivot]+qselect(num,right)
		#iterate
# def qselect(num,array):
# 	if num<0:
# 		return
# 	else:
# 		return(sort(array)[num-1])
# qselect(2, [3, 10, 4, 7, 19])
# qselect(4, [11, 2, 8, 3])

print(qselect(2,[3,10,4,7,19]))
# print(qselect(4, [11, 2, 8, 3]))
