#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{  QApplication a(argc, argv);
        Calculator w;
        w.setFixedSize(700, 500);
        QBrush br(Qt::TexturePattern);

        QPalette plt = w.palette();
        w.setPalette(plt);
        w.show();
        return a.exec();
}
