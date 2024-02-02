#pragma once


class Random
{
public:
	static int RangeInt(int min, int max);
	static float RangeFloat(int min, int max);
	static double RangeDouble(int min, int max);
	static size_t RangeSizeT(int min, int max);
};

