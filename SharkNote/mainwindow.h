#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql/QtSql>
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase con;
    QSqlQuery sqlbefehl;
    int numberq;
private slots:
    void cmdeinfuegenClicked();
    void Fehleranzeige();
    void ausgabehandler(int feldanzahl);
    void delhelpq(bool on);
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_yesbu_clicked();
};

#endif // MAINWINDOW_H
