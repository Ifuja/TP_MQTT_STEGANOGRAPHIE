# TP MQTT & STÉGANOGRAPHIE
Travaux pratiques effectués en cours de C++. Pour l'ensemble des TP, vous aurez besoin de télécharger les logiciels MQTTX et QT.

## TP MQTT
Ce TP a pour but de comprendre le fonctionnement de MQTT, un protocole de messagerie légère pour les réseaux à faible bande passante et à haute latence. Il permet de mettre en place des communications entre différents appareils en temps réel.

### Installation
1. Ouvrez un terminal et récupérez le projet ci-dessus en faisant un "git clone".
2. Ouvrez le logiciel QT et executez le projet TestQtMQTT.

Depuis le logiciel MQTTX vous devez créer (en prenant exemple sur mon projet):

➢ Un broker public : broker.emqx.io, port 1883

➢ Topic : /ynov/bordeaux/

➢ Connexion : Ifuja@broker.emqx.io:1883

➢ Message : Ifuja

## TP STÉGANOGRAPHIE
Ce TP a pour but de comprendre le principe de la stéganographie, qui consiste à dissimuler des informations secrètes dans des fichiers multimédias (images, vidéos, sons, etc.).

### Installation
1. Ouvrez un terminal et récupérez le projet ci-dessus en faisant un "git clone".
2. Ouvrez le logiciel QT et executez le projet tp_steganographie.

### Utilisation
Une interface graphique s'ouvrira et vous devez suivre les étapes suivantes :
➢ Cliquez sur le bouton "Originale" (vous aurez le contenu du fichier "phrase_originale.txt")
➢ Cliquez sur le bouton "Modifiée" (vous aurez le contenu du fichier "phrase_modifiée.txt")
➢ Cliquez sur le bouton "Lancement" pour obtenir la modification entre les deux fichiers.
