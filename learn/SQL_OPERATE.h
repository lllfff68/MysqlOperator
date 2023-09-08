#ifndef SQL_OPERATE_H
#define SQL_OPERATE_H

#include <mainwindow.h>
#include <QSqlDatabase>
#include <QVector>

struct PRIMARY_KEY_RESULT
{
    QString primary_key_name ;
    bool primary_key_exist;
};

class SQL
{
public:
    friend class MainWindow;

    struct CompareStruct
    {
        QString col_name;
        QString less_than;
        QString greater_than;
    };

    PRIMARY_KEY_RESULT CheckPrimaryKeyExist() const;
    bool CheckPrimaryKeyNotRepeated(QString primerKeyQuery, QString primerKeyInput) const;
    void CheckColunm();
    void InsertValue(QVector<QString> inputValueList);
    void DeleteValue(QVector<QVector<QString>> deleteRow);
    void ChangeData(QString changedValue, int changedColmun);
    QSqlQuery QueryData(QVector<CompareStruct> compList, int count);

private:
    int column_count;
    QVector<QString> column_names;
    QVector<QString> column_types;
    QString tableName = "student";
    QVector<QString> selectDataList;
    QVector<QString> tableList;

};


#endif // SQL_OPERATE_H
