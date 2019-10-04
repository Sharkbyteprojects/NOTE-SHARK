#ifndef SQLINIT_H
#define SQLINIT_H
#endif // SQLINIT_H
con = QSqlDatabase::addDatabase("QSQLITE");
con.setDatabaseName("notes.db");
delhelpq(false);
if(!con.open())
{
    QMessageBox mb;
    mb.setText("We can't load SQL Database");
    //ui->LstAusgabe->addItem("!!Error DB!!");
    mb.exec();
    return;
}
sqlbefehl = QSqlQuery(con);
sqlbefehl.exec("CREATE TABLE notes("
               "id INTEGER, "
               "title TEXT, "
               "message TEXT)");
sqlbefehl.exec("SELECT * FROM notes");
ausgabehandler(numberq);
