#ifndef CLNT_GPRH_GRAPHICSSCENE_HPP
#define CLNT_GPRH_GRAPHICSSCENE_HPP
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsSceneMouseEvent>

class MyGraphicsScene : public QGraphicsScene
{
public:
  MyGraphicsScene();

public slots:
  void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  QPointF	_pos;
public:
  const QPointF &getPos() const;

public:
};

#endif /* !CLNT_GPRH_GRAPHICSSCENE_HPP_ */
