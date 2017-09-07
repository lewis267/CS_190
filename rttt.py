#!\bin\python3
line = input()
tree = list(map(str.strip, line.split(',')))

def read_right(num_to_read, index):
    stars = 0
    for i in range(num_to_read):

        #check if done
        if index >= len(tree):
            return

        #check for star
        if tree[index] == '*':
            stars += 1

        else:
            #print comma
            if index > 0:
                print(',', end='')

            #print the number
            print(tree[index], end='')
            
        #increment
        index += 1

    if index >= len(tree):
        return
    else:
        read_left((num_to_read-stars)*2, index)
    
def read_left(num_to_read, index):
    rev_level = []
    #reverse this level
    for i in range(num_to_read):
        #check if done
        if index >= len(tree):
            break
        
        #add item
        rev_level.append(tree[index])
        
        #increment
        index+=1

    stars = 0
    # print the level
    for item in rev_level[::-1]:
        if item == '*':
            stars += 1
        else:
            print(','+str(item), end='')

    if index >= len(tree):
        return
    else:
        read_right((num_to_read-stars)*2, index)
        
read_right(1, 0)
print()
