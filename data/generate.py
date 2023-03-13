import random

def main():
    for i in range(1, 11):
        generate(i)

def generate(i):
    file = open(f"data/data{i}.txt", "w")

    for i in range(1000000):
        isPositive = [True, False]
        choice_ = random.choice(isPositive)
        if choice_:
            current_ = random.random()*random.randint(0, 1000000)
        else:
            current_ = random.random()*random.randint(0, 1000000)*(-1)
        file.write(f"{current_:.4f} ")

    file.close()

if __name__ == "__main__":
    main()