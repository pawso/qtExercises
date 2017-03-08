#include "field.hpp"
#include <iostream>

int Field::m_currentGraph = 1;
GameField *Field::m_gameField = NULL;

void Field::changePlayer(int playerNum)
{
    m_currentGraph = playerNum % 2;
}

Field::Field(QWidget *parent, int spacing, int fieldWidth, int fieldHeight, int row, int col, int idx)
{
    m_button = new QPushButton(parent);
    m_button->resize(fieldWidth, fieldHeight);
    m_button->move(spacing + col * (fieldWidth + spacing), spacing + row * (fieldHeight + spacing));
    QPalette pal = m_button->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    m_button->setAutoFillBackground(true);
    m_button->setPalette(pal);
    m_button->update();
    QObject::connect(m_button, SIGNAL (clicked()), this, SLOT (changeVal()));

    m_gameField = static_cast<GameField*>(parent);
    m_fieldIdx = idx;

    prepareFieldImages();
}

Field::~Field(void)
{
}

void Field::changeVal(void)
{
    if (m_wasClicked)
        return;

    m_button->setIcon(m_buttonGraphics[m_currentGraph]);
    m_button->setIconSize(QSize(100, 100));

    m_gameField->changedButtonIdx(m_fieldIdx);

    m_wasClicked = true;
}

void
Field::prepareFieldImages(void)
{
    m_buttonGraphics.resize(2);

    QPixmap pixmap;
    pixmap.load("./krzysztof.png");
    m_buttonGraphics[0] = pixmap;
    pixmap.load("./maryla.jpg");
    m_buttonGraphics[1] = pixmap;
}

