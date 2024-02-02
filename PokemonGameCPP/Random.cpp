#include "Random.h"
#include <random>

static int RangeInt(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min, max);

	return dist(gen);
}
static float RangeFloat(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<float> dist(min, max);

	return dist(gen);
}
static double RangeDouble(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<double> dist(min, max);

	return dist(gen);
}
static size_t RangeSizeT(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> dist(min, max);

	return dist(gen);
}
