void printUnorderedPairs(int[] array) {
 for (int i= 0; i < array.length; i++) {
   for (int j = i + 1; j < array.length; j++) {
     cout<<(array[i] + "," + array[j]);
   }
  }
}



### Time Complexity Calculation
1. **Outer Loop**: Runs from `i = 0` to `i = array.length - 1`, which is `n` iterations, where `n` is the length of the array.
2. **Inner Loop**: For each value of `i`, the inner loop runs from `j = i + 1` to `j = array.length - 1`. The number of iterations for `j` depends on `i`:
   - When `i = 0`, `j` runs from 1 to `n - 1`: `n - 1` iterations.
   - When `i = 1`, `j` runs from 2 to `n - 1`: `n - 2` iterations.
   - When `i = 2`, `j` runs from 3 to `n - 1`: `n - 3` iterations.
   - ...
   - When `i = n - 2`, `j` runs from `n - 1` to `n - 1`: 1 iteration.
   - When `i = n - 1`, `j` has no iterations (since `j = i + 1` exceeds `n - 1`).

3. **Total Work**:
   - The total number of pairs printed is the sum of the inner loop iterations:
     - Number of iterations = `(n - 1) + (n - 2) + (n - 3) + ... + 1`.
   - This is an **arithmetic series**: sum of integers from 1 to `n - 1`.
   
4. **Time Complexity**:
   - The dominant term in the expression (frac{n^2 - n}{2\) is \(\frac{n^2}{2}\).
   - In time complexity, we ignore constants and lower-order terms.
   - Thus, the time complexity is (O(n^2)).

