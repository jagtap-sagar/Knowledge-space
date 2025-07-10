Approach
Count Lengths: Calculate the lengths of both linked lists.
Align Lists: Advance the pointer of the longer list by the difference in lengths to ensure both pointers traverse the same remaining distance.
Traverse Together: Move both pointers one step at a time until they meet at a node (intersection point) or reach the end (nullptr, no intersection).
Return Result: If they meet at a non-null node, return that node as the intersection point; otherwise, return nullptr.
