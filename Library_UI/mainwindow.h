#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QMenu>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QEvent>
#include <QCloseEvent>
#include <QTextStream>
#include <QLabel>
#include <QLineEdit>
#include <QPropertyAnimation>
#include <QGridLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
    void reject();
private:
    Ui::MainWindow *ui;
private slots:
    void open();
    void save();
    void quit();
    void on_ptrnView_clicked();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
