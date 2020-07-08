function quickSort(arr, l, r) {
  if (l == undefined) {
    l = 0;
  }

  if (r == undefined) {
    r = arr.length - 1;
  }

  if (l >= r) {
    return;
  }

  let pivot = Math.floor((Math.random() * (r - l + 1))) + l;
  let x = arr[r];
  [arr[pivot], arr[r]] = [arr[r], arr[pivot]];

  let j = l;

  for (let i = l; i <= r; ++i) {
    if (arr[i] < x) {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      j++;
    }
  }

  [arr[r], arr[j]] = [arr[j], arr[r]];
  quickSort(arr, l, j - 1);
  quickSort(arr, j + 1, r);
}

let a = [1, 8, 3, 2, 2, 7, 9, 5];
quickSort(a);

console.log(a);
