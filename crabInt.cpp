#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>

// a vector to store the program
std::vector<char> program;

// Memory tape
std::vector<int> memory = {0};

// pointers/iterators
// Stack pointer
auto p_memory = memory.begin();
// Tracks program location 
auto p_program = program.begin();

// Error messages
void quit(bool error) {
	if (error) {
		std::cout << "\nError at " << *p_program << *(++p_program) << "\n";
		exit(1);
	} else {
		std::cout << "\nDone\n";
		exit(0);
	}
}

// Interpretor
bool instruction(char input) {
	switch (input) {
		// Decrement memory pointer
		case '<':
			if (p_memory == memory.begin())
				quit(true);
			else
				--p_memory;
			break;
		// Increment memory pointer
		case '>':
			if (p_memory == memory.end())
				quit(true);
			else
				++p_memory;
			break;
		// Increment memory block
		case '+':
			++(*p_memory);
			break;
		// Decrement memory block
		case '-':
			--(*p_memory);
			break;
		case '0':
		// Set memory block to 0
			*p_memory = 0;
			break;
		// Set memory block to 0x7FFFFFFF
		case 'r':
			*p_memory = INT32_MAX;
			break;
		// Output
		case 'o':
			std::cout << *p_memory << "\n";
			break;
		// Swap with next memory block
		case 's':
			auto temp = *(p_memory);
			*p_memory = *(++p_memory);
			++p_memory;
			*p_memory = temp;
			--p_memory;
			break;
		// Accepts an input
		case 'i':
			std::cin >> *p_memory;
			break;
		case 'c':
		// Loop "while(*ptr){"
			if (*p_memory == 0) {
				int level = 0;
				while (1) {
					if (p_program == program.end())
						quit(true);
					else
						++p_program;
					if (*p_program == 'c') ++level;
					if (*p_program == 'b')
						if (!level)
							break;
						else
							--level;
				}
			}
			break;
		// Loop "}"
		case 'b':
			if (!(*p_memory == 0)) {
				int level = 0;
				while (1) {
					if (p_program == program.begin())
						quit(true);
					else
						--p_program;
					if (*p_program == 'b') ++level;
					if (*p_program == 'c')
						if (!level)
							break;
						else
							--level;
				}
			}
			break;
		// If the end is reached
		default:
			quit(false);
			break;
	}
	// Increment program pointer
	++p_program;

	return true;
}

int main(int argc, char** argv) {
	// Opens file
	FILE* f = fopen(argv[1], "rb");
	if (f == NULL) {
		std::cout << "Cannot open\n";
		exit(1);
	}

	// Buffer to read file
	char buffer;
	int pos = 0;

	// Continues to read file till EOF
	while (!feof(f)) {
		// Reads character and determines whether it is a valid character or
		// not. This means ALL other characters are comments and that comments
		// cannot Have the following characters in them. E.g. "Hell" is a valid
		// comment But "Hello" is not a valid comment as it contains the
		// character 'o'
		buffer = fgetc(f);
		if (buffer == '>' || buffer == '<' || buffer == '+' || buffer == '-' ||
			buffer == '0' || buffer == 'r' || buffer == 'o' || buffer == 's' ||
			buffer == 'i' || buffer == 'c' || buffer == 'b')
			// Interprets program
			program.push_back(buffer);
	}

	// Close file
	fclose(f);

	// Runs through program
	while (p_program != program.end())
		if (!instruction(*p_program)) break;

	quit(false);
	return 0;
}