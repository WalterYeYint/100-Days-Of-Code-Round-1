#Finding the pair of values that sum up to the target value
#Python2 Code

def find_pairs(values, target):
    if target > 1:
        value_dict = {}
        for value in values:
            if value in value_dict:
                value_dict[value] += 1
            else:
                value_dict[value] = 0
        for value in values:
            target_compliment = target - value
            if target_compliment in value_dict:
                if target_compliment == value:
                    if not value_dict[target_compliment] > 0:
                        continue
                return str(value) + " and " + str(target_compliment)
    return "No valid pairs"


print find_pairs([14, 13, 6, 7, 8, 10, 1, 2], 3) == "1 and 2"
print find_pairs([14, 13, 6, 7, 8, 10, 1], 3)
print find_pairs([14, 13, 6, 7, 8, 10, 1, 4, 2, 3], 5)
print find_pairs([2], 4)
print find_pairs([2], -1) == "No valid pairs"
print find_pairs([], 4)
