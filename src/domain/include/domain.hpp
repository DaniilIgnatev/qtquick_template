#pragma once

#include <QObject>
#include <QString>

// JoystickViewModel: Reference implementation for interactive demo
class JoystickViewModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal labelX READ labelX WRITE setLabelX NOTIFY labelXChanged)
    Q_PROPERTY(qreal labelY READ labelY WRITE setLabelY NOTIFY labelYChanged)
    Q_PROPERTY(QString labelText READ labelText CONSTANT)
   public:
    explicit JoystickViewModel(QObject* parent = nullptr);

    qreal labelX() const;
    void setLabelX(qreal x);

    qreal labelY() const;
    void setLabelY(qreal y);

    QString labelText() const;

    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void centerLabel();

   signals:
    void labelXChanged();
    void labelYChanged();

   private:
    static constexpr qreal MOVE_STEP = 20.0;
    qreal m_labelX;
    qreal m_labelY;
    QString m_labelText;
};