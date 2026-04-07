#include "../include/main_window.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include "annotation/Parameters.h"

AnnotationWindow::AnnotationWindow(QWidget *parent) : QMainWindow(parent) {

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    this->typeSelector = new QComboBox(centralWidget);

    typeSelector->addItem("Monograph");
    typeSelector->addItem("Book");

    //for (auto cat : catMap) {
        //typeSelector->addItem(cat.first);
    //} 

    mainLayout->addWidget(typeSelector);

    this->stackedWidget = new QStackedWidget(centralWidget);
    mainLayout->addWidget(stackedWidget);

    createTypeWidgets();

    connect(typeSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), stackedWidget, &QStackedWidget::setCurrentIndex);
}

void AnnotationWindow::createTypeWidgets() {

    QWidget *monoPage = new QWidget();
    QFormLayout *monoLayout = new QFormLayout(monoPage);

    QLineEdit *monoAuthor = new QLineEdit();
    QLineEdit *monoTitle = new QLineEdit();
    QLineEdit *monoYear = new QLineEdit();
    QLineEdit *monoPublisher = new QLineEdit();
    QLineEdit *monoPages = new QLineEdit();

    monoLayout->addRow("Author:", monoAuthor);
    monoLayout->addRow("Title:", monoTitle);
    monoLayout->addRow("Year:", monoYear);
    monoLayout->addRow("Publisher:", monoPublisher);
    monoLayout->addRow("Pages:", monoPages);

    this->stackedWidget->addWidget(monoPage);

    QWidget *bookPage = new QWidget();
    QFormLayout *bookLayout = new QFormLayout(bookPage);

    QLineEdit *bookAuthor = new QLineEdit();
    QLineEdit *bookTitle = new QLineEdit();
    QLineEdit *bookYear = new QLineEdit();
    QLineEdit *bookPublisher = new QLineEdit();
    QLineEdit *bookPlace = new QLineEdit();
    QLineEdit *bookPages = new QLineEdit();

    bookLayout->addRow("Author:", bookAuthor);
    bookLayout->addRow("Title:", bookTitle);
    bookLayout->addRow("Year:", bookYear);
    bookLayout->addRow("Publisher:", bookPublisher);
    bookLayout->addRow("Place:", bookPlace);
    bookLayout->addRow("Pages:", bookPages);

    this->stackedWidget->addWidget(bookPage);
}