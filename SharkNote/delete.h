#ifndef DELETE_H
#define DELETE_H

#endif // DELETE_H
void MainWindow::delhelpq(bool on){
    ui->pushButton_3->setHidden(!on);
    ui->yesbu->setHidden(!on);
    ui->pushButton_3->setEnabled(on);
    ui->yesbu->setEnabled(on);
    ui->label_5->setHidden(!on);
    ui->pushButton->setEnabled(!on);
    ui->spinBox->setEnabled(!on);
    ui->label_4->setHidden(on);
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->spinBox->value()!=0){
    delhelpq(true);}else {
    QMessageBox mbd;
    mbd.setText("Failue to Delete\nThe entry with the number 0 doesn't exist!");
    mbd.exec();
}
}

void MainWindow::on_pushButton_3_clicked()
{
    delhelpq(false);ui->spinBox->setValue(0);
}

void MainWindow::on_yesbu_clicked()
{
   int values = ui->spinBox->value();
   sqlbefehl.exec("DELETE FROM notes WHERE id=\""+ QString::number(values) +"\"");
   sqlbefehl.exec("SELECT * FROM notes");
   ausgabehandler(numberq);
   delhelpq(false);
   ui->spinBox->setValue(0);
}
