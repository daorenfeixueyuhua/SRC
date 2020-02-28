class Animal():
    name = ''

    def eat(self):
        return None

    def run(self):
        return None


class Tiger(Animal):
    name = 'Tiger'

    def __init__(self):
        print('I am Tiger')

    def eat(self):
        print('I like eat meant.')

    def run(self):
        print('I can running.')


class Rabbit(Animal):
    name = 'Rabbit'

    def __init__(self):
        print('I am Rabbit')

    def eat(self):
        print('I like grass very much.')

    def run(self):
        print('I can jump.')


if __name__ == "__main__":
    animal = Animal()
    animal.eat()

    rabbit = Rabbit()
    rabbit.eat()
    rabbit.run()

    tiger = Tiger()
    tiger.eat()
    tiger.run()
