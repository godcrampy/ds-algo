function binarySearch(array, n) {
  let l = 0, r = array.length - 1;

  while (l < r) {
    m = Math.floor(l + (r - l) / 2);
    if (array[m] > n) {
      r = m - 1;
    } else if (array[m] < n) {
      l = m + 1;
    } else {
      return m;
    }
  }

  return -1;
}

let arr = [2, 5, 6, 9, 13, 15, 15, 28, 30];

console.log(binarySearch(arr, 14));
console.log(binarySearch(arr, 28));
console.log(binarySearch(arr, 15));
