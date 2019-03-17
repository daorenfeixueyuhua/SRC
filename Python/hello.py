

class Student():

    def __init__(self, name, id):
        self.name = name
        self.id = id

    def show(self):
        print("I am " + self.name + " and my id is " + self.id)


if __name__ == "__main__":
    s = Student('彭达', '123')
    s.show()
