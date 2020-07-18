function radixSort(arr) {
  let zero = [], one = [];

  for (let j = 0; j < 31; ++j) {
    for (const n of arr) {
      if ((n & (1 << j)) != 0) {
        one.push(n);
      } else {
        zero.push(n);
      }
    }

    let i = 0;

    while (zero.length) {
      arr[i++] = zero.shift();
    }

    while (one.length) {
      arr[i++] = one.shift();
    }
  }
}

let a = [1, 8, 3, 2, 2, 7, 9, 5];
radixSort(a);

console.log(a);
