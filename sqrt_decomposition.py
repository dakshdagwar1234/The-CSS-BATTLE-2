import math

class SqrtDecomposition:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        self.block_size = int(math.sqrt(self.n))
        self.num_blocks = (self.n + self.block_size - 1) // self.block_size
        self.blocks = [0] * self.num_blocks
        self._build()

    def _build(self):
        for i in range(self.n):
            block_idx = i // self.block_size
            self.blocks[block_idx] += self.arr[i]

    def update(self, idx, val):
        if not (0 <= idx < self.n):
            raise IndexError("Index out of bounds")
        
        block_idx = idx // self.block_size
        self.blocks[block_idx] += (val - self.arr[idx])
        self.arr[idx] = val

    def query(self, l, r):
        if not (0 <= l <= r < self.n):
            raise IndexError("Query range out of bounds")

        total_sum = 0
        
        # Traverse the first block partially
        while l <= r and l % self.block_size != 0:
            total_sum += self.arr[l]
            l += 1

        # Traverse full blocks
        while l + self.block_size <= r:
            block_idx = l // self.block_size
            total_sum += self.blocks[block_idx]
            l += self.block_size

        # Traverse the last block partially
        while l <= r:
            total_sum += self.arr[l]
            l += 1
            
        return total_sum

if __name__ == "__main__":
    arr = [1, 5, 2, 4, 6, 1, 3, 5, 7, 10]
    sq_decomp = SqrtDecomposition(arr)

    print("Initial array:", arr)
    print("Sum of range [0, 9]:", sq_decomp.query(0, 9)) # Expected: 44
    print("Sum of range [1, 4]:", sq_decomp.query(1, 4)) # Expected: 5 + 2 + 4 + 6 = 17

    sq_decomp.update(2, 10) # arr[2] becomes 10
    print("Array after update at index 2 to 10:", sq_decomp.arr)
    print("Sum of range [0, 9] after update:", sq_decomp.query(0, 9)) # Expected: 44 - 2 + 10 = 52
    print("Sum of range [1, 4] after update:", sq_decomp.query(1, 4)) # Expected: 5 + 10 + 4 + 6 = 25
