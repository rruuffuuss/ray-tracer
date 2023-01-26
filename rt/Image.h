#pragma once
#include <vector>
#include "Colour.h"

class Image {
public:
	Image(int width, int height);
	~Image();

	Colour GetColour(int x, int y) const;
	void setColour(const Colour& colour, int x, int y);

	void Export(const char* path) const;
private:
	int m_width;
	int m_height;
	std::vector<Colour> m_colours;
};