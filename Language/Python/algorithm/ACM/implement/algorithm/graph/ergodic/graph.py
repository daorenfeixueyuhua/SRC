class graph:
    info = []
    next = []
    to = []

    def __init__(self, n: int, m: int):
        self.info = [0 for _ in [0] * n]
        self.next = [0 for _ in [0] * m]
        self.to = [0 for _ in [0] * m]

    def edge_size(self):
        return len(self.to)

    def vertex_size(self):
        return len(self.info)


if __name__ == '__main__':
    pass
