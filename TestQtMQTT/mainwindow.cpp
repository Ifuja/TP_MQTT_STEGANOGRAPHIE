#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /***Settings of MQTT broker***/
    QSettings *ssettings= new QSettings();
    ssettings->setValue("port",1883);
    ssettings->setValue("host","broker.emqx.io");
    ssettings->setValue("qosLevel",0);

    /***Settings of MQTT client***/
    client= new QMqttClient(this);
    client->setHostname("broker.emqx.io");
    client->setPort(1883);
    client->connectToHost();

    /***The method for published a message on the MQTT topic "/ynov/bordeaux/"***/
    connect(ui->pb_published,&QPushButton::clicked, this, [this]()
    {
        client->publish(QMqttTopicName("/ynov/bordeaux/"),ui->enter_message->text().toLocal8Bit());
        qDebug()<<" state "<< client->state();
        QMqttSubscription* sub= client->subscribe(QMqttTopicFilter("/ynov/bordeaux/"));
    });

    /***The method for received a message sended by the MQTT client***/
    connect(client,&QMqttClient::messageReceived, this, [this](const QByteArray& message,const QMqttTopicName& topic)
    {
        QString texte= QString("Topic:")+topic.name();
        texte+= QString(" message ")+ QString( message);
        ui->received_message->setText(texte);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

