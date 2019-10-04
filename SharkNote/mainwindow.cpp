#include "init.h"
#include "add.h"
void MainWindow::Fehleranzeige()
{
    QSqlError fehler = sqlbefehl.lastError();
    if(fehler.isValid()){
        QMessageBox mbs;
        mbs.setText("SQL Error:\n" + fehler.databaseText());
        mbs.exec();
    }
}

#include "delete.h"
