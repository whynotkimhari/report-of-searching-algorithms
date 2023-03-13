import matplotlib.pyplot as plt

x_axis_values = [i for i in range(1, 11)]

names = ["HeapSort", "IntroSort", "MergeSort", "QuickSort"]
for name in names:
    path = "values/" + name + ".txt"
    with open(path) as file:
        y_axis_values = list(map(float, file.read().strip().split(" ")))
    print(name, y_axis_values)
    plt.plot(x_axis_values, y_axis_values, label = name)

plt.xlabel('kth running')
plt.ylabel('running time - sec')
plt.title('Speed Line Graph')
plt.legend()

plt.show()