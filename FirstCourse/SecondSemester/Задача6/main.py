def func(numbers):
    if len(numbers) < 3:
        return numbers

    intervals = []
    count = 0
    i = 1
    while i < len(numbers) - 1:
        if numbers[i] < numbers[i-1]:
            start = i
            while i < len(numbers) - 1 and numbers[i] == numbers[i+1]:
                i += 1
            if i < len(numbers) - 1 and numbers[i] < numbers[i+1]:
                intervals.append((start, i + 1))
        i += 1

    for j in range(intervals[len(intervals) - 1][1], len(numbers)):
        if numbers[j] < numbers[j-1]:
            start = j
    intervals.append((start , len(numbers)))

    if len(intervals) % 2 == 0:
        count = len(intervals)
    else:
        count = len(intervals) - 1
    print(count)
    for j in range(count - 2, -1, -2):
        s1, e1 = intervals[j]
        s2, e2 = intervals[j+1]

        numbers[s1:e2] = numbers[s2:e2] + numbers[e1:s2] + numbers[s1:e1]

    return numbers

def main():
    with open('input.txt', 'r') as file:
        line = file.readline()
        if not line: return
        numbers = list(map(int, line.split()))
    print(*(func(numbers)))

main()
