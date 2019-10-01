def sort(array):
	if array==[]:
		return []
	else:
		pivot=array[0]
		left=[x for x in array if x<pivot]
		right=[x for x in array[1:] if x>=pivot]
		a = [sort(left)]+[pivot]+[sort(right)]
		_left = sort(left)
		_right = sort(right)
		return[_left + [pivot] + _right]
		return a



t = sort([4,2,6,3,5,7,1,9])
# print(sort([4,2,6,3,5,7,1,9]))
# t=[4,2,6,3,5,7,1,9]
def search(t, x):
	for i in t:
		if x==i:
			print("xx")
			return True
		else:
			# for j in t[0]:
			# 	if x==j:
			# 		print(j)
			# 	else:
			# 		for k in t[2]:
			# 			print(k)
			print('y')
search(t,2)

def sorted(tree):
	return [sorted(tree[0]), tree[1], sorted(tree[2])]

