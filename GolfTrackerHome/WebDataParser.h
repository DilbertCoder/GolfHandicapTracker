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
#ifndef WEBDATAPARSER_H
#define WEBDATAPARSER_H

#include <QString>

#include <vector>

#include "WebDataItem.h"

//-----------------------------------------------------------------------------
//! \brief Object to parse the data from the USGA site
//
//! This class is responsable for parsing out the data from the USGA web
//! site for course info. This class takes in the complete HTTP requested
//! text
//-----------------------------------------------------------------------------
class WebDataParser
{
public:
    //-------------------------------------------------------------------------
    //!WebDataParser Constructor
    //! \param webData String of HTTP request from USGA Website
    //-------------------------------------------------------------------------
    WebDataParser(QString webData);

    bool IsValidWebData();

    bool ParseWebData();

private:
    //! Memeber to hold the parsed out data from the web
    std::vector<WebDataItem> m_ParsedData;

    //! Holds the data to be parsed
    const QString m_WebDataString;
};

#endif // WEBDATAPARSER_H
