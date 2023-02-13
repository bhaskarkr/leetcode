class OrderedStream:

    def __init__(self, n: int):
        self.count = 1
        self.data = [-1]*(n+2)

    def insert(self, idKey: int, value: str) -> List[str]:
        self.data[idKey] = value
        while self.data[self.count] != -1:
            self.count += 1
        return self.data[idKey: self.count]


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
