#ifndef _FIELD_HPP_
#define _FIELD_HPP_

#include "gameArea.hpp"

#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QColor>
#include <QPixmap>

#include <vector>

class Field : public QWidget
{
    Q_OBJECT
    public:
        Field(QWidget *parent = 0, int spacing = 0, int fieldWidth = 0, int fieldHeight = 0, int row = 0, int col = 0, int idx = 0);
        ~Field(void);

        static void changePlayer(int playerNum);
        void reset(void);


    public slots:
        void changeVal();

    signals:
        void playerChanged(int idx);

    private:
        void prepareFieldImages(void);

        QPushButton *m_button;
        std::vector<QPixmap> m_buttonGraphics;
        static int m_currentGraph;
        int m_fieldIdx;
        int m_wasClicked;
};

#endif
