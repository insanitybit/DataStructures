#include "BST.h"
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{

	const size_t count = 5000;
	const int32_t seed = 50;
	size_t val = 100;

	BST<size_t> b;

	srand(seed);

	for (size_t i = 0; i < count; i++) {
		val = (rand() % count);
		b.insert(val);
	}

	for (size_t i = 0; i < count; i++) {
		val = (rand() % count) + 1;
		b.find(val);
	}


	return 0;
}
