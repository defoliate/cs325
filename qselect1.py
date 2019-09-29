def quickSort(num,arr):
	    less = []
	    pivotList = []
	    more = []
	    if len(arr) <= 1:
	        return arr
	    else:
	        pivot = arr[0]     
	        for i in arr:
	            if i < pivot:
	                less.append(i)
	            elif i > pivot:
	                more.append(i)
	            else:
	                pivotList.append(i)
	        less = quickSort(num,less)
	        more = quickSort(num,more)
	        # print(more)
	        # return less + pivotList + more
print(quickSort(4,[11, 2, 8, 3]))
# qselect(2, [3, 10, 4, 7, 19])
