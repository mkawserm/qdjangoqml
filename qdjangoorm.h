#ifndef QDJANGOORM_H
#define QDJANGOORM_H

#include <QObject>

class QDjangoORM : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QDjangoORM)

public:
    QDjangoORM(QObject *parent = Q_NULLPTR);
    ~QDjangoORM();
};

#endif // QDJANGOORM_H
