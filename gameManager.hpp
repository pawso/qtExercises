#include <QWidget>
#include <QObject>
#include <vector>

class GameManager : public QObject
{
    Q_OBJECT
    public:
        explicit GameManager(QWidget *parent = 0);

    public slots:
        void roundFinished(int playerIdx, int fieldIdx);


    private:
        std::vector<unsigned> m_fields;
        bool checkState(void);
};
