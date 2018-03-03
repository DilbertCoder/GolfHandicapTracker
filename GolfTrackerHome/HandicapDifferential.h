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
