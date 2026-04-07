#pragma once

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QStackedWidget>
#include <annotation/Parameters.h>

class AnnotationWindow : public QMainWindow {
private:
    QComboBox *typeSelector;
    QStackedWidget *stackedWidget;
    QLabel *resultText;

    void createTypeWidgets();
    void changeTypeWidget();
    void generateAnnotation();
    QMap<QString, QString> extractDataForm();
    AnnotationData getAnnotationData(const QMap<QString, QString>& formData);

public:
    AnnotationWindow(QWidget *parent = nullptr);
};