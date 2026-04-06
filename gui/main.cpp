#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

int main(int argc, char *argv[]) {
    qDebug() << "Starting app...";  // debug output
    
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Test GUI");
    window.resize(400, 300);
    
    QPushButton *button = new QPushButton("Click me!", &window);
    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(button);
    
    window.show();  
    
    qDebug() << "App exec";
    return app.exec();
}
