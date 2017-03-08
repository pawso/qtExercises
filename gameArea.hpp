#ifndef _GAME_AREA_HPP_
#define _GAME_AREA_HPP_

#include <QWidget>
#include <QLabel>

class GameField : public QWidget
{
    Q_OBJECT
    public:
        explicit GameField(QWidget *parent = 0);
        ~GameField();

        void changedButtonIdx(int idx);

    signals:
    public slots:

    private:
        void createAndAttachMainField(QWidget *parent);
        void createAndAttachFields(QWidget *parent);

        unsigned m_fieldWidth;
        unsigned m_fieldHeight;

        unsigned m_spacer;

        unsigned m_mainWidth;
        unsigned m_mainHeight;
};

#endif /* _GAME_AREA_HPP_ */
