def compute_h_index(Input):
    #Input.sort()

    left = 0
    right = len(Input) - 1

    h_idx = -2
    
    while left < right:
        middle = (int)(left + (right - left)/2)
        middle_element = Input[middle]
        remaining_elements = right - middle + 1

        if middle_element <= remaining_elements:
            h_idx = middle_element
            left = middle + 1

        else:
            right = middle - 1


    return Input[left]


some_numbers = [2, 2, 2, 4, 4, 4, 5, 5, 5, 5, 5, 6]
#some_numbers.sort()

#print("The value of len(some_numbers) is: ", len(some_numbers))

print("Here's a sorted array \n")
for i in range(0, len(some_numbers)):
    print(some_numbers[i], end = " ")
    
result = compute_h_index(some_numbers)
print('The h-index is: ', result)
