#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include "annotation/Parameters.h"
#include "main_window.h"

AnnotationWindow::AnnotationWindow(QWidget *parent) : QMainWindow(parent) {

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    this->typeSelector = new QComboBox(centralWidget);

    for (auto cat : catMap) {
        typeSelector->addItem(cat.first);
    } 

    mainLayout->addWidget(typeSelector);
    mainLayout->setSpacing(3);

    this->stackedWidget = new QStackedWidget(centralWidget);
    mainLayout->addWidget(stackedWidget);

    createTypeWidgets();

    mainLayout->setSpacing(2);
    QPushButton *applyBtn = new QPushButton("Apply", centralWidget);
    mainLayout->addWidget(applyBtn);

    this->resultText = new QLabel("tutaj bedzie odpowiedz", centralWidget);
    mainLayout->addWidget(resultText);

    connect(typeSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(applyBtn, &QPushButton::clicked, this, AnnotationWindow::generateAnnotation);
}

void AnnotationWindow::generateAnnotation() {
   
    AnnotationData data;

    data.annStyle == AnnotationStyle::BAS;

    QString comboText = typeSelector->currentText();

    auto result = std::find_if(
                catMap.begin(),
                catMap.end(),
                [&comboText](const auto& cat) {return cat.first == comboText;}
    );

    if (result != catMap.end()) {
        data.annCat = result->second;
    }

    QWidget *currentWidget = stackedWidget->currentWidget();
    QFormLayout *form = qobject_cast<QFormLayout*>(stackedWidget->currentWidget()->layout());

    for (int row = 0; row < form->rowCount(); row++) {
        QLayoutItem *labelItem = form->itemAt(row, QFormLayout::LabelRole);
        QLayoutItem *fieldItem = form->itemAt(row, QFormLayout::FieldRole);

        if (labelItem && fieldItem) {
            QLabel *label = qobject_cast<QLabel*>(labelItem->widget());
            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(fieldItem->widget());

            if (label && lineEdit) {
                QString fieldName = label->text(); 
                QString fieldValue = lineEdit->text(); 
                
                qDebug() << "Pole" << fieldName << "ma wartość:" << fieldValue; 
            }  
        }
    }
}

void AnnotationWindow::createTypeWidgets() {

    // *** BOOK ***
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
    
    // *** COLLECTIVE ***
    QWidget *collectivePage = new QWidget();
    QFormLayout *collectiveLayout = new QFormLayout(collectivePage); 

    QLineEdit *collectiveAuthor = new QLineEdit();
    QLineEdit *collectiveTitle = new QLineEdit();
    // QLineEdit *collectiveYear = new QLineEdit();
    QLineEdit *collectivePublisher = new QLineEdit();
    QLineEdit *collectivePlace = new QLineEdit();
    QLineEdit *collectivePages = new QLineEdit();

    collectiveLayout->addRow("Author:", collectiveAuthor);
    collectiveLayout->addRow("Title:", collectiveTitle);
    // collectiveLayout->addRow("Year:", collectiveYear);
    collectiveLayout->addRow("Publisher:", collectivePublisher);
    collectiveLayout->addRow("Place:", collectivePlace);
    collectiveLayout->addRow("Pages:", collectivePages);

    this->stackedWidget->addWidget(collectivePage);
    
    // *** MONOGRAPH ***
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

    // *** Legal Act ***
    QWidget *legalPage = new QWidget();
    this->stackedWidget->addWidget(legalPage);

    // *** MAGAZINE ARTICLE ***
    QWidget *magazinePage = new QWidget();
    QFormLayout *magazineLayout = new QFormLayout(magazinePage);

    QLineEdit *magazineAuthor = new QLineEdit();
    QLineEdit *magazineTitle = new QLineEdit();
    QLineEdit *magazineYear = new QLineEdit();
    QLineEdit *magazinePages = new QLineEdit();

    magazineLayout->addRow("Author:", magazineAuthor);
    magazineLayout->addRow("Title:", magazineTitle);
    magazineLayout->addRow("Year:", magazineYear);
    magazineLayout->addRow("Pages:", magazinePages);

    this->stackedWidget->addWidget(magazinePage);

    // *** ONLINE ARTICLE ***
    QWidget *onlineArtPage = new QWidget();
    QFormLayout *onlineArtLayout = new QFormLayout(onlineArtPage);

    QLineEdit *onlineArtAuthor = new QLineEdit();
    QLineEdit *onlineArtTitle = new QLineEdit();
    QLineEdit *onlineArtYear = new QLineEdit();
    QLineEdit *onlineArtPages = new QLineEdit();
    QLineEdit *onlineArtSource = new QLineEdit();
    QLineEdit *onlineArtDate = new QLineEdit();
    QLineEdit *onlineArtUrl = new QLineEdit();
    
    onlineArtLayout->addRow("Author:", onlineArtAuthor);
    onlineArtLayout->addRow("Title:", onlineArtTitle);
    onlineArtLayout->addRow("Year:", onlineArtYear);
    onlineArtLayout->addRow("Pages:", onlineArtPages);
    onlineArtLayout->addRow("Source:", onlineArtSource);
    onlineArtLayout->addRow("Date:", onlineArtDate);
    onlineArtLayout->addRow("Url:", onlineArtUrl);
    
    this->stackedWidget->addWidget(onlineArtPage);

    // *** ONLINE VIDEO ***
    QWidget *videoPage = new QWidget();
    QFormLayout *videoLayout = new QFormLayout(videoPage);

    QLineEdit *videoAuthor = new QLineEdit();
    QLineEdit *videoTitle = new QLineEdit();
    QLineEdit *videoOriginalTitle = new QLineEdit();
    QLineEdit *videoYear = new QLineEdit();
    QLineEdit *videoSource = new QLineEdit();
    QLineEdit *videoDate = new QLineEdit();
    QLineEdit *videoUrl = new QLineEdit();
    
    videoLayout->addRow("Author:", videoAuthor);
    videoLayout->addRow("Title:", videoTitle);
    videoLayout->addRow("Original title", videoOriginalTitle);
    videoLayout->addRow("Year:", videoYear);
    videoLayout->addRow("Source:", videoSource);
    videoLayout->addRow("Date:", videoDate);
    videoLayout->addRow("Url:", videoUrl);

    this->stackedWidget->addWidget(videoPage);
}