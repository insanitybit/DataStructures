#include <iostream>
#include "Vector.h"
// #include <vector>
#include <chrono>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;

	start = std::chrono::steady_clock::now();



	Vector<size_t> vec(5000000);
	// vector<size_t> vec;

	// const int32_t seed = 50;
	// srand(seed);

	size_t count = 50000000;
	// size_t val = 501;

	for (size_t i = 0; i < count; i++) {
		vec.push_back(std::move(i));
	}


	end = std::chrono::steady_clock::now();
	elapsed_seconds = end-start;
	cout << "5m push_back::  " << elapsed_seconds.count() * 1000 << "ms" << endl;


	// start = std::chrono::steady_clock::now();

	// // bool found = vec.contains(100);
	// auto found = std::find(std::begin(vec), std::end(vec), 100);

	// end = std::chrono::steady_clock::now();
	// elapsed_seconds = end-start;
	// cout << "contains::  " << elapsed_seconds.count() * 1000 << "ms" << endl;

	// cout << found << "\n";

	// std::vector<size_t> vec;

	// vec.set_growth_rate(1.5);

	// for (size_t i = 0; i < 10; ++i)
	// {
	// 	vec.push_back(i);
	// 	cout << vec[i] << endl;
	// }

	// Vector<size_t> v(move(vec));


	// for (size_t i = 0; i < v.size(); ++i)
	// {
	// 	cout << v[i] << endl;
	// }


	// end = std::chrono::steady_clock::now();
	// elapsed_seconds = end-start;
	// cout << "10k push_back::  " << elapsed_seconds.count() * 1000 << "ms" << endl;


	// // cout << vec.capacity() << endl;
	// // cout << vec.size() << endl;

	// // cout << "wasted space:: " << (vec.capacity() - vec.size()) << endl;

	return 0;
}
