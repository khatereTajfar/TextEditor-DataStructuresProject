#include "mainwindow.h"
#include "doublylinkedlist.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    mFileName="";
    ui->textEdit->setPlainText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString texts;
    QString file=QFileDialog::getOpenFileName(this,"open a file");
    if(!file.isEmpty()){
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
            mFileName=file;
            QTextStream in(&sFile);
            while (!in.atEnd()) {
                QString text=in.readLine();
                texts=texts.append(" ").append(text);
            }
            ui->textEdit->setPlainText(texts);
            QStringList splited=texts.split(" ");
            Node* cur;
            cur = List.First;
            for(int i=0;i<splited.length();i++){
                List.Insert(cur,splited[i]);
                cur = cur->Next;
            }
            printf("-------------------------------------------------\n");
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFileName);
    if(sFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&sFile);
        out <<ui->textEdit->toPlainText();
        sFile.flush();
        sFile.close();
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    QString file=QFileDialog::getSaveFileName(this,"open a file");
    if(!file.isEmpty()){
        mFileName=file;
        on_actionSave_triggered();
    }
}


Node* MainWindow::on_Find_clicked()
{
    QString text=ui->lineEdit->text();
    Node *Pred=List.Search(text);
    return Pred;
}

void MainWindow::on_Insert_clicked()
{
    QString text=ui->lineEdit_2->text();
    Node *Pred=on_Find_clicked();
    List.Insert(Pred,text);
    Node *cur=List.First->Next;
    ui->textEdit->clear();

    while (cur!=List.First) {
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->textEdit->insertPlainText (cur->Data);
        ui->textEdit->insertPlainText (" ");
        ui->textEdit->moveCursor (QTextCursor::End);
        cur=cur->Next;
    }

}

void MainWindow::on_Delete_clicked()
{
    Node *Pred=on_Find_clicked();
    List.Delete(Pred);
    Node *cur=List.First->Next;
    ui->textEdit->clear();

    while (cur!=List.First) {
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->textEdit->insertPlainText (cur->Data);
        ui->textEdit->insertPlainText (" ");
        ui->textEdit->moveCursor (QTextCursor::End);
        cur=cur->Next;
    }
}

void MainWindow::on_Edit_clicked()
{
    QString text=ui->lineEdit_3->text();
    Node *Current=on_Find_clicked();
    List.Edit(Current,text);
    Node *cur=List.First->Next;
    ui->textEdit->clear();

    while (cur!=List.First) {
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->textEdit->insertPlainText (cur->Data);
        ui->textEdit->insertPlainText (" ");
        ui->textEdit->moveCursor (QTextCursor::End);
        cur=cur->Next;
    }
}


