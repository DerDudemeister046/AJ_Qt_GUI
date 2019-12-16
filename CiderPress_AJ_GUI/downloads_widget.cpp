#include "downloads_widget.h"
#include "ui_downloads_widget.h"

Downloads_Widget::Downloads_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Downloads_Widget)
{
    ui->setupUi(this);
    corecom = new CoreCommunicator(this);

    //qDebug() << corecom->urlCreator("modified.xml");

    ui->downloads_treew->setColumnCount(2);
    addRoot("Hello", "World");
}

Downloads_Widget::~Downloads_Widget()
{
    delete ui;
}


void Downloads_Widget::on_getList_btn_clicked()
{
    corecom->setFilename("modified.xml");

    QString urlbase = corecom->urlCreator("modified.xml");
    QString urlfilter = "&filter=ids;down";
    QString geturl = urlbase + urlfilter;
    qDebug() << geturl;
    corecom->get(geturl);


    XMLInterpreter *xmli = new XMLInterpreter;
    xmli->readXML("modified.xml");

    xmli->listElements("downloadid","id");
    QStringList list_id = xmli->getElementList("download", "id");
    QStringList list_filename = xmli->getElementList("download", "filename");

    for (int i=0; i<list_id.size(); i++)
    {
        qDebug() << "LIST ELEMENT: "<< list_id.at(i);
        qDebug() << "LIST FILENAME: "<< list_filename.at(i);

        addRoot(list_id.at(i),list_filename.at(i));
    }
}

void Downloads_Widget::addRoot(QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->downloads_treew);
    itm->setText(0,name);
    itm->setText(1,Description);
    ui->downloads_treew->addTopLevelItem(itm);

    //addChild(itm,"abc","test1");
}

void Downloads_Widget::addChild(QTreeWidgetItem *parent, QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Description);
    parent->addChild(itm);
}
