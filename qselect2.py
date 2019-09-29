# def qselect(num,array):
def qselect(num,array):
	if array==[]:
		return array
	pivot=array[0]
	# print(pivot)
	left=[x for x in array if x<pivot]
	# print(len(left))
	if num<len(left):
		return qselect(num,left)
	if num==len(left)+1:
		return pivot
	else:
		right=[x for x in array if x>pivot]
		# print(len(right))
		# print(right)
		# print("////")
		# print(num-len(left)-1)
		# print("====")

		return qselect(num-len(left)-1,right)
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
print(qselect(4, [11, 2, 8, 3]))
# qselect(2,[3,10,4,7,19])
print(qselect(2,[3,10,4,7,19]))
# print(qselect(2, [2, 2, 8, 3]))
