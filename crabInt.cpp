#include <stdio.h>

#include <cstring>
#include <iostream>
#include <vector>

std::vector<char> program;
std::vector<int> memory = {0};

auto p_memory = memory.begin();
auto p_program = program.begin();

void quit(bool error) {
	if (error) {
		std::cout << "\nError\n";
		exit(1);
	} else {
		std::cout << "\nDone\n";
		exit(0);
	}
}

bool instruction(char input) {
	switch (input) {
		case '<':
			if (p_memory == memory.begin())
				quit(true);
			else
				--p_memory;
			break;
		case '>':
			if (p_memory == memory.end())
				quit(true);
			else
				++p_memory;
			break;
		case '+':
			++(*p_memory);
			break;
		case '-':
			--(*p_memory);
			break;
		case '0':
			*p_memory = 0;
			break;
		case 'r':
			*p_memory = INT32_MAX;
			break;
		case 'o':
			std::cout << *p_memory << "\n";
			break;
		case 'i':
			std::cin >> *p_memory;
			break;
		case 'c':
			if (*p_memory == 0) {
				// code
			}
			break;
		case 'b':
			if (p_program == program.begin())
				quit(true);

			--p_program;
			break;
		default:
			quit(false);
			break;
	}
	++p_program;

	return true;
}

int main(int argc, char** argv) {
	FILE* f = fopen(argv[1], "rb");
	if (f == NULL) {
		std::cout << "Cannot open\n";
		exit(1);
	}

	char buffer;
	int pos = 0;

	while (!feof(f)) {
		buffer = fgetc(f);
		if (buffer == '>' || buffer == '<' || buffer == '+' || buffer == '-' ||
			buffer == '0' || buffer == 'o' || buffer == 'i' || buffer == 'c' ||
			buffer == 'b') {
			program.push_back(buffer);
		}
	}
	fclose(f);

	return 0;
}