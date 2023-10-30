class Solution:

    def sortByBits(self, arr: List[int]) -> List[int]:  
        def compa(a : int, b : int) -> int:
            ac = a.bit_count()
            bc = b.bit_count()
            if ac == bc:
                return a - b 
            return  ac - bc  
        return sorted(arr, key = cmp_to_key(compa))

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:  
        def compa(a : int, b : int) -> int:
            ac = bin(a).count('1')
            bc = bin(b).count('1')
            if ac == bc:
                return a - b 
            return  ac - bc  
        return sorted(arr, key = cmp_to_key(compa))  
