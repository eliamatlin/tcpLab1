#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QToolBar>
#include <QMenuBar>
#include "stack.h"
#include "queue.h"


Stack NewStack;
Queue NewQueue;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Mode_label_2->setText("Режим Стека");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    Mode = false;
    ui->Mode_label_2->setText("Режим Стека");
}

void MainWindow::on_pushButton_4_clicked()
{
    Mode = true;
    ui->Mode_label_2->setText("Режим Очереди");
}

void MainWindow::on_pushButton_clicked()//Push
{
         if (Mode==false) //Stack
         {
            if(ui->textEdit->toPlainText().length() > 0)
            {

                ui->listWidget->insertItem(0, ui->textEdit->toPlainText());
                NewStack.Push(ui->textEdit->toPlainText().toInt());
                ui->textEdit->clear();
                ui->textEdit->setFocus();
            }
         }

         else
         {
             if(ui->textEdit->toPlainText().length() > 0) //Queue
             {
                 ui->listWidget->addItem(ui->textEdit->toPlainText());
                 NewStack.Push(ui->textEdit->toPlainText().toInt());
                 ui->textEdit->clear();
                 ui->textEdit->setFocus();
             }
         }
}

void MainWindow::on_pushButton_2_clicked()//Pop
{
          if (Mode==false) //Stack
          {
            if(ui->listWidget->count() > 0)
            {
             ui->label->setText(QString::number (NewStack.Pop(), 10));
             delete ui->listWidget->item(0);
            }
          }

          else
          {
              if(ui->listWidget->count() > 0) //Queue
              {
               ui->label->setText(QString::number (NewStack.Pop(), 10));
               delete ui->listWidget->item(0);
              }
          }
}
