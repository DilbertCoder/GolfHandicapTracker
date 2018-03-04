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
#ifndef UPDATECOURSEDATATHREAD_H
#define UPDATECOURSEDATATHREAD_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>

//-----------------------------------------------------------------------------
//! \brief Thread to update course data localy
//
//! This class will update the USGA Course informtion need for this application
//! locally on this machine.
//! TODO: Maybe push this to a site somewhere?
//-----------------------------------------------------------------------------
class UpdateCourseDataThread : public QObject
{
    Q_OBJECT
public:
    explicit UpdateCourseDataThread(QObject *parent = nullptr);
    ~UpdateCourseDataThread();

    void StopUpdate();

    void StartUpdate();

protected slots:
    void OnInitilizeThread();

    void OnNetworkManagerFinished();

protected:
    void UpdateCourseId();

private:
    const QString m_UsgaCourseWebPage;

    QUrl m_UsgaSearchUrl;
    QNetworkAccessManager m_NetworkManager;
    QNetworkReply* m_UsgaReply;

    uint m_CourseIdOne;
    uint m_CourseIdTwo;
    uint m_CourseIdThree;
    uint m_CourseIdFour;
    uint m_CourseIdFive;
};

#endif // UPDATECOURSEDATATHREAD_H
