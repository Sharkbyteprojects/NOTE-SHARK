#ifndef ADD_H
#define ADD_H

#endif // ADD_H

void MainWindow::cmdeinfuegenClicked()
{
    sqlbefehl.exec("SELECT id FROM notes");
    Fehleranzeige();
    int id = 0;
    sqlbefehl.last();
    id = sqlbefehl.value(0).toInt()+1;
    QString titles = ui->lineEdit->text();
    QString messagesm = ui->lineEdit_2->text();
    sqlbefehl.exec("INSERT INTO notes VALUES("
                   "'"+QString::number(id)+"',"
                   "'"+titles.replace("'", "\"")+"',"
                   "'" + messagesm.replace("'", "\"") +"'"
                   ")");
    Fehleranzeige();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    sqlbefehl.exec("SELECT * FROM notes");
    Fehleranzeige();
    ausgabehandler(numberq);
}
#include "augabehandler.h"
