class Solution:
    def isSameTree(self, p, q):
        # Dono nodes empty hain
        if p is None and q is None:
            return True

        # Sirf ek node empty hai
        if p is None or q is None:
            return False

        # Values different hain
        if p.val != q.val:
            return False

        # Left aur right subtree check karo
        return (
            self.isSameTree(p.left, q.left)
            and
            self.isSameTree(p.right, q.right)
        )