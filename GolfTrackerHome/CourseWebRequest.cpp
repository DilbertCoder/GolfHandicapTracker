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
#include "CourseWebRequest.h"

#include <QDebug>
#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QXmlQuery>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CourseWebRequest::CourseWebRequest(QObject *parent) :
    QObject(parent),
    m_UsgaCourseWebPage("https://ncrdb.usga.org/NCRDB/courseTeeInfo.aspx?CourseID=%0%1%2%3%4")
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CourseWebRequest::OnNetworkManagerFinished()
{
    //    QString httpResults = QString(m_UsgaReply->readLine());

    //    while(!httpResults.isEmpty())
    //    {
    //        if(httpResults.contains("gvTee"))
    //        {
    //            qDebug() << "Found start of table";
    //        }

    //        httpResults = QString(m_UsgaReply->readLine());
    //    }
    //    QString noWhiteSpace = httpResults.simplified();

    //    if(noWhiteSpace.contains("gvTee"))
    //    {
    //        int tableLocation = noWhiteSpace.indexOf("gvTee");
    //    }
    //    QString tableLine = httpResults.at(tableLocation);
}
