#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString j_original_filePath;
    QString j_modified_filePath;
    QString content_original;
    QString content_modified;
    QString differences;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
