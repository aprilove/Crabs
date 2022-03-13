# Crabs
A language designed to help those understand how a Turing machine works with many ideas borrowed from BF.

- [x] Finish interpreter
- [ ] Finish compiler
- [ ] Add QOL characters

## Language design
| Char | Meaning						|
|------|--------------------------------|
| `>`  | Increment the data pointer		|
| `<`  | Decrement the data pointer		|
| `+`  | Increment at memory block		|
| `-`  | Decrement at memory block		|
| `0`  | Sets current memory block to 0	|
| `r`  | Sets current memory block to 0x7FFFFFFF	|
| `o`  | Outputs the memory block 		|
| `s`  | Swaps memory block with next memory block 		|
| `i`  | Accepts 4 bytes and stores it in the current memory block|
| `c`  | If current memory block is 0, skip to next `b`. If memory block is 0, continue with execution |
| `b`  | searches code above the instruction immediately above for a `c` and jumps to it |

## Sample Code
### Decrement and Increment 
`c->+<b`

### Hello World
`++++++++c>++++c>++>+++>+++>+<<<<-b>+>+>->>+c<b<-b>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.`
