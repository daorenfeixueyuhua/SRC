class Student():
    name = ''
    age = 0
    id = 0

    def __init__(self, name, age, id):
        self.name = name
        self.age = age
        self.id = id

    def __str__(self):
        return 'my name is ' + self.name + ' and I am ' + str(self.age) + ' years old, my number is ' + str(self.id)


if __name__ == "__main__":
    student = Student('pengda', 22, 10086)
    print(student)
