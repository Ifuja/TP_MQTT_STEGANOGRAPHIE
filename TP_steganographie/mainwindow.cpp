#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>
#include <QFile>

#define PHRASE_ORIGINALE "C:/Users/user/Documents/TP_MQTT_STEGANOGRAPHIE/phrase_originale.txt"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QString phrase_original = QString ("C:/Users/user/Documents/TP_MQTT_STEGANOGRAPHIE/phrase_originale.txt");

    /*** The button that will display the original joke ***/
    connect(ui->pb_original, &QPushButton::clicked, this, [this]()
    {
        QString path_joke_original = "C:/Users/user/Documents/TP_MQTT_STEGANOGRAPHIE/phrase_originale.txt" ;
        ui->edit_original->setText(path_joke_original);

        s_j_original_filePath = QString ("C:/Users/user/Documents/TP_MQTT_STEGANOGRAPHIE/phrase_originale.txt");
        QFile file(s_j_original_filePath);

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->text->setPlainText("Impossible d'ouvrir le fichier!");
            return;
        }

        QTextStream text_original(&file);
        ui->text->setPlainText(text_original.readAll());
        s_content_original = ui->text->toPlainText();

        file.close();
        qDebug() << "Le bouton original a été cliqué.";
    });

    /*** The button that will display the modified joke ***/
    connect(ui->pb_modified, &QPushButton::clicked, this, [this]()
    {
        QString path_joke_modified = "C:/Users/user/Documents/TP_MQTT_STEGANOGRAPHIE/phrase_modifiée.txt";
        ui->edit_modified->setText(path_joke_modified);

        s_j_modified_filePath = QString ("C:/Users/user/Documents/TP_MQTT_STEGANOGRAPHIE/phrase_modifiée.txt");
        QFile file(s_j_modified_filePath);

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->text->setPlainText("Impossible d'ouvrir le fichier!");
            return;
        }

        QTextStream text_modified(&file);
        ui->text->setPlainText(text_modified.readAll());
        s_content_modified = ui->text->toPlainText();

        file.close();
        qDebug() << "Le bouton modifié a été cliqué.";
    });

    /*** The button that will display the difference between the original and modified joke ***/
    connect(ui->pb_play, &QPushButton::clicked, this, [this]()
    { 
        int32_t minLength = qMin(s_content_original.length(), s_content_modified.length());
        for (int32_t s32_i = 0; s32_i < minLength; s32_i++)
        {
            if (s_content_original[s32_i] != s_content_modified[s32_i])
            {
                s_differences.append(s_content_original[s32_i]);
            }
        }
        if (s_content_original.length() > s_content_modified.length())
        {
            s_differences.append(s_content_original.midRef(minLength));
        }
        else if (s_content_modified.length() > s_content_original.length())
        {
            s_differences.append(s_content_modified.midRef(minLength));
        }
        qDebug() << "La différence entre les deux phrases :" << s_differences;
        ui->text->setPlainText(s_differences);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

