#include <QApplication>
#include <QDebug>
#include "include/main_window.h"

int main(int argc, char *argv[]) {
    qDebug() << "Starting app...";  // debug output
    qDebug() << "Qt version: " << qVersion();

    QApplication app(argc, argv);

    AnnotationWindow window;

    window.setWindowTitle("Annotation Generator");
    window.resize(400, 300);
    window.show();  
    
    return app.exec();
}
