# Crabs
A language similar to BF but is designed to help those understand how a Turing machine works.

## Language design
| Char | Meaning						|
|------|--------------------------------|
| `>`  | Increment the data pointer		|
| `<`  | Decrement the data pointer		|
| `+`  | Increment at memory block		|
| `-`  | Decrement at memory block		|
| `0`  | Sets current memory block to 0	|
| `o`  | Outputs the memory block 		|
| `i`  | Accepts 4 bytes and stores it in the current memory block|
| `c`  | If current memory block is 0, skip to next `ab`. If memory block is 0, continue with execution |
| `b`  | searches code above the instruction immediately above for a `cr` and jumps to it |