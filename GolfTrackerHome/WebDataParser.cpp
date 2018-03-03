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
#include "WebDataParser.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
WebDataParser::WebDataParser(QString webData) : m_WebDataString(webData)
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool WebDataParser::IsValidWebData()
{
    //If the web request has this string in it then it is valid and can be
    //parsed
    return m_WebDataString.contains("gvTee");
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool WebDataParser::ParseWebData()
{
    bool parseSuccessful = false;

    //Lets remove some of the blank space from the strings
    QString simplifiedString = m_WebDataString.simplified();

    int locationOfgvTee = simplifiedString.indexOf("gvTee");

    if(locationOfgvTee == -1) return parseSuccessful;



    return parseSuccessful;
}
