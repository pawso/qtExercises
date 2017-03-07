#include "field.hpp"
#include <iostream>

Field::Field(QWidget *parent, int spacing, int fieldWidth, int fieldHeight, int row, int col)
{
    QPushButton *m_button = new QPushButton(parent);
    m_button->resize(fieldWidth, fieldHeight);
    m_button->move(spacing + col * (fieldWidth + spacing), spacing + row * (fieldHeight + spacing));
    QPalette pal = m_button->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    m_button->setAutoFillBackground(true);
    m_button->setPalette(pal);
    m_button->update();
    QObject::connect(m_button, SIGNAL (clicked()), this, SLOT (changeVal()));

    PrepareFieldImages();
    m_currentGraph = 0;
}

Field::~Field(void)
{
}

void Field::changeVal(void)
{
    QPushButton *caller = qobject_cast<QPushButton *>(sender());
    if (!caller)
        return;

    caller->setIcon(m_buttonGraphics[m_currentGraph % 3]);
    caller->setIconSize(QSize(100, 100));
    m_currentGraph++;
}

void
Field::PrepareFieldImages(void)
{
    m_buttonGraphics.resize(3);

    QPixmap pixmap;
    m_buttonGraphics[0] = pixmap;
    pixmap.load("./krzysztof.png");
    m_buttonGraphics[1] = pixmap;
    pixmap.load("./maryla.jpg");
    m_buttonGraphics[2] = pixmap;
}
