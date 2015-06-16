#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Library Awesomo"));
    ui->windySwitchy->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::open()
{
    QString fp = (QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                                               tr("Txt-Files (*.txt);;All Files (*);; Html-Files (*.htm *.html)")));
    if (!fp.isEmpty())
    {
        QFile file(fp);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
//        addrEdit->setText(in.readAll());
        file.close();
    }
}
void MainWindow::save()
{
    QString fPath = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                                                 tr("Txt-Files (*.txt);;All Files (*);; Html-Files (*.htm *.html)"));
    if(!fPath.isEmpty())
    {
        QFile file(fPath);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not save file"));
            return;
        }
        QTextStream out(&file);
//        out << addrEdit->toPlainText();
        out.flush();
        file.close();
    }
}
void MainWindow::quit()
{
    QMessageBox quitMsg;
    quitMsg.setWindowTitle(tr("Quit"));
    quitMsg.setText(tr("Unsaved progress will be lost.\nAre you sure?"));
    quitMsg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    quitMsg.setDefaultButton(QMessageBox::No);
    if(quitMsg.exec() == QMessageBox::Yes)
        qApp->quit();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, tr("Quit"),
                                                                tr("Unsaved progress will be lost.\nAre you sure?"),
                                                                QMessageBox::Cancel | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}


void MainWindow::on_ptrnView_clicked()
{
    ui->windySwitchy->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->windySwitchy->setCurrentIndex(0);
}
