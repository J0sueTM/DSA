# Sorting

Sorting algorithms are algorithms that process a collection of data and arrange them in a given order. For example, we can give the sequence (1, 6, 3, 4, 2, 5) to a sorting algorithm and it will return (1, 2, 3, 4, 5, 6).

In this case, we made a ascending sorting. Sorting algorithms can be also be used to process other types of data, like text, floats, lists, etc, in the given order.

**Implementation**

There are a lot of sorting algorithms. For learning purposes, we'll cover just the following:

- Bubble sort
- Selection sort
- Insertion sort
- Merge sort

If you want to study the other sorting algorithms, [here you go](https://www.geeksforgeeks.org/sorting-algorithms/).

### Bubble sort

```
function bubbleSort(integer array[] elements):
	for integer i = 0 in range elements.size():
		for integer j = 0 in range elements.size() - 1:
			if elements[j] > elements[j + 1]:
				swap(elements[j], elements[j + 1])
endfunction

integer array[] elements = input()
bubbleSort(elements)

for element in elements:
	print(element)
```

**Explanation**

The bubble sort algorithm works by iterating throughout the elements again and again, swapping the adjacent elements if they are not in the given order. The above algorithm will sort the elements in ascending order, if you want it to order by descending order, swap the elements if ```elements[j] < elements[j + 1]```.

### Selection sort

```
function selectionSort(integer array[] elements):
	integer minNumber = maximumInteger
	integer pos = 0

	for integer i = 0 in range elements.size():
		for integer j = i in range elements.size():
			if elements[j] < minNumber:
				minNumber = elements[j]
				pos = j
			
		swap(elements[i], elements[pos])
		maxNumber = 0
endfunction

int array[] elements = input()
selectionsort(elements)

for element in elements:
	print(element)
```

**Explanation**

The Selection sort algorithm works by iterating through the elements, choosing the smallest one, swapping it with the beginning of the actual iteration, and doing it again until it reaches the end.

### Insertion sort

```
function insertSort(integer array[] elements):
	integer prev = 0
	
	for i = 1 in range elements.size():
		prev = i - 1
		
		while prev >= 0 and arr[prev] > i:
			arr[prev + 1] = arr[prev]
			prev -= 1
		
		arr[j + 1] = i
endfunction

integer array[] elements = input()
insertSort(elements)

for element in elements:
	print(element)
```

**Explanation**

The insert sort algorithm works by iterating through the elements, starting at the second one, marking it and the previous. Then loop until previous is less than 0, changing the elements' positions one forward.