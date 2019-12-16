#include "uploads_widget.h"
#include "ui_uploads_widget.h"

Uploads_Widget::Uploads_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Uploads_Widget)
{
    ui->setupUi(this);
    corecom = new CoreCommunicator(this);
    // Setup TableView in Widget
    ui->uploads_treew->setColumnCount(3);
}

Uploads_Widget::~Uploads_Widget()
{
    delete ui;
}

void Uploads_Widget::on_getList_btn_clicked()
{
    corecom->setFilename("modified.xml");

    // Setup final url to include filters if needed
    QString urlbase = corecom->urlCreator("modified.xml");
    QString urlfilter = "&filter=ids;upload";
    QString geturl = urlbase + urlfilter;

    qDebug() << geturl;
    // Get XML-File from server and save localy
    corecom->get(geturl);


    // Start XML Interpreter to read out XML File
    XMLInterpreter *xmli = new XMLInterpreter;
    xmli->readXML("modified.xml");  // Set table to be read

    // Get Elements that will be displayed from XML-File
    QStringList list_id = xmli->getElementList("download", "id");
    QStringList list_filename = xmli->getElementList("download", "filename");
    QStringList list_status = xmli->getElementList("download", "status");

    qDebug() << "Populate Downloadlist";
    for (int i=0; i<list_id.size(); i++)
    {
        addRoot(list_id.at(i),list_filename.at(i), list_status.at(i));
    }
}

void Uploads_Widget::addRoot(QString name, QString description, QString status)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->uploads_treew);
    itm->setText(0,name);
    itm->setText(1,description);
    itm->setText(2, status);
    ui->uploads_treew->addTopLevelItem(itm);

    //addChild(itm,"abc","test1");
}

void Uploads_Widget::addChild(QTreeWidgetItem *parent, QString name, QString description, QString status)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,description);
    parent->addChild(itm);
}
