#pragma once

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QStackedWidget>

class AnnotationWindow : public QMainWindow {
private:
    QComboBox *typeSelector;
    QStackedWidget *stackedWidget;
    QLabel *resultText;

    void createTypeWidgets();
    void changeTypeWidget();
    void generateAnnotation();

public:
    AnnotationWindow(QWidget *parent = nullptr);
};