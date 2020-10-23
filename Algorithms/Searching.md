# Searching algorithms

Searching algorithms are algorithms that are used to find an element from a data structure. There are two types of searching algorithms:

- **Sequential search**: The data structure is iterated until the element is found. Linear search
- **Interval search**: The data structure must already be sorted, interval search divide the data structure step by step until the element is in the middle. Binary search

### Linear search

```
function linearSearch(integer array[] elements, integer targetElement):
	for i in range(elements,size()):
		if elements[i] == targetElement:
			return i
endfunction

integer array[] elements = input()
integer targetElement = input()

linearSearch(elements, targetElement)
```

### Binary search

```
# recursive
function recursiveBinarySearch(integer array[] elements, integer start, integer end, integer targetElement):
	integer middle = (start + end) / 2
	
	if elements[middle] == targetElement:
		return middle
	else if targetElement > elements[middle]:
		return recursiveBinarySearch(elements, middle + 1, end, targetElement)
	else if targetElement < elements[middle]:
		return recursiveBinarySearch(elements, start, middle, targetElement)
	else
		return -1 # not found
endfunction

# iterative
function iterativeBinarySearch(integer arry[] elements, integer targetElement):
	integer start = 0
	integer end = elements.size()
	integer middle = (start + end) / 2
	
	while elements[middle] != targetElement:
    	if elements[middle] > targetElement:
    		start = middle + 1
    		middle = (start + end) / 2
    	else if elements[middle] < targetElement:
    		end = middle
    		middle = (start + end) / 2
    		
    if elements[middle] == targetElement:
    	return middle
    else
    	return -1 # not found
endfunction

integer array[] elements = input()
integer targetElement = input()

print(recursiveBinarySearch(elements, 0, elements.size(), targetElement))
print(iterativeBinarySearch(elements, targetElement))
```

Obs: The binary search algorithms will work just with already sorted data structures