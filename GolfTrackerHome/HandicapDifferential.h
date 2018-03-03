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
#ifndef HANDICAPDIFFERENTIAL_H
#define HANDICAPDIFFERENTIAL_H

//-----------------------------------------------------------------------------
// Class to calculate and hold the Handicap Differential for a score entered
// for a given round.
// Required information for this class:
// 1. Adjusted Gross Score (AGS)
// 2. USGA Course Rating (UCR)
// 3. Slope Rating (SR)
// 4. 113 (The Slope Rating of a standard diffcutly cource)
// ----------------------------------------------------------------------------
class HandicapDifferential
{
public:
    explicit HandicapDifferential(double score, double rating, double slope);

    double GetHandicapDifferential() const;

private:
    const double m_StandardSlopeRating;

    const double m_AdjustedGrossScore;
    const double m_UsgaCourceRating;
    const double m_CourseSlopRating;
};

#endif // HANDICAPDIFFERENTIAL_H
