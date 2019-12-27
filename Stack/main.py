class Stack:

    def __init__(self, key, lengthMax):
        self.key = key
        self.top = 0
        self.lengthMax = lengthMax
        self.gaps = [None] * self.lengthMax

    def push(self, container):
        if(self.top == self.lengthMax):
            return 'Pilha cheia'

        self.gaps[self.top] = container
        self.top += 1

        return 'Adicionado'

    def pop(self):
        if(self.isEmpty()):
            return None

        container = self.gaps[self.top - 1]

        self.gaps[self.top - 1] = None
        self.top -= 1

        return container

    def isEmpty(self):
        return not bool(self.top)

    def isExist(self, id):
        i = 0

        while i < self.top and self.gaps[i].id != id:
            i += 1

        return not (i == self.top)

    def show(self):
        print('Pilha key: {} =>'.format(self.key))

        for container in self.gaps:
            print('{}'.format(container.id if container else container))
        print('')


class Container:

    def __init__(self, id):
        self.id = id


class Port:

    def __init__(self, length):
        self.length = length
        self.stacks = [Stack(str(i) if i < length - 1 else 'swap', 5)
                       for i in range(self.length)]

    def addContainer(self, container):
        stack = self.stackMin()
        stack.push(container)

    def removeContainer(self, id):
        stack = self.localizeContainer(id)

        if not bool(stack):
            print('Container não existe')

        container = stack.pop()
        while container and container.id != id:
            self.stacks[self.length - 1].push(container)
            container = stack.pop()

        print('Hora da troca')
        self.stacks[self.length - 1].show()

        containerSwap = self.stacks[self.length - 1].pop()
        while containerSwap:
            stack.push(containerSwap)
            containerSwap = self.stacks[self.length - 1].pop()

        return container

    def localizeContainer(self, id):

        for i in range(self.length - 1):
            if (self.stacks[i].isExist(id)):
                return self.stacks[i]

        return None

    def stackMin(self):
        stackMin = self.stacks[0]

        for stack in self.stacks[1:self.length - 1]:
            if stack.top < stackMin.top:
                stackMin = stack

        return stackMin

    def show(self):
        for stack in self.stacks:
            stack.show()


def main():

    port = Port(5)

    port.addContainer(Container(10))

    port.addContainer(Container(115))

    port.addContainer(Container(154))

    port.addContainer(Container(184))

    port.addContainer(Container(35))

    port.addContainer(Container(1))

    port.addContainer(Container(8))

    port.addContainer(Container(89))

    port.addContainer(Container(588))

    port.addContainer(Container(48))

    port.addContainer(Container(885))

    port.addContainer(Container(777))

    port.addContainer(Container(647))

    port.addContainer(Container(6969))

    port.show()

    port.removeContainer(1)

    port.show()


main()
