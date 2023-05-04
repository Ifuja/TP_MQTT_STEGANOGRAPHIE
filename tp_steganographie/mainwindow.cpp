#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*** The button that will display the original joke ***/
    connect(ui->pb_original, &QPushButton::clicked, this, [this]()
    {
        QString path_joke_original = "C:/Users/user/Documents/tp_steganographie/phrase_originale.txt";
        ui->edit_original->setText(path_joke_original);

        j_original_filePath = "C:/Users/user/Documents/tp_steganographie/phrase_originale.txt";
        QFile file(j_original_filePath);

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->text->setPlainText("Impossible d'ouvrir le fichier!");
            return;
        }

        QTextStream text_original(&file);
        ui->text->setPlainText(text_original.readAll());
        content_original = ui->text->toPlainText();

        file.close();
        qDebug() << "Le bouton original a été cliqué.";
    });

    /*** The button that will display the modified joke ***/
    connect(ui->pb_modified, &QPushButton::clicked, this, [this]()
    {
        QString path_joke_modified = "C:/Users/user/Documents/tp_steganographie/phrase_modifiée.txt";
        ui->edit_modified->setText(path_joke_modified);

        j_modified_filePath = "C:/Users/user/Documents/tp_steganographie/phrase_modifiée.txt";
        QFile file(j_modified_filePath);

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->text->setPlainText("Impossible d'ouvrir le fichier!");
            return;
        }

        QTextStream text_modified(&file);
        ui->text->setPlainText(text_modified.readAll());
        content_modified = ui->text->toPlainText();

        file.close();
        qDebug() << "Le bouton modifié a été cliqué.";
    });

    /*** The button that will display the difference between the original and modified joke ***/
    connect(ui->pb_play, &QPushButton::clicked, this, [this]()
    { 
        int minLength = qMin(content_original.length(), content_modified.length());
        for (int i = 0; i < minLength; i++)
        {
            if (content_original[i] != content_modified[i])
            {
                differences.append(content_original[i]);
            }
        }
        if (content_original.length() > content_modified.length())
        {
            differences.append(content_original.midRef(minLength));
        }
        else if (content_modified.length() > content_original.length())
        {
            differences.append(content_modified.midRef(minLength));
        }
        qDebug() << "La différence entre les deux phrases :" << differences;
        ui->text->setPlainText(differences);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

