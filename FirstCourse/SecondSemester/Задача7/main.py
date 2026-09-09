import matplotlib.pyplot as plt

def quick_sort(arr, low, high, pivots):
    if low < high:
        p = arr[(low + high) // 2]
        i = low
        j = high
        while i <= j:
            while arr[i] < p:
                i += 1
            while arr[j] > p:
                j -= 1

            if i <= j:
                arr[i], arr[j] = arr[j], arr[i]
                update_plot(arr, f"Меняем {arr[i]} и {arr[j]}", pivots)
                i += 1
                j -= 1

        for pos in range(i, high + 1):
            if arr[pos] == p:
                pivots.add(pos)

        quick_sort(arr, low, j, pivots)
        quick_sort(arr, i, high, pivots)
    return arr

def update_plot(arr, title, pivots):
    plt.clf()
    colors = []
    for idx in range(len(arr)):
        if idx in pivots:
            colors.append('lightgreen')
        else:
            colors.append('steelblue')

    plt.bar(range(len(arr)), arr, color=colors, edgecolor='black')
    plt.title(title)
    plt.pause(0.1)

def main():
    plt.ion()
    pivots = set()

    with open('input.txt', 'r') as file:
        line = file.readline()
        if not line:
            return
        array = list(map(int, line.split()))

    print("Исходный массив:", *(array))
    sorted_array = quick_sort(array, 0, len(array)-1, pivots)
    print("Отсортированный массив:", *(sorted_array))

    plt.clf()
    plt.bar(range(len(sorted_array)), sorted_array, color='lightgreen', edgecolor='black')
    plt.title(f'Готово!')
    plt.ioff()
    plt.show()

main()
