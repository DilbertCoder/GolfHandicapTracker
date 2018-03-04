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
#include "UpdateCourseDataThread.h"

#include <QTimer>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QApplication>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UpdateCourseDataThread::UpdateCourseDataThread(QObject *parent) :
    QObject(parent),
    m_UsgaCourseWebPage("https://ncrdb.usga.org/NCRDB/courseTeeInfo.aspx?CourseID=%0%1%2%3%4"),
    m_UsgaReply(nullptr),
    m_CourseIdOne(0),
    m_CourseIdTwo(0),
    m_CourseIdThree(5),
    m_CourseIdFour(2),
    m_CourseIdFive(5)
{
    //Currently there are not courses below 00525
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UpdateCourseDataThread::~UpdateCourseDataThread()
{
    if(m_UsgaReply != nullptr)
    {
        m_UsgaReply->abort();
        m_UsgaReply->deleteLater();
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void UpdateCourseDataThread::StopUpdate()
{
    if(m_UsgaReply != nullptr)
    {
        m_UsgaReply->abort();
        m_UsgaReply->deleteLater();
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void UpdateCourseDataThread::StartUpdate()
{
    if(m_UsgaReply == nullptr)
    {
        QTimer::singleShot(100, this, SLOT(OnInitilizeThread()));
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void UpdateCourseDataThread::OnInitilizeThread()
{
    //02258 10510
    m_UsgaSearchUrl = QUrl(m_UsgaCourseWebPage.arg(m_CourseIdOne)
                                              .arg(m_CourseIdTwo)
                                              .arg(m_CourseIdThree)
                                              .arg(m_CourseIdFour)
                                              .arg(m_CourseIdFive));

    if(m_UsgaSearchUrl.isValid())
    {
        try
        {
            m_UsgaReply = m_NetworkManager.get(QNetworkRequest(m_UsgaSearchUrl));

            connect(m_UsgaReply,
                    SIGNAL(finished()),
                    this,
                    SLOT(OnNetworkManagerFinished()));
        }
        catch(...)
        {
            qDebug() << "Failed Network Manager";
        }
    }
    else
    {
        qDebug() << "URL is Invalid: " << m_UsgaSearchUrl.url();
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void UpdateCourseDataThread::OnNetworkManagerFinished()
{
    QString httpResults = QString(m_UsgaReply->readAll());

    if(httpResults.contains("Club/Course Name"))
    {
        QString dataFileName = QString(QApplication::applicationDirPath() + "/CourseData/Course%0%1%2%3%4.txt").arg(m_CourseIdOne)
                                                                                                               .arg(m_CourseIdTwo)
                                                                                                               .arg(m_CourseIdThree)
                                                                                                               .arg(m_CourseIdFour)
                                                                                                               .arg(m_CourseIdFive);

        QFile courseData(dataFileName);
        if(courseData.open(QFile::WriteOnly))
        {
//            <td style="width:50%;">Rolling Hills CC</td><td>Monroe</td><td align="center">NC</td>
            int clubLoc = httpResults.indexOf("Club/Course Name");
            int courseNameLoc = httpResults.indexOf("50",clubLoc);
            int endCouseNameLoc = httpResults.indexOf("<", courseNameLoc);
            int courseNameSize = endCouseNameLoc - (courseNameLoc + 6);
            int countyNameEnd = httpResults.indexOf("</td>",endCouseNameLoc+1 );
            int countyNameSize = countyNameEnd - (endCouseNameLoc + 8);

            QJsonObject dataObject;
            dataObject.insert("CourseID", QString("%0%1%2%3%4").arg(m_CourseIdOne)
                                                               .arg(m_CourseIdTwo)
                                                               .arg(m_CourseIdThree)
                                                               .arg(m_CourseIdFour)
                                                               .arg(m_CourseIdFive));

            dataObject.insert("CourseName",httpResults.mid(courseNameLoc +6, courseNameSize));

            dataObject.insert("County",httpResults.mid(endCouseNameLoc + 9, countyNameSize -1));

            dataObject.insert("State",httpResults.mid(countyNameEnd + 24, 2));

            QJsonDocument outputJson(dataObject);

            courseData.write(outputJson.toJson());

            courseData.close();
        }
    }

    disconnect(m_UsgaReply,
               SIGNAL(finished()),
               this,
               SLOT(OnNetworkManagerFinished()));

    m_UsgaReply->deleteLater();
    m_UsgaReply = nullptr;

    UpdateCourseId();

    QTimer::singleShot(1000, this, SLOT(OnInitilizeThread()));
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void UpdateCourseDataThread::UpdateCourseId()
{
    if(m_CourseIdFive == 9)
    {
        m_CourseIdFive = 0;
        ++m_CourseIdFour;
        if(m_CourseIdFour == 10)
        {
            m_CourseIdFour = 0;
            ++m_CourseIdThree;
            if(m_CourseIdThree == 10)
            {
                m_CourseIdThree = 0;
                ++m_CourseIdTwo;
                if(m_CourseIdTwo == 10)
                {
                    m_CourseIdTwo = 0;
                    ++m_CourseIdOne;
                    if(m_CourseIdOne == 10)
                    {
                        return;
                    }
                }
            }
        }
    }
    else
    {
        ++m_CourseIdFive;
    }
}
