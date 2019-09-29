def qselect(A,k):    
    if len(A)<=k:return A    
    pivot = A[-1]    
    right = [pivot] + [x for x in A[:-1] if x>=pivot]    
    rlen = len(right)    
    if rlen==k:    
        return right    
    if rlen>k:    
        return qselect(right, k)    
    else:    
        left = [x for x in A[:-1] if x<pivot]    
        return qselect(left, k-rlen) + right     
print(qselect([11, 2, 8, 3],4))
# qselect(2, [3, 10, 4, 7, 19])
