#include "qdjangoorm.h"

#include "qdjango/src/db/QDjango.h"
#include "qdjango/src/db/QDjangoModel.h"

QDjangoORM::QDjangoORM(QObject *parent):
    QObject(parent)
{
    this->m_dbDriver = QLatin1String("QSQLITE");
}

QDjangoORM::~QDjangoORM()
{
}

void QDjangoORM::classBegin()
{

}

void QDjangoORM::componentComplete()
{
    if(!this->m_dbName.isEmpty()){
        this->setDb(this->m_dbName,this->m_dbDriver);
    }

}

void QDjangoORM::setDb(const QString &dbName, const QString &dbDriver)
{
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(dbDriver);
        db.setDatabaseName(dbName);
        db.open();
        QDjango::setDatabase(db);
    }
}

bool QDjangoORM::createTables()
{
    return QDjango::createTables();
}

bool QDjangoORM::dropTables()
{
    return QDjango::dropTables();
}

bool QDjangoORM::isDebugEnabled()
{
    return  QDjango::isDebugEnabled();
}

void QDjangoORM::setDebugEnabled(bool enabled)
{
    QDjango::setDebugEnabled(enabled);
}

void QDjangoORM::test()
{
    QDjango::registerModel<QDjangoModel>();
    QDjango::createTables();
}
