#include "servers_widget.h"
#include "ui_servers_widget.h"

Servers_Widget::Servers_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Servers_Widget)
{
    ui->setupUi(this);
    corecom = new CoreCommunicator;
    xmlInterpreter = new XMLInterpreter;
    updateServers();
}

Servers_Widget::~Servers_Widget()
{
    delete ui;
}

void Servers_Widget::updateServers()
{
    corecom->setFilename("getobject.xml");
    corecom->get(corecom->urlCreator("getobject.xml"));
    xmlInterpreter->readXML("getobject.xml");
}
