#pragma once

#include <QMainWindow>
#include <QComboBox>
#include <QStackedWidget>

class AnnotationWindow : public QMainWindow {
private:
    QComboBox *typeSelector;
    QStackedWidget *stackedWidget;

    void createTypeWidgets();
    void changeTypeWidget();

public:
    AnnotationWindow(QWidget *parent = nullptr);
};