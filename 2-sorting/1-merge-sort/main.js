function mergeSort(arr, l, r) {
  if (l == undefined) {
    l = 0;
  }

  if (r == undefined) {
    r = arr.length - 1;
  }

  if (l >= r) {
    return;
  }

  let m = Math.floor(l + (r - l) / 2);
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  let temp = arr.slice(l, r + 1);

  let i = l;
  let j = m + 1;
  let k = l;
  while (i <= m || j <= r) {
    let a = i <= m ? temp[i - l] : Number.MAX_SAFE_INTEGER;
    let b = j <= r ? temp[j - l] : Number.MAX_SAFE_INTEGER;

    if (a < b) {
      arr[k++] = temp[i++ - l];
    } else {
      arr[k++] = temp[j++ - l];
    }
  }
}

let a = [1, 8, 3, 2, 2, 7, 9, 5];
mergeSort(a);

console.log(a);
