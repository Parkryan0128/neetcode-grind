class MyHashSet:

    def __init__(self):
        self.key_list = []

    def add(self, key: int) -> None:
        for item in self.key_list:
            if item == key:
                return
        self.key_list.append(key)

    def remove(self, key: int) -> None:
        for item in self.key_list:
            if item == key:
                self.key_list.remove(key)

    def contains(self, key: int) -> bool:
        for item in self.key_list:
            if item == key:
                return True
        
        return False
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)