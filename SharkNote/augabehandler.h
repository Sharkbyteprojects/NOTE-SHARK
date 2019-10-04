#ifndef AUGABEHANDLER_H
#define AUGABEHANDLER_H

#endif // AUGABEHANDLER_H
void MainWindow::ausgabehandler(int feldanzahl)
{
    ui->LstAusgabe->clear();
    QString ausgabe;
    while(sqlbefehl.next())
    {
        ausgabe = "";
        for(int i=0; i<feldanzahl; i++){
            //ausgabe=sqlbefehl.value(i).toString() + " \\ ";
            ausgabe+=sqlbefehl.value(i).toString() + " |\t| ";
        }
        ui->LstAusgabe->addItem(ausgabe);
    }
}
