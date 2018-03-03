//-----------------------------------------------------------------------------
//Golf Tracker Home
//Copyright (C) 2018 DilbertCoder
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------------
#ifndef WEBDATAITEM_H
#define WEBDATAITEM_H

//-----------------------------------------------------------------------------
//! \brief Course Data Object
//
//! This class will hold onto the parsed data from the USGA course web site
//-----------------------------------------------------------------------------
class WebDataItem
{
public:
    enum TeeGender
    {
        MALE,
        FEMALE
    };

    enum TeeColor
    {
        RED,
        WHITE,
        GREEN,
        BLUE
    };

    WebDataItem(TeeGender gender, TeeColor color, double courseRating, int slopeRating);

private:
    TeeGender m_Gender;

    TeeColor m_Color;

    double m_CourseRating;

    int m_SlopeRating;
};

#endif // WEBDATAITEM_H
