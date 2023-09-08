#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SQL_OPERATE.h"
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QTableView>
#include <QStringList>
#include <QVector>
#include <QItemDelegate>

#include <QTableView>
#include <QKeyEvent>

SQL sql;
PRIMARY_KEY_RESULT premary_key_result;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->localhost->setMaxLength(5);
    ui->username->setMaxLength(16);
    ui->passwd->setMaxLength(16);
    ui->passwd->setEchoMode(QLineEdit::Password);

//    ui->IP->setText("127.0.0.1");
//    ui->localhost->setText("3306");
//    ui->username->setText("root");
//    ui->passwd->setText("root");
//    ui->DBname->setText("test");

    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList list = QSqlDatabase::drivers();
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    //QSqlDatabase DB = QSqlDatabase::addDatabase("QODBC");

    connect(ui->connectButton, &QPushButton::clicked, this, [=](){connected(DB);});
    connect(ui->refreash, &QPushButton::clicked, this, &MainWindow::refreash);
    connect(ui->addbutton, &QPushButton::clicked, this, &MainWindow::add_data);
    connect(ui->deletebutton, &QPushButton::clicked, this, &MainWindow::DeleteData);
    connect(ui->changebutton, &QPushButton::clicked, this, &MainWindow::ChangeData);
    connect(ui->table, &QTableView::clicked, this, &MainWindow::CatchTableViewMouseClick);
    connect(ui->table, &QTableView::activated, this, &MainWindow::CatchTableViewEnter);
    connect(ui->querybutton, &QPushButton::clicked, this, &MainWindow::QureyData);
    connect(ui->selectbox, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
            [&](int index) {
                    sql.tableName = ui->selectbox->itemText(index);
                    qDebug() << "Selected table: " << ui->selectbox->itemText(index);
                    refreash();
                });
}

MainWindow::~MainWindow()
{
    delete ui;
}


// 点击连接按钮触发动作
void MainWindow::connected(QSqlDatabase DB)
{
    if (ui->connectButton->text() == "连接")
    {
        qDebug() << "开始连接！";

        IP = ui->IP->text();
        localhost = ui->localhost->text();
        username = ui->username->text();
        passwd = ui->passwd->text();
        DBname = ui->DBname->text();

        qDebug() << "IP ： " << IP <<",  localhost： " << localhost << ",  username: " << username << ",  passwd: " << "????" << ",  DBname: " << DBname;

        DB.setHostName(IP);
        DB.setPort(localhost.toInt());
        DB.setUserName(username);
        DB.setPassword(passwd);
        DB.setDatabaseName(DBname);



        // 连接成功,弹出窗口，连接按钮变为断开连接
        if (DB.open())
        {
            SelectTable();
            //QMessageBox::information(this, "连接结果", "连接成功！");
            ui->connectButton->setText("断开连接");
            refreash();
        }

        // 连接失败，弹出窗口，保持不变
        else
        {
            qDebug() << "连接失败";
            QMessageBox::information(this, "连接结果", "连接失败！");
        }
    }

    else if (ui->connectButton->text() == "断开连接" )
    {
        // 触发断开连接
        DB.close();
        // 改变连接按钮
        ui->connectButton->setText("连接");
        refreash();
        QMessageBox::information(this, "连接结果", "连接断开！");
        qDebug() << "连接断开" ;
    }
}

void MainWindow::refreash()
{
    // 触发表格刷新
    QStandardItemModel *model = new QStandardItemModel(this);
    QSqlQuery query;
    query.exec("select * from " + sql.tableName);
    QSqlRecord record = query.record();
    QStringList headList;

    // 设置表头标题
//    model->setHorizontalHeaderLabels({record.fieldName(0), record.fieldName(1), record.fieldName(2)});
    for (int i =0; i < record.count(); i++)
    {
        headList.append(record.fieldName(i));
    }
    model->setHorizontalHeaderLabels(headList);
    // 添加数据
    while (query.next())
    {
//        model->appendRow({ new QStandardItem(query.value(0).toString()), new QStandardItem(query.value(1).toString()), new QStandardItem(query.value(2).toString()) });
        QList<QStandardItem*> valueList;
        for (int i =0; i < record.count(); i++)
        {
            if (!query.isNull(i))
                valueList.append(new QStandardItem(query.value(i).toString()));
            else
                valueList.append(new QStandardItem("null"));
        }
        model->appendRow(valueList);
    }
    // 创建QTableView并设置数据模型
    ui->table->setModel(model);
    // QMessageBox::information(this, "", "刷新！！！");
}

// 完成数据添加
void MainWindow::add_data()
{
    // 查询主键是否存在
    premary_key_result = sql.CheckPrimaryKeyExist();
    sql.CheckColunm();
    if (premary_key_result.primary_key_exist)
    {
        while(1)
        {
            // 得到输入的主键
            QString primerKeyInputData = inputPrimaryKeyData(premary_key_result.primary_key_name);
            if (primerKeyInputData == "")
            {
                qDebug() << "输入值不能为空！";
                break;
            }
            if (sql.CheckPrimaryKeyNotRepeated(premary_key_result.primary_key_name, primerKeyInputData))
            {
                // 不冲突则依次输入对应值
                qDebug() << "主键不冲突！";
                QVector<QString> inputValueList = inputValue(premary_key_result.primary_key_name, primerKeyInputData);
                sql.InsertValue(inputValueList);
                refreash();
                break;
            }
            else
            {
                qDebug() << "主键冲突,请重新输入！";
                QString primerKeyInputData = inputPrimaryKeyData(premary_key_result.primary_key_name);
                refreash();
            }
        }
    }
    else
    {
        // 直接弹窗输入value
        QVector<QString> inputValueList = inputValue(premary_key_result.primary_key_name, "");
        sql.InsertValue(inputValueList);
    }
}

QString MainWindow::inputPrimaryKeyData(QString PrimaryKeyName)
{
    // 弹出窗口要求输入主键
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("请输入主键");
    dialog->resize(300,200);
    // 创建一个布局管理器
    QVBoxLayout* layout = new QVBoxLayout(dialog);

    // 主键名称框
    QLabel* label = new QLabel(dialog);
    label->setText("主键为： " + PrimaryKeyName + "，输入添加数据的主键！");
    layout->addWidget(label);

    // 文本输入框
    QLineEdit* inputText = new QLineEdit(dialog);
    // 字体居中
    inputText->setAlignment(Qt::AlignCenter);
    inputText->setMinimumHeight(30);
    // 添加到布局管理器中
    layout->addWidget(inputText);

    // 按钮
    QPushButton* okButton = new QPushButton("确定", dialog);
    okButton->setMinimumHeight(20);
    layout->addWidget(okButton);

    // 设置布局管理器的对齐方式为居中
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setAlignment(Qt::AlignCenter);
    label->setAlignment(Qt::AlignLeft);

    // 当确定按钮被点击时，关闭弹出窗口
    connect(okButton, &QPushButton::clicked, dialog, &QDialog::accept);

    // 显示弹出窗口，并等待用户输入
    if (dialog->exec() == QDialog::Accepted)
    {
        QString userInput = inputText->text();
        statusBar()->showMessage("用户输入: " + userInput);
    }
    else
    {
        statusBar()->showMessage("用户取消输入");
    }
    QString userInput = inputText->text();
    connect(dialog, &QDialog::rejected, [=]()
    {
        delete dialog;
        return "";
    });
    // 释放弹出窗口的内存
    delete dialog;

    return userInput;
}

QVector<QString> MainWindow::inputValue(QString primerKeyName, QString primerKeyInput)
{
    // 弹出一个窗口，垂直布局，依次为kye：  value：  key:   value:
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("请输入主键");
    dialog->resize(300,500);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    // 创建容器分别存储对话框中的内容
    QVector<QLineEdit*> inputTextList;
    QVector<QString> inputValueList;
    // 多少个key多少个value
    for (int i = 0; i < sql.column_count; i++)
    {
        // 主键名称框
        QLabel* label = new QLabel(dialog);
        label->setText(sql.column_names.at(i));
        layout->addWidget(label);
        // 文本输入框
        QLineEdit* inputText = new QLineEdit(dialog);
        if ( primerKeyName == sql.column_names.at(i))
        {
            inputText->setText(primerKeyInput);
        }

        // 字体居中
        inputText->setAlignment(Qt::AlignCenter);
        inputText->setMinimumHeight(30);
        // 添加到布局管理器中
        layout->addWidget(inputText);
        layout->setAlignment(Qt::AlignCenter);
        label->setAlignment(Qt::AlignLeft);

        inputTextList.append(inputText);
    }

    // 按钮
    QPushButton* okButton = new QPushButton("确定", dialog);
    okButton->setMinimumHeight(20);
    layout->addWidget(okButton);
    layout->setContentsMargins(20, 20, 20, 20);

    connect(okButton, &QPushButton::clicked, dialog, &QDialog::accept);
    dialog->exec();

    // 得到输入值的list
    for (int i = 0; i < sql.column_count; i++)
    {
        inputValueList.append(inputTextList.at(i)->text());
    }

    delete dialog;
    return inputValueList;
}

void MainWindow::DeleteData()
{
    // 接收QTableView的数据
//    QItemSelectionModel* selectionModel = ui->table->selectionModel();
//    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();
    QAbstractItemModel* itemModel = ui->table->model();
    QModelIndexList selectedIndexes = ui->table->selectionModel()->selectedIndexes();
    sql.CheckColunm();
    if (!selectedIndexes.isEmpty()) {
        QVector<QVector<QString>> deleteRow;
        for(auto it = selectedIndexes.begin(); it != selectedIndexes.end(); it++)
        {
//            qDebug() << "Selected cell: " << it->row() << ", " << it->column();
//            qDebug() <<sql.column_count;
            QVector<QString> newRow;
            for (int i = 0; i < sql.column_count; i++)
            {
                QModelIndex itemIndex = itemModel->index(it->row(), i);
                QVariant data = itemIndex.data();
                newRow.append(data.toString());
            }
            deleteRow.append(newRow);
        }

        // 调用SQL函数
        sql.DeleteValue(deleteRow);
        refreash();
    }
}


// 直接在表格中修改, 则个函数负责放开和限制修改表格
void MainWindow::ChangeData()
{
    if (ui->changebutton->text() == "修改数据")
    {
        ui->changebutton->setText("修改完成");
        ui->table->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
    else
    {
        ui->changebutton->setText("修改数据");
        ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void MainWindow::CatchTableViewMouseClick()
{
    if (ui->changebutton->text() == "修改完成")
    {
//        qDebug() << "单击试试效果~~~~~~~~~~~~~~~~~~~~~~~";
        QAbstractItemModel* itemModel = ui->table->model();
        QModelIndexList selectedIndexes = ui->table->selectionModel()->selectedIndexes();
        sql.CheckColunm();
        if (!selectedIndexes.isEmpty())
        {
            QVector<QString> selectDataList;
            for (int i = 0; i< sql.column_count; i++)
            {
                selectDataList.append(itemModel->index(selectedIndexes.at(0).row(), i).data().toString());
//                qDebug() << itemModel->index(selectedIndexes.at(0).row(), i).data().toString();
            }
            sql.selectDataList = selectDataList;
//                qDebug() << "Selected cell: " << selectedIndexes.at(0).row() << ", " << selectedIndexes.at(0).column();
//                qDebug() << itemModel->index(selectedIndexes.at(0).row(), selectedIndexes.at(0).column()).data().toString();
//                sql.ChangeData();
        }
    }
}

void MainWindow::CatchTableViewEnter()
{
    if (ui->changebutton->text() == "修改完成")
    {
        qDebug() << "修改数据中~~~~~~~~~~~~~~~~~~~~~~~";
        QAbstractItemModel* itemModel = ui->table->model();
        QModelIndexList selectedIndexes = ui->table->selectionModel()->selectedIndexes();
        sql.CheckColunm();
        if (!selectedIndexes.isEmpty())
        {
            QVector<QString> dataList;
            int changedColmun = selectedIndexes.at(0).column();
            QString changedValue = itemModel->index(selectedIndexes.at(0).row(), selectedIndexes.at(0).column()).data().toString();
            for (int i = 0; i< sql.column_count; i++)
            {
                dataList.append(itemModel->index(selectedIndexes.at(0).row(), i).data().toString());
//                qDebug() << itemModel->index(selectedIndexes.at(0).row(), i).data().toString();
            }
//                qDebug() << "数据更改该为：" << changedValue;
//                qDebug() << "更改列数位置：" << changedColmun;
            sql.ChangeData(changedValue, changedColmun);
        }
    }
}

void MainWindow::QureyData()
{
    qDebug() << "查询数据！";
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("输入查询数据");
    dialog->resize(300,200);

    QVBoxLayout* vlayout = new QVBoxLayout(dialog);

    // 存放数据
    QVector<QPair<QLineEdit*, QLineEdit*>> values;
    QVector<QString> colNameList;
    sql.CheckColunm();
    for (int i = 0; i < sql.column_count; i++)
    {
        if (!sql.column_types.at(i).startsWith("char"))
        {
            QHBoxLayout* hlayout = new QHBoxLayout();
            QLineEdit* less_than = new QLineEdit(dialog);
            QLineEdit* greater_than = new QLineEdit(dialog);
            QPair<QLineEdit*, QLineEdit*> inputValuesPairs;
            inputValuesPairs.first = less_than;
            inputValuesPairs.second = greater_than;

            QLabel* lable_name = new QLabel(dialog);

            less_than->setAlignment(Qt::AlignCenter);
            greater_than->setAlignment(Qt::AlignCenter);

            lable_name->setText(" < " + sql.column_names.at(i) + " < ");
            hlayout->addWidget(less_than);
            hlayout->addWidget(lable_name);
            hlayout->addWidget(greater_than);
            hlayout->setAlignment(Qt::AlignLeft);
            hlayout->setContentsMargins(20, 20, 20, 20);

            vlayout->addLayout(hlayout);
            values.append(inputValuesPairs);
            colNameList.append(sql.column_names.at(i));
        }
    }

    QPushButton *okButton = new QPushButton("确定", dialog);
    okButton->setMinimumHeight(20);

    vlayout->addWidget(okButton);

    connect(okButton, &QPushButton::clicked, dialog, &QDialog::accept);
    dialog->exec();

    QVector<SQL::CompareStruct> compList;
    int valueCount = 0;
    for (int i = 0; i < values.length(); i++)
    {
        SQL::CompareStruct comp;
        comp.col_name = colNameList.at(i);
        comp.less_than = values.at(i).first->text();
        if (!comp.less_than.isEmpty()) valueCount++;
        comp.greater_than = values.at(i).second->text();
        if (!comp.greater_than.isEmpty()) valueCount++;
        compList.append(comp);

    }

    delete dialog;
    QSqlQuery result = sql.QueryData(compList, valueCount);

    // 触发表格刷新
    QStandardItemModel *model = new QStandardItemModel(this);
    QSqlRecord record = result.record();
    QStringList headList;

    // 设置表头标题
//    model->setHorizontalHeaderLabels({record.fieldName(0), record.fieldName(1), record.fieldName(2)});
    for (int i =0; i < record.count(); i++)
    {
        headList.append(record.fieldName(i));
    }
    model->setHorizontalHeaderLabels(headList);
    // 添加数据
    while (result.next())
    {
//        model->appendRow({ new QStandardItem(query.value(0).toString()), new QStandardItem(query.value(1).toString()), new QStandardItem(query.value(2).toString()) });
        QList<QStandardItem*> valueList;
        for (int i =0; i < record.count(); i++)
        {
            if (!result.isNull(i))
                valueList.append(new QStandardItem(result.value(i).toString()));
            else
                valueList.append(new QStandardItem("null"));
        }
        model->appendRow(valueList);
    }
    // 创建QTableView并设置数据模型
    ui->table->setModel(model);
    // QMessageBox::information(this, "", "刷新！！！");

}

void MainWindow::SelectTable()
{
    QSqlQuery query;
    query.exec("show tables");

    ui->selectbox->clear();

    while(query.next())
    {
        ui->selectbox->addItem(query.value(0).toString());
        sql.tableList.append(query.value(0).toString());
    }

    // 获取当前选中的项索引
    int selectedIndex = ui->selectbox->currentIndex();

    // 设置默认选中项
    ui->selectbox->setCurrentIndex(0);
    qDebug() << selectedIndex;

}
