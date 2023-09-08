#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QVector>
#include <QTableView>
#include <SQL_OPERATE.h>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void connected(QSqlDatabase DB);
    void refreash();
    void add_data();
    QString inputPrimaryKeyData(QString PrimaryKeyName);
    QVector<QString> inputValue(QString primerKeyName, QString primerKeyInput);
    void DeleteData();
    void ChangeData();
    void CatchTableViewMouseClick();
    void CatchTableViewEnter();
    void QureyData();
    void SelectTable();

private:
    Ui::MainWindow *ui;
    QString IP;
    QString localhost;
    QString username;
    QString passwd;
    QString DBname;




};

#endif // MAINWINDOW_H
