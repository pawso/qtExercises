#include <QApplication>
#include <QLabel>

#include "gameArea.hpp"

const unsigned int APP_WIDTH = 600;
const unsigned int APP_HEIGHT = 600 + 100; /// space needed for one more button

int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 
    // Create a container window
    QWidget window;
    window.setFixedSize(APP_HEIGHT, APP_WIDTH);

    GameField *gameField = new GameField(&window);
    
    window.show();
 
 // Create a progress bar
 // with the range between 0 and 100, and a starting value of 0
 /* QProgressBar *progressBar = new QProgressBar(&window);
 progressBar->setRange(0, 100);
 progressBar->setValue(0);
 progressBar->setGeometry(10, 10, 180, 30);
 
 // Create a horizontal slider
 // with the range between 0 and 100, and a starting value of 0
 QSlider *slider = new QSlider(&window);
 slider->setOrientation(Qt::Horizontal);
 slider->setRange(0, 100);
 slider->setValue(0);
 slider->setGeometry(10, 40, 180, 30);
 
 // Connection
 // This connection set the value of the progress bar
 // while the slider's value changes
 QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int))); */
 
 return app.exec();
}
