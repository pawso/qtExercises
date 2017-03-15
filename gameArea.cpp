#include "gameArea.hpp"
#include "gameManager.hpp"
#include <QApplication>
#include <iostream>

GameField::GameField(QWidget *parent) : QWidget(parent)
{
    m_mainWidth = parent->width() ;
    m_mainHeight = parent->height();

    m_spacer = 10;

    m_fieldWidth = (m_mainWidth - 4 * m_spacer) / 3;
    m_fieldHeight = (m_mainHeight - 100 - 4 * m_spacer) / 3;

    createAndAttachMainField(parent);
    createAndAttachFields(parent);
    createAndAttachControlButton(parent);

    GameManager *gm = new GameManager(parent);
    QObject::connect(this, SIGNAL (roundFinished(int, int)), gm, SLOT (roundFinished(int, int)));

    m_playerIdx = 1;
    m_prevField = NULL;
}

GameField::~GameField()
{
}

void
GameField::createAndAttachMainField(QWidget *parent)
{
    QLabel *background = new QLabel(parent);
    
    background->setStyleSheet("QLabel { background-color : white; }");
    background->resize(m_mainWidth, m_mainHeight);
}

void
GameField::createAndAttachFields(QWidget *parent)
{
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Field *f = new Field(parent, m_spacer, m_fieldWidth, m_fieldHeight, i, j, k++);
            QObject::connect(f, SIGNAL (playerChanged(int)), this, SLOT (changedButtonIdx(int)));
        }
    }
}

void
GameField::createAndAttachControlButton(QWidget *parent)
{
    QPushButton *button = new QPushButton(parent);
    button->resize(60, 30);
    button->move(300, 550);
    button->setText("Player 1");
    button->update();

    QObject::connect(button, SIGNAL (clicked()), this, SLOT (handleChangePlayerButton()));
}

void
GameField::changedButtonIdx(int idx)
{
    std::cout << "Idx is" << idx << std::endl;
    Field *caller = qobject_cast<Field *>(sender());
    if (!caller)
        return;

    if (m_prevField)
        m_prevField->reset();
    m_prevField = caller;

    m_selectedField = idx;
}

void
GameField::handleChangePlayerButton(void)
{
    emit roundFinished(m_playerIdx, m_selectedField);

    QPushButton *caller = qobject_cast<QPushButton *>(sender());
    if (!caller)
        return;

    if (m_playerIdx == 1) {
        m_playerIdx = 2;
        caller->setText("Player 2");
    } else {
        m_playerIdx = 1;
        caller->setText("Player 1");
    }

    m_prevField = NULL;
    Field::changePlayer(m_playerIdx);
}


