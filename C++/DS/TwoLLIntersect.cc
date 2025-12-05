TODO  make PDF 
Approach
1. Count Lengths: Calculate the lengths of both linked lists.
2 .Align Lists: Advance the pointer of the longer list by the difference in lengths to ensure both pointers traverse the 
same remaining distance.
3. Traverse Together: Move both pointers one step at a time until they meet at a node (intersection point) or reach the end (nullptr,
no intersection).
Return Result: If they meet at a non-null node, return that node as the intersection point; otherwise, return nullptr.
