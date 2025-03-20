# List Manipulation
# Ethan Greenhouse
# 2/2/2025

# Combines two lists of integers, removes duplicates, and returns a sorted list
def combineLists(left_list, right_list):
    # Check if both inputs are lists
    if not isinstance(left_list, list) or not isinstance(right_list, list):

        # Check if all elements in both lists are integers
        if not all(isinstance(x, int) for x in left_list + right_list):
            return None  

    return sorted(list(set(left_list + right_list)))

# Doubles last value in each row of 2D array
def doubleLastValue(list_of_lists):
    # Check if the input is a list
    if not isinstance(list_of_lists, list):
        return None

    # Iterate through each row in the list of lists
    for row in list_of_lists:
        # Check if the row is a list and is not empty
        if not isinstance(row, list) or not row:
            return None  

    return [row[:-1] + [row[-1] * 2] for row in list_of_lists]

# Example usage
print(f"Combined list: {combineLists([1, 2, 3], [3, 4, 5])}")           # Output: Combined list: [1, 2, 3, 4, 5]
print(f"Doubled list value: {doubleLastValue([[1, 2, 3], [4, 5, 6]])}") # Output: Doubled list value: [[1, 2, 6], [4, 5, 12]]
