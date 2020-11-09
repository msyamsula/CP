class Node():
    def __init__(self, data):
        self.__data = data
        self.__left = None
        self.__right = None

    def getRight(self):
        return self.__right

    def getLeft(self):
        return self.__left
    
    def getData(self):
        return self.__data

    def insertRight(self, new_node):
        self.__right = new_node

    def insertLeft(self, new_node):
        self.__left = new_node

class binaryTree():
    def __init__(self, root):
        self.__root = Node(root)
        self.__pointer = self.__root

    def resetPointer(self):
        self.__pointer = self.__root

    def getPointer(self):
        return self.__pointer

    def getPointerData(self):
        return self.__pointer.getData()

    def goRight(self):
        self.__pointer = self.__pointer.getRight()

    def goLeft(self):
        self.__pointer = self.__pointer.getLeft()

    def addLeft(self, new_data):
        new_node = Node(new_data)
        if self.__pointer.getLeft() == None:
            self.__pointer.insertLeft(new_node)

    def addRight(self, new_data):
        new_node = Node(new_data)
        if self.__pointer.getRight() == None:
            self.__pointer.insertRight(new_node)

        self.__pointer = self.__pointer.getRight()


# bt = binaryTree(9)
# bt.addLeft(5)
# bt.addRight(4)
# bt.addRight(2)
# bt.resetPointer()


# print(bt.getPointerData())


