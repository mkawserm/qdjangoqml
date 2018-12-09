#ifndef QDJANGOORM_H
#define QDJANGOORM_H

#include <QObject>
#include <QSqlDatabase>
#include <QQmlParserStatus>

class QDjangoORM : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_DISABLE_COPY(QDjangoORM)

    Q_PROPERTY(QString dbName READ dbName WRITE setDbName NOTIFY dbNameChanged)
    Q_PROPERTY(QString dbDriver READ dbDriver WRITE setDbDriver NOTIFY dbDriverChanged)

private:
    QString m_dbName;
    QString m_dbDriver;

public:
    Q_INVOKABLE QDjangoORM(QObject *parent = Q_NULLPTR);
    ~QDjangoORM();

    void classBegin();
    void componentComplete();


    QString dbName() const
    {
        return m_dbName;
    }

    QString dbDriver() const
    {
        return m_dbDriver;
    }

public slots:
    void setDb(const QString &dbName, const QString &dbDriver = QLatin1String("QSQLITE"));
    bool createTables();
    bool dropTables();
    bool isDebugEnabled();
    void setDebugEnabled(bool enabled);

    void test();

    void setDbName(const QString &dbName)
    {
        if (m_dbName == dbName)
            return;

        m_dbName = dbName;
        emit dbNameChanged(m_dbName);
    }

    void setDbDriver(const QString &dbDriver)
    {
        if (m_dbDriver == dbDriver)
            return;

        m_dbDriver = dbDriver;
        emit dbDriverChanged(m_dbDriver);
    }


signals:
    void dbNameChanged(const QString &dbName);
    void dbDriverChanged(const QString &dbDriver);
};

#endif // QDJANGOORM_H
