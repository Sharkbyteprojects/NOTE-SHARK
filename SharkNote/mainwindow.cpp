#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("notes.db");
    numberq = 3;
    ui->spinBox->setValue(0);
    ui->spinBox->setMinimum(0);
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
    connect(ui->cmdeinfuegen, SIGNAL(clicked()),SLOT(cmdeinfuegenClicked()));
    this->setFixedSize(this->width(), this->height());
    sqlbefehl.exec("CREATE TABLE notes("
                   "id INTEGER, "
                   "title TEXT, "
                   "message TEXT)");
    sqlbefehl.exec("SELECT * FROM notes");
    ausgabehandler(numberq);
 }

MainWindow::~MainWindow()
{
    con.close();
    delete ui;
}
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
void MainWindow::Fehleranzeige()
{
    QSqlError fehler = sqlbefehl.lastError();
    if(fehler.isValid()){
        QMessageBox mbs;
        mbs.setText("SQL Error:\n" + fehler.databaseText());
        mbs.exec();
    }
}
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
