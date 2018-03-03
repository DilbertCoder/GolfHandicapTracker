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
