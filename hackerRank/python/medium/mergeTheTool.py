def removeDuplicate(string):
    result=''
    for char in string:
        if char not in result:
            result+=char
    
    return result

def merge_the_tools(string, k):
    string_length = len(string)
    total_segment = int (string_length / k)

    segment = []
    for i in range(total_segment):
        segment_element = string[i*k:(i+1)*k]
        segment_element_trimmed = removeDuplicate(segment_element)
        print(segment_element_trimmed)
        # segment.append(segment_element_trimmed)

    # print(segment)

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)


# print(mergeTheTools('AABCAAADA',3))
# string = 'AABCAAADA'