#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <doublylinkedlist.h>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

private slots:
    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionSave_As_triggered();

    void on_Delete_clicked();

    Node *on_Find_clicked();

    void on_Insert_clicked();

    void on_Edit_clicked();

private:
    QString mFileName;
    DoublyLinkedList List;

};

#endif // MAINWINDOW_H
