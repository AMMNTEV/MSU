def main():
    with open('input.txt', 'r') as file:
        line = file.readline()
        numbers = list(map(int, line.split()))

    print(func(numbers))

def func(numbers):
    if not numbers:
        return 0

    count = 0
    f = 0
    for i in range(1, len(numbers)):
        if numbers[i] > numbers[i-1]:
            f = 1
        if numbers[i] <= numbers[i-1] and f == 1:
            count += 1
            f = 0
    if f == 1:
        count += 1
    return count

main()
