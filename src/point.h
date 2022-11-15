﻿#pragma once

template <typename T>
struct Point {
	T x{0}, y{0};
};


template <typename T>
struct Rect {
	T x{ 0 }, y{ 0 }, w{ 0 }, h{ 0 };

	Point <T> getXY()
	{
		return { x,y };
	}

	Point <T> getWH()
	{
		return { w,h };
	}

	void setXY(Point <T> input)
	{
		x = input.x;
		y = input.y;
	}

	void setWH(Point <T> input)
	{
		w = input.x;
		h = input.y;
	}

	T addXW()
	{
		return x + w;
	}

	T addYH()
	{
		return y + h;
	}

	void printXY()
	{
		std::cout << "x:" << x << " y:" << y << "\n";
	}

	void printRect()
	{
		std::cout << "x:" << x << " y:" << y << " w:" << w << " h:" << h << "\n";
	}
};
