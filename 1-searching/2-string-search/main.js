function stringSearchNaive(str, needle) {
  for (let i = 0; i < str.length - needle.length + 1; ++i) {
    let found = true;
    for (let j = 0; j < needle.length; ++j) {
      if (str[i + j] != needle[j]) {
        found = false;
        break;
      }
    }
    if (found) {
      return i;
    }
  }
  return -1;
}

console.log(stringSearchNaive('sahil', 'hil'));
console.log(stringSearchNaive('sahil', 'hal'));
