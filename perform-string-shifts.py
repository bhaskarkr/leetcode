class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        final_shift = 0
        for ss in shift:
            if ss[0] == 0:
                final_shift += ss[1]
            else:
                final_shift -= ss[1]
        final_shift %= len(s)
        # while final_shift > 0:
        #     s = s[1 : ] + s[0]
        #     final_shift -= 1
        return s[final_shift: ] + s[:final_shift]
