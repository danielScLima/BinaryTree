#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateDotFile();
    updateImage();
    renderImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    myFile.open
    (
        "file.dot"
    );

    std::string textToFile;
    if (ui->radioButtonTrad->isChecked())
        textToFile = binaryTree.gitDotFileMode1();
    else
        textToFile = binaryTree.gitDotFileMode2();

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->labelOfImage->setPixmap(image);
    ui->labelOfImage->show();
}

void MainWindow::on_pushButtonOfInsert_clicked()
{
    int toInsert = ui->lineEditOfInsert->text().toInt();

    BinaryTreeNode* node = binaryTree.insert(toInsert);

    updateDotFile();
    updateImage();
    renderImage();

    QMessageBox msgBox;

    if (node != nullptr)
        msgBox.setText("The data was inserted");
    else
        msgBox.setText("Already exists a node with this data");

    msgBox.exec();
}

void MainWindow::on_pushButtonOfSearch_clicked()
{
    int toSearch = ui->lineEditOfSearch->text().toInt();
    bool ret = binaryTree.search(toSearch);

    QMessageBox msgBox;

    if (ret)
        msgBox.setText("Existe esse nó");
    else
        msgBox.setText("NÃO existe esse nó");

    msgBox.exec();
}

void MainWindow::on_pushButtonOfRemove_clicked()
{
    int toRemove = ui->lineEditOfRemove->text().toInt();
    BinaryTreeNode *binaryTreeNode = binaryTree.removeOne(toRemove);

    updateDotFile();
    updateImage();
    renderImage();

    if (binaryTreeNode != nullptr)
        delete binaryTreeNode;
}

void MainWindow::on_pushButtonPreOrdem_clicked()
{
    //Eu, esq, direita

    std::string ret = binaryTree.preOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonEmOrdem_clicked()
{
    //esq, eu, dir

    std::string ret = binaryTree.inOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonPosOrdem_clicked()
{
    //esq, dir, eu

    std::string ret = binaryTree.posOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonEmNivel_clicked()
{
    //eu, filhos, netos, bisnetos

    std::string ret = binaryTree.InLevelOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_radioButtonTrad_toggled(bool checked)
{
    updateDotFile();
    updateImage();
    renderImage();
}

void MainWindow::on_pushButtonRemPred_clicked()
{
    int toRemove = ui->lineEditRemPred->text().toInt();
    BinaryTreeNode *binaryTreeNode = binaryTree.removeUsingPredecessor(toRemove);

    updateDotFile();
    updateImage();
    renderImage();

    if (binaryTreeNode != nullptr)
        delete binaryTreeNode;
}
