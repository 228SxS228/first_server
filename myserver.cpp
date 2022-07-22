#include "myserver.h"

myserver::myserver(){}
myserver::~myserver(){}

void myserver::startServer()
{
    if (this->listen(QHostAddress::Any,5555))
    {
        qDebug()<<"Listenig";
    }
    else
    {
        qDebug()<<"Not listenig";
    }
}

void myserver::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
        connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisck()));

    qDebug()<<socketDescriptor<<"Client connected";

    socket->write("You are connect");
    qDebug()<<"Send client connected status - YES";
}

void myserver::sockReady()
{

}
void myserver::sockDisck()
{
    qDebug()<<"Disconnect";
    socket->deleteLater();
}
