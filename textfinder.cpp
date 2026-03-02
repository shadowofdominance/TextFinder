#include "textfinder.h"
#include "ui_textfinder.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFile();
}

TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::on_FindButton_clicked()
{
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}

void TextFinder::loadTextFile()
{
    qDebug() << "Exists?" << QFile::exists(":/para.txt");

    QFile inputFile(":/para.txt");

    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file!";
        return;
    }

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
}
