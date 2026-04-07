#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QPixmap>
#include "annotation/BasGenerator.h"
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
    mainLayout->setSpacing(2);

    this->stackedWidget = new QStackedWidget(centralWidget);
    mainLayout->addWidget(stackedWidget);

    createTypeWidgets();

    mainLayout->setSpacing(1);
    QPushButton *applyBtn = new QPushButton("Generate", centralWidget);
    mainLayout->addWidget(applyBtn);
    mainLayout->setSpacing(2);

    this->resultText = new QLabel("tutaj bedzie odpowiedz", centralWidget);
    resultText->setTextFormat(Qt::RichText);
    mainLayout->addWidget(resultText);

    connect(typeSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(applyBtn, &QPushButton::clicked, this, AnnotationWindow::generateAnnotation);
}

void AnnotationWindow::generateAnnotation() {
    
    QMap<QString, QString> rawData = extractDataForm();

    AnnotationData data = getAnnotationData(rawData);

    const char* generated = BasGenerator().generateAnnotation(data);

    this->resultText->setText(QString::fromUtf8(generated));
}

QMap<QString, QString> AnnotationWindow::extractDataForm(){

    QMap<QString, QString> collectedData;

    QWidget *currentPage = stackedWidget->currentWidget();

    QList<QLineEdit*> allLineEdits = currentPage->findChildren<QLineEdit*>();

    for (QLineEdit *lineEdit : allLineEdits) {
        QString fieldName = lineEdit->objectName();
        QString fieldValue = lineEdit->text();
        
        collectedData.insert(fieldName, fieldValue);
    }

    return collectedData;
}

AnnotationData AnnotationWindow::getAnnotationData(const QMap<QString, QString> &formData) {

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
        qDebug() << "Kategoria: " << result->first;
    } else {
        qDebug() << "Nie znaleziono kategorii!";
    }

    if (formData.contains("year"))          data.year = formData.value("year").toStdString();
    if (formData.contains("date"))          data.date = formData.value("date").toStdString();
    if (formData.contains("title"))         data.title = formData.value("title").toStdString();
    if (formData.contains("originalTitle")) data.originalTitle = formData.value("originalTitle").toStdString();
    if (formData.contains("place"))         data.place = formData.value("place").toStdString();
    if (formData.contains("publisher"))     data.publisher = formData.value("publisher").toStdString();
    if (formData.contains("url"))           data.url = formData.value("url").toStdString();
    if (formData.contains("source"))        data.source = formData.value("source").toStdString();
    if (formData.contains("pages"))         data.pages = formData.value("pages").toStdString();
    if (formData.contains("author"))        data.authors[0] = formData.value("author").toStdString();

    // Add later parsing from multiple authors
    return data;
}

void AnnotationWindow::createTypeWidgets() {

    // *** BOOK ***
    QWidget *bookPage = new QWidget();
    QFormLayout *bookLayout = new QFormLayout(bookPage);

    QLineEdit *bookAuthor = new QLineEdit();
    bookAuthor->setObjectName("author");

    QLineEdit *bookTitle = new QLineEdit();
    bookTitle->setObjectName("title");

    QLineEdit *bookYear = new QLineEdit();
    bookYear->setObjectName("year");

    QLineEdit *bookPublisher = new QLineEdit();
    bookPublisher->setObjectName("publisher");

    QLineEdit *bookPlace = new QLineEdit();
    bookPlace->setObjectName("place");

    QLineEdit *bookPages = new QLineEdit();
    bookPages->setObjectName("pages");

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
    collectiveAuthor->setObjectName("authors");
    
    QLineEdit *collectiveTitle = new QLineEdit();
    collectiveTitle->setObjectName("title");
    
    QLineEdit *collectivePublisher = new QLineEdit();
    collectivePublisher->setObjectName("publisher");
    
    QLineEdit *collectivePlace = new QLineEdit();
    collectivePlace->setObjectName("place");
    
    QLineEdit *collectivePages = new QLineEdit();
    collectivePages->setObjectName("pages");

    collectiveLayout->addRow("Author:", collectiveAuthor);
    collectiveLayout->addRow("Title:", collectiveTitle);
    collectiveLayout->addRow("Publisher:", collectivePublisher);
    collectiveLayout->addRow("Place:", collectivePlace);
    collectiveLayout->addRow("Pages:", collectivePages);

    this->stackedWidget->addWidget(collectivePage);
    
    // *** MONOGRAPH ***
    QWidget *monoPage = new QWidget();
    QFormLayout *monoLayout = new QFormLayout(monoPage);

    QLineEdit *monoAuthor = new QLineEdit();
    monoAuthor->setObjectName("author");
    
    QLineEdit *monoTitle = new QLineEdit();
    monoTitle->setObjectName("title");
    
    QLineEdit *monoYear = new QLineEdit();
    monoYear->setObjectName("year");
    
    QLineEdit *monoPublisher = new QLineEdit();
    monoPublisher->setObjectName("publisher");
    
    QLineEdit *monoPages = new QLineEdit();
    monoPages->setObjectName("pages");

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
    magazineAuthor->setObjectName("author");
    
    QLineEdit *magazineTitle = new QLineEdit();
    magazineTitle->setObjectName("title");
    
    QLineEdit *magazineYear = new QLineEdit();
    magazineYear->setObjectName("year");
    
    QLineEdit *magazinePages = new QLineEdit();
    magazinePages->setObjectName("pages");

    magazineLayout->addRow("Author:", magazineAuthor);
    magazineLayout->addRow("Title:", magazineTitle);
    magazineLayout->addRow("Year:", magazineYear);
    magazineLayout->addRow("Pages:", magazinePages);

    this->stackedWidget->addWidget(magazinePage);

    // *** ONLINE ARTICLE ***
    QWidget *onlineArtPage = new QWidget();
    QFormLayout *onlineArtLayout = new QFormLayout(onlineArtPage);

    QLineEdit *onlineArtAuthor = new QLineEdit();
    onlineArtAuthor->setObjectName("author");
    
    QLineEdit *onlineArtTitle = new QLineEdit();
    onlineArtTitle->setObjectName("title");
    
    QLineEdit *onlineArtYear = new QLineEdit();
    onlineArtYear->setObjectName("year");
    
    QLineEdit *onlineArtPages = new QLineEdit();
    onlineArtPages->setObjectName("pages");
    
    QLineEdit *onlineArtSource = new QLineEdit();
    onlineArtSource->setObjectName("source");
    
    QLineEdit *onlineArtDate = new QLineEdit();
    onlineArtDate->setObjectName("date");
    
    QLineEdit *onlineArtUrl = new QLineEdit();
    onlineArtUrl->setObjectName("url");
    
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
    videoAuthor->setObjectName("author");
    
    QLineEdit *videoTitle = new QLineEdit();
    videoTitle->setObjectName("title");
    
    QLineEdit *videoOriginalTitle = new QLineEdit();
    videoOriginalTitle->setObjectName("originalTitle");
    
    QLineEdit *videoYear = new QLineEdit();
    videoYear->setObjectName("year");
    
    QLineEdit *videoSource = new QLineEdit();
    videoSource->setObjectName("source");
    
    QLineEdit *videoDate = new QLineEdit();
    videoDate->setObjectName("date");
    
    QLineEdit *videoUrl = new QLineEdit();
    videoUrl->setObjectName("url");
    
    videoLayout->addRow("Author:", videoAuthor);
    videoLayout->addRow("Title:", videoTitle);
    videoLayout->addRow("Original title", videoOriginalTitle);
    videoLayout->addRow("Year:", videoYear);
    videoLayout->addRow("Source:", videoSource);
    videoLayout->addRow("Date:", videoDate);
    videoLayout->addRow("Url:", videoUrl);

    this->stackedWidget->addWidget(videoPage);
}