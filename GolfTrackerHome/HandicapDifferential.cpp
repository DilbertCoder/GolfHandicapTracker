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
#include "HandicapDifferential.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandicapDifferential::HandicapDifferential(double score,
                                           double rating,
                                           double slope) :
    m_StandardSlopeRating(113.0),
    m_AdjustedGrossScore(score),
    m_UsgaCourceRating(rating),
    m_CourseSlopRating(slope)
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
double HandicapDifferential::GetHandicapDifferential() const
{
    double difference = m_AdjustedGrossScore - m_UsgaCourceRating;
    double slopeDifference = difference * m_StandardSlopeRating;
    double differenctial = slopeDifference / m_CourseSlopRating;

    return differenctial;
}
