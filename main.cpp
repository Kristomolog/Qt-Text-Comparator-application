#include "TextComparator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    TextComparator window;
    window.show();
    
    return app.exec();
}
