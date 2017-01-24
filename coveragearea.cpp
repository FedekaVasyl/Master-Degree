#include "coveragearea.h"

CoverageArea::CoverageArea()
{
    this->height = 1000;
    this->width = 1000;
}

int CoverageArea::GetHeight() const
{
    return this->height;
}

int CoverageArea::GetWidth() const
{
    return this->width;
}

void CoverageArea::SetHeight(int _height)
{
    this->height = _height;
}

void CoverageArea::SetWidth(int _width)
{
    this->width = _width;
}
