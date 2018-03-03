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
