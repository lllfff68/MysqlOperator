#include <SQL_OPERATE.h>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlIndex>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>

PRIMARY_KEY_RESULT SQL::CheckPrimaryKeyExist() const
{
    PRIMARY_KEY_RESULT primary_key_result;
    QSqlQuery query;
    query.exec("SHOW KEYS FROM " + tableName + " WHERE Key_name = 'PRIMARY'");
    query.next();
    QSqlRecord record = query.record();
    int columnIndex = record.indexOf("Column_name");
    QString primaryKey = query.value(columnIndex).toString();


    if (primaryKey.isEmpty())
    {
         qDebug() << "没有找到主键！";
        // 建议设置主键 不需要判断主键是否重复
         primary_key_result.primary_key_name = "";
         primary_key_result.primary_key_exist = false;
    }
    else
    {
        primary_key_result.primary_key_name = primaryKey;
        primary_key_result.primary_key_exist = true;
    }

    return primary_key_result;
}

bool SQL::CheckPrimaryKeyNotRepeated(QString primerKeyQuery, QString primerKeyInput) const
{
    // 对比输入user_input和已经存在的主键是否重复，重复则报错

    // 这个输入需要通过弹窗获取
    QSqlQuery query;
    query.exec("select " + primerKeyQuery + " from " + tableName);
    while(query.next())
    {
        if (primerKeyInput == query.value(0).toString())
        {
            qDebug() << "输入主键和表中主键重复！";
            return false;
        }
    }
    return true;
}

// 查询所有列的信息
void SQL::CheckColunm()
{
    QSqlQuery query;
    QString senctence = "show columns from " + tableName;
    if (query.exec(senctence))
    {
        column_count = 0;
        column_names.clear();
        column_types.clear();
        while (query.next())
        {
            column_names.append(query.value("Field").toString());
            column_types.append(query.value("Type").toString());
            column_count++;
        }
    }
    else
    {
        qDebug() << "语句执行失败：" + senctence;
    }
}

// insert into student (id, name, score) values (100,1,1);
void SQL::InsertValue(QVector<QString> inputValueList)
{

    QSqlQuery query;
    QString scentence = "insert into " + tableName + "(";
    for (int i = 0; i < inputValueList.size(); i++)
    {
        scentence += column_names.at(i);
        if (i == inputValueList.size()-1)
        {
            continue;
        }
        else
        {
            scentence += ", ";
        }
    }
    scentence += ") values (";
    for (int i = 0; i < inputValueList.size(); i++)
    {
        scentence += "?";
        if (i == inputValueList.size()-1)
        {
            continue;
        }
        else
        {
            scentence += ", ";
        }
    }
    scentence += ")";
    query.prepare(scentence);
    for (int i = 0; i < inputValueList.size(); i++)
    {
        if (inputValueList.at(i) != "")
            query.bindValue(i, inputValueList.at(i));
        else
            query.bindValue(i, QVariant(QVariant::String));
    }

    if (!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "添加成功！ " + scentence;
}

void SQL::DeleteValue(QVector<QVector<QString>> deleteRow)
{
    for (int count = 0; count < deleteRow.size(); count++)
    {
        QSqlQuery query;
        QString scentence = "delete from " + tableName + " where ";
        for (int i = 0; i < column_count; i++)
        {
            if (deleteRow.at(count).at(i) != "null")
                scentence += column_names.at(i) + "=?";
            else
                scentence += column_names.at(i) + " is NULL";
            if (i != column_count-1) scentence += " and ";
            else break;
        }
        query.prepare(scentence);
        for (int i = 0, mark = 0; i < column_count; i++)
        {
            if (deleteRow.at(count).at(i) != "null")
            {
                query.bindValue(mark,deleteRow.at(count).at(i));
                mark++;
            }
        }
        if (!query.exec())
            qDebug() << query.lastError();
        else
            qDebug() << "删除成功！ " + scentence;

    }
}

void SQL::ChangeData(QString changedValue, int changedColmun)
{
    QSqlQuery query;
    QString scentence = "update " + tableName + " set " + column_names.at(changedColmun);
    if (changedValue.isEmpty())
    {
        scentence += "=null where ";
        QVector<int> bind_count;
        for (int i = 0, count = 0, and_count = 0; i < column_count; i++)
        {
            if (i != changedColmun)
            {
                if (selectDataList.at(i) == "null" || selectDataList.at(i).isNull() || selectDataList.at(i).isEmpty())
                    scentence += column_names.at(i) + " is null";
                else
                {
                    if (column_types.at(i).startsWith("char"))
                    {
                        scentence += column_names.at(i) + "=?";
                        bind_count.append(i);
                    }
                    else
                        scentence += column_names.at(i) + "=" + selectDataList.at(i);

                    count++;
                }

                if (and_count < column_count-2)
                {
                    scentence += " and ";
                    and_count++;
                }
            }
        }
        qDebug() << scentence;
        query.prepare(scentence);
        for (int i =0; i < bind_count.size(); i++)
        {
            query.bindValue(i, selectDataList.at(bind_count.at(i)));
        }
        if (!query.exec())
            qDebug() << query.lastError();
        else
            qDebug() << "修改成功！ " + scentence;
    }

    // 不知道为什么改为空值时会说缺少绑定的值，不要乱动
    else
    {
        scentence += "=? where ";

        for (int i = 0, count = 0; i < column_count; i++)
        {
            if (i != changedColmun)
            {
                if (selectDataList.at(i) == "null" || selectDataList.at(i).isNull() || selectDataList.at(i).isEmpty())
                    scentence += column_names.at(i) + " is null";
                else
                    scentence += column_names.at(i) + "=?";

                if (count < column_count-2)
                {
                    scentence += " and ";
                    count++;
                }
            }
        }
        query.prepare(scentence);

        if (changedValue != "")
        {
            query.bindValue(0, changedValue);
        }

        for (int i = 0, count = 1;  i < column_count; i++)
        {
            if (i != changedColmun)
            {
                if (selectDataList.at(i) == "null" || selectDataList.at(i).isNull() || selectDataList.at(i).isEmpty())
                {
                    query.bindValue(count, QVariant(QVariant::String));
                    count++;
                }
                else
                {
                    query.bindValue(count, selectDataList.at(i));
                    count++;
                }
            }
        }
        if (!query.exec())
            qDebug() << query.lastError();
        else
            qDebug() << "修改成功！ " + scentence;
    }
}

QSqlQuery SQL::QueryData(QVector<CompareStruct> compList, int valueCount)
{
    QSqlQuery query;
    QString scentence;
    scentence = "select * from " + tableName + " where ";
    qDebug() << valueCount;
    valueCount--;
    for (int i = 0; i < compList.size(); i++)
    {
        qDebug() << compList.at(i).col_name << compList.at(i).less_than << compList.at(i).greater_than;
        if(!compList.at(i).less_than.isEmpty())
        {
            scentence += compList.at(i).col_name + ">" + compList.at(i).less_than;
            if (valueCount)
            {
                scentence += " and ";
                valueCount--;
            }
        }
        if(!compList.at(i).greater_than.isEmpty())
        {
            scentence += compList.at(i).col_name + "<" + compList.at(i).greater_than;
            if (valueCount)
            {
                scentence += " and ";
                valueCount--;
            }
        }
    }
    qDebug() << scentence;
    if (!query.exec(scentence))
        qDebug() << query.lastError();
    else
        qDebug() << "查询成功！ " + scentence;
    return query;
}
