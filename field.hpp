#ifndef _FIELD_HPP_
#define _FIELD_HPP_

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
        Field(QWidget *parent = 0, int spacing = 0, int fieldWidth = 0, int fieldHeight = 0, int row = 0, int col = 0);
        ~Field(void);

    public slots:
        void changeVal();

    private:
        void PrepareFieldImages(void);

        int m_currentGraph;
        QPushButton *m_button;

        std::vector<QPixmap> m_buttonGraphics;
};

#endif
