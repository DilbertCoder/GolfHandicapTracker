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
//-----------------------------------------------------------------------------
// This class will request the Course information from the USGA website
//-----------------------------------------------------------------------------
#ifndef COURSEWEBREQUEST_H
#define COURSEWEBREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class CourseWebRequest : public QObject
{
    Q_OBJECT
public:
    explicit CourseWebRequest(QObject *parent = nullptr);

signals:

protected slots:
    void OnNetworkManagerFinished();

protected:
    void UpdateCourseId();

private:
    QString m_UsgaCourseWebPage;

    QUrl m_UsgaSearchUrl;
    QNetworkAccessManager m_NetworkManager;
    QNetworkReply* m_UsgaReply;

    uint m_CourseIdOne;
    uint m_CourseIdTwo;
    uint m_CourseIdThree;
    uint m_CourseIdFour;
    uint m_CourseIdFive;
};

#endif // COURSEWEBREQUEST_H
